/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2014 Nico Van Cleemput.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include"shared/multicode_base.h"
#include"shared/multicode_output.h"

/*
 * Constructs the linear forest with the specified components.
 * The graph is output in multi_code format.
 */
void constructGraph(int order, int largestComponent, int componentCounts[]){
    int i, j, k, currentVertex;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, order);
    
    currentVertex = 1;
    for(i = 1; i <= largestComponent; i++){
        for(j = 0; j < componentCounts[i]; j++){
            for(k = 1; k < i; k++){
                addEdge(graph, adj, currentVertex, currentVertex+1);
                currentVertex++;
            }
            currentVertex++;
        }
    }
    
    writeMultiCode(graph, adj, stdout);
}

//====================== USAGE =======================

void help(char *name) {
    fprintf(stderr, "The program %s constructs a linear forest with the specified \ncomponents.\n\n", name);
    fprintf(stderr, "Usage\n=====\n");
    fprintf(stderr, " %s [options] s1[:n1] s2[:n2] ...\n\n", name);
    fprintf(stderr, "where si is the number of vertices in a component and ni is the number of \ncomponents.\n");
    fprintf(stderr, "\nThis program can handle graphs up to %d vertices. Recompile if you need larger\n", MAXN);
    fprintf(stderr, "graphs.\n\n");
    fprintf(stderr, "Valid options\n=============\n");
    fprintf(stderr, "    -h, --help\n");
    fprintf(stderr, "       Print this help and return.\n");
}

void usage(char *name) {
    fprintf(stderr, "Usage: %s [options] s1[:n1] s2[:n2] ...\n", name);
    fprintf(stderr, "For more information type: %s -h \n\n", name);
}

int main(int argc, char** argv) {

    int i;
    
    /*=========== commandline parsing ===========*/

    int c;
    char *name = argv[0];
    static struct option long_options[] = {
        {"help", no_argument, NULL, 'h'}
    };
    int option_index = 0;

    while ((c = getopt_long(argc, argv, "h", long_options, &option_index)) != -1) {
        switch (c) {
            case 'h':
                help(name);
                return EXIT_SUCCESS;
            case '?':
                usage(name);
                return EXIT_FAILURE;
            default:
                fprintf(stderr, "Illegal option %c.\n", c);
                usage(name);
                return EXIT_FAILURE;
        }
    }
    
    int parameterCount = argc - optind;
    
    int componentSize[parameterCount], componentCount[parameterCount];
    int totalVertexCount = 0, largestComponent = 0;
    
    for (i = 0; i < parameterCount; i++){
        if(strchr(argv[optind+i], ':')){
            if(sscanf(argv[optind+i], "%d:%d", componentSize+i, componentCount+i)!=2){
                fprintf(stderr, "Error while reading arguments -- exiting!\n");
                return EXIT_FAILURE;
            }
        } else {
            componentSize[i] = atoi(argv[optind+i]);
            componentCount[i] = 1;
        }
        totalVertexCount += componentSize[i] * componentCount[i];
        if(componentSize[i] > largestComponent){
            largestComponent = componentSize[i];
        }
    }
    
    int linearForestComponentCount[largestComponent+1];
    
    for(i = 0; i <= largestComponent; i++){
        linearForestComponentCount[i] = 0;
    }
    
    for (i = 0; i < parameterCount; i++){
        if(componentSize[i] > 0 && componentCount[i] > 0){
            linearForestComponentCount[componentSize[i]] += componentCount[i];
        }
    }

    fprintf(stderr, "Constructing linear forest with following composition:\n");
    for(i = 0; i <= largestComponent; i++){
        if(linearForestComponentCount[i]){
            fprintf(stderr, "   %d component%s with %d %s\n",
                    linearForestComponentCount[i],
                    linearForestComponentCount[i] == 1 ? "" : "s",
                    i, i == 1 ? "vertex" : "vertices");
        }
    }
    
    constructGraph(totalVertexCount, largestComponent, linearForestComponentCount);
    
    return EXIT_SUCCESS;
}

