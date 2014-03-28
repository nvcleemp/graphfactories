/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2014 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include"shared/multicode_base.h"
#include"shared/multicode_output.h"

unsigned long long int sets[MAXN];
unsigned long long int setCount;

int choose(int n, int k){
    if(k == 0)
        return 1;
    return (n * choose(n - 1, k - 1)) / k;
}

void constructSets(unsigned long long int currentSet, int setSize, int position,
        int maxSize, int targetSize){
    if(setSize == targetSize){
        sets[setCount] = currentSet;
        setCount++;
        return;
    } else if(position == maxSize){
        return;
    }
    
    constructSets(currentSet, setSize, position+1, maxSize, targetSize);
    constructSets(currentSet | (1ULL << position), setSize+1, position+1,
            maxSize, targetSize);
}
/*
 * Constructs the kneser graph for the specified parameters.
 * The graph is output in multi_code format.
 */
void constructGraph(int n, int k){
    int i, j;
    
    GRAPH graph;
    ADJACENCY adj;
    
    int order = choose(n,k);
    
    if(order > MAXN){
        fprintf(stderr, "Order %d is too large for this program -- exiting!\n", order);
        exit(EXIT_FAILURE);
    }
    
    prepareGraph(graph, adj, order);
    
    constructSets(0ULL, 0, 0, n, k);
    
    for(i = 1; i < order; i++){
        for(j = i + 1; j <= order; j++){
            if(!(sets[i-1] & sets[j-1])){
                addEdge(graph, adj, i, j);
            }
        }
    }
    
    writeMultiCode(graph, adj, stdout);
}

int main(int argc, char** argv) {

    if (argc==3) {
        int n = atoi(argv[1]);
        int k = atoi(argv[2]);
        if(n > 64){
            fprintf(stderr, "Only n up to 64 supported -- exiting!\n");
            exit(EXIT_FAILURE);
        }
        if(n < 2*k){
            fprintf(stderr, "Not defined if n < 2k -- exiting!\n");
            exit(EXIT_FAILURE);
        }
        constructGraph(n, k);
        return (EXIT_SUCCESS);
    } else {
        fprintf(stderr,"%s n k\n",argv[0]);
        return EXIT_FAILURE;
    }
}

