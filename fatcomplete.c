/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2013 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include"shared/multicode_base.h"
#include"shared/multicode_output.h"

/*
 * Constructs a fat K_n with the specified number of vertices and edge 
 * multiplicity. The graph is output in multi_code format.
 */
void constructGraph(int vertices, int edgeMultiplicity){
    int i, j, k;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, vertices);
    
    for(i = 1; i < vertices; i++){
        for(j = i+1; j <= vertices; j++){
            for(k = 0; k < edgeMultiplicity; k++){
                addEdge(graph, adj, i, j);
            }
        }
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==3) {
        int vertices = atoi(argv[1]);
        int edgeMultiplicity = atoi(argv[2]);
        constructGraph(vertices, edgeMultiplicity);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s n\n",argv[0]);
        return EXIT_FAILURE;
    }
}

