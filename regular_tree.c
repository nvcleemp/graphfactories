/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2013 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 * 
 * This file requires the shared multicode files from the graphtools project
 * This program constructs regular trees with constant depth, i.e., trees 
 * where all the non-leaf vertices have the same degree and where all the leaves
 * are at the same distance from the center of the graph.
 */

#include <stdio.h>
#include <stdlib.h>
#include"shared/multicode_base.h"
#include"shared/multicode_output.h"

int getOrder(int internalDegree, int depth){
    int i;
    
    int power = 1;
    
    for(i=0; i<depth; i++){
        power *= internalDegree - 1;
    }
    
    return (internalDegree*power - 2)/(internalDegree - 2);
}

void constructGraph(int internalDegree, int depth){
    int i, j, k;
    int minLeaf, maxLeaf;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, getOrder(internalDegree, depth));
    
    if(depth==0){
        writeMultiCode(graph, adj, stdout);
        return;
    }
    
    for(i = 0; i < internalDegree; i++){
        addEdge(graph, adj, 1, 2 + i);
    }
    
    minLeaf = 2;
    maxLeaf = 1 + internalDegree;
    
    for(i = 1; i < depth; i++){
        int newLeaf = maxLeaf + 1;
        for(j = minLeaf; j <= maxLeaf; j++){
            for(k = 0; k < internalDegree - 1; k++){
                addEdge(graph, adj, j, newLeaf);
                newLeaf++;
            }
        }
        minLeaf = maxLeaf + 1;
        maxLeaf = newLeaf - 1;
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==3) {
        int internalDegree = atoi(argv[1]);
        int depth = atoi(argv[2]);
        constructGraph(internalDegree, depth);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s degree depth\n",argv[0]);
        return EXIT_FAILURE;
    }
}

