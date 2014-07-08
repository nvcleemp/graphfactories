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
 * Constructs independent set with the specified number of vertices.
 * The graph is output in multi_code format.
 */
void constructGraph(int order){
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, order);
    
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

