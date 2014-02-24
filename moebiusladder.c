/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2014 Nico Van Cleemput.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include"shared/multicode_base.h"
#include"shared/multicode_output.h"

/*
 * Constructs the moebius ladders.
 * The graph is output in multi_code format.
 */
void constructGraph(int n){
    int i;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, 2*n);
    
    for(i = 1; i < n; i++){
        addEdge(graph, adj, i, i + 1);
        addEdge(graph, adj, i, i + n);
        addEdge(graph, adj, i+n, i + 1 + n);
    }
    addEdge(graph, adj, n, n + 1);
    addEdge(graph, adj, n, 2*n);
    addEdge(graph, adj, 2*n, 1);
    
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

