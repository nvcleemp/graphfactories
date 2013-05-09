/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2013 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Constructs the path graph with the specified number of vertices.
 * The graph is output in multi_code format.
 */
int main(int argc, char** argv) {

    if (argc!=2) {
        fprintf(stderr,"%s n\n",argv[0]);
        return EXIT_FAILURE;
    }
    
    int order = atoi(argv[1]);
    
    fprintf(stdout, ">>multi_code<<");
    
    fprintf(stdout, "%c", (unsigned char) order);
    
    int i;
    for (i = 1; i < order; i++) {
        fprintf(stdout, "%c", (unsigned char) (i + 1));
        fprintf(stdout, "%c", (unsigned char) 0);
    }
    
    return (EXIT_SUCCESS);
}

