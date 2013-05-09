/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2013 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Constructs the complete bipartite graph with the specified 
 * partition sizes.
 * The graph is output in multi_code format.
 */
int main(int argc, char** argv) {

    if (argc!=3) {
        fprintf(stderr,"%s n m\n",argv[0]);
        return EXIT_FAILURE;
    }
    
    int order1 = atoi(argv[1]);
    int order2 = atoi(argv[2]);
    
    fprintf(stdout, ">>multi_code<<");
    
    fprintf(stdout, "%c", (unsigned char) order1 + order2);
    
    int i, j;
    for (i = 1; i <= order1; i++) {
        for (j = order1 + 1; j <= order1 + order2; j++) {
            fprintf(stdout, "%c", (unsigned char) j);
        }
        fprintf(stdout, "%c", (unsigned char) 0);
    }
    for (i = order1+1; i < order1 + order2; i++) {
        fprintf(stdout, "%c", (unsigned char) 0);
    }
    
    return (EXIT_SUCCESS);
}

