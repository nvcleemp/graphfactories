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
 * Constructs the path graph with the specified number of vertices.
 * The graph is output in multi_code format.
 */
void constructGraph(int order){
    int i;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, order);
    
    for(i = 1; i < order; i++){
        addEdge(graph, adj, i, i+1);
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==2) {
        int order = atoi(argv[1]);
        constructGraph(order);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s n\n",argv[0]);
        return EXIT_FAILURE;
    }
}

