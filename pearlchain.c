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
 * Constructs the pearl chain with the specified number of vertices.
 * The graph is output in multi_code format.
 */
void constructGraph(int order){
    int i;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, order);
    
    for(i = 1; i <= order; i++){
        addEdge(graph, adj, i, (i%order)+1);
        if(i%2){
            addEdge(graph, adj, i, (i%order)+1);
        }
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==2) {
        int order = atoi(argv[1]);
        if(order%2){
            fprintf(stderr,"A pearl chain only exists for even orders.\n");
            return EXIT_FAILURE;
        }
        constructGraph(order);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s n\n",argv[0]);
        return EXIT_FAILURE;
    }
}

