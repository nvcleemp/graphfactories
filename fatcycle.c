/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2013 Nico Van Cleemput.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include"shared/multicode_base.h"
#include"shared/multicode_output.h"

/*
 * Constructs the fat cycle graph with the specified number of vertices and edge
 * multiplicity. The graph is output in multi_code format.
 */
void constructGraph(int order, int multiplicity){
    int i, j;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, order);
    
    for(i = 1; i <= order; i++){
        for(j = 0; j < multiplicity; j++){
            addEdge(graph, adj, i, (i%order)+1);
        }
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==3) {
        int order = atoi(argv[1]);
        int multiplicity = atoi(argv[2]);
        constructGraph(order, multiplicity);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s n m\n",argv[0]);
        return EXIT_FAILURE;
    }
}

