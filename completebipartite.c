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
 * Constructs the complete bipartite graph with the specified 
 * partition sizes.
 * The graph is output in multi_code format.
 */
void constructGraph(int order1, int order2){
    int i, j;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, order1 + order2);
    
    for(i = 1; i <= order1; i++){
        for(j = order1 + 1; j <= order1 + order2; j++){
            addEdge(graph, adj, i, j);
        }
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==3) {
        int order1 = atoi(argv[1]);
        int order2 = atoi(argv[2]);
        constructGraph(order1, order2);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s n m\n",argv[0]);
        return EXIT_FAILURE;
    }
}

