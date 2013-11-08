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

#define H(i) (4*(i)+1)
#define U(i) (4*(i)+2)
#define V(i) (4*(i)+3)
#define W(i) (4*(i)+4)

/*
 * Constructs the flower snark J(t) for given t.
 * The graph is output in multi_code format.
 */
void constructGraph(int t){
    int i;
    
    GRAPH graph;
    ADJACENCY adj;
    
    prepareGraph(graph, adj, 4*t);
    
    for(i = 0; i < t; i++){
        addEdge(graph, adj, H(i), U(i));
        addEdge(graph, adj, H(i), V(i));
        addEdge(graph, adj, H(i), W(i));
    }
    for(i = 0; i < t - 1; i++){
        addEdge(graph, adj, U(i), U(i+1));
        addEdge(graph, adj, V(i), V(i+1));
        addEdge(graph, adj, W(i), W(i+1));
    }
    addEdge(graph, adj, U(t-1), V(0));
    addEdge(graph, adj, V(t-1), U(0));
    addEdge(graph, adj, W(t-1), W(0));
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==2) {
        int t = atoi(argv[1]);
        if(t<3){
            fprintf(stderr,"A flower snark only exists for t>2\n");
            return EXIT_FAILURE;
        }
        if(t%2==0){
            fprintf(stderr,"This construction only yields snarks for odd t.\n");
            return EXIT_FAILURE;
        }
        constructGraph(t);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s t\n",argv[0]);
        return EXIT_FAILURE;
    }
}

