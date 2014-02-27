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
 * Constructs the hypercube of given dimension.
 * The graph is output in multi_code format.
 */
void constructGraph(int d) {
    int i, j;

    GRAPH graph;
    ADJACENCY adj;

    int n = 1 << d;

    prepareGraph(graph, adj, n);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < d; j++) {
            if (!(i & (1 << j))) {
                addEdge(graph, adj, i + 1, i + (1 << j) + 1);
            }
        }
    }

    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc == 2) {
        int dimension = atoi(argv[1]);
        constructGraph(dimension);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr, "%s d\n", argv[0]);
        return EXIT_FAILURE;
    }
}

