/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2013 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 * 
 * This file requires the shared multicode files from the graphtools project
 */

#include <stdio.h>
#include <stdlib.h>
#include"shared/multicode_base.h"
#include"shared/multicode_output.h"

void constructGraph(int maxDegree, int subdivisions){
    int i, j;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, 1 + maxDegree*(subdivisions + 1));
    
    for(i = 0; i < maxDegree; i++){
        addEdge(graph, adj, 1, 2 + i);
        for(j = 0; j < subdivisions; j++){
            addEdge(graph, adj, 2 + i + j*maxDegree, 2 + i + (j+1)*maxDegree);
        }
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==2) {
        int maxDegree = atoi(argv[1]);
        constructGraph(maxDegree, 0);
        return (EXIT_SUCCESS);
    } else if (argc==3) {
        int maxDegree = atoi(argv[1]);
        int subdivisions = atoi(argv[2]);
        constructGraph(maxDegree, subdivisions);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s D [s]\n",argv[0]);
        return EXIT_FAILURE;
    }
}

