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
 * Constructs the generalized Petersengraph G(n,k).
 * The graph is output in multi_code format.
 */
void constructGraph(int n, int k){
    int i;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, 2*n);
    
    for(i = 1; i <= n; i++){
        addEdge(graph, adj, i, (i%n)+1);
        addEdge(graph, adj, i, i + n);
        addEdge(graph, adj, i+n, ((i-1+k)%n) + n + 1);
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==1) {
        constructGraph(5, 2);
        return (EXIT_SUCCESS);
    } else if (argc==3) {
        int n = atoi(argv[1]);
        int k = atoi(argv[2]);
        constructGraph(n, k);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s [n k]\n",argv[0]);
        return EXIT_FAILURE;
    }
}

