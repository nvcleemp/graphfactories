/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2013 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Constructs the cycle graph with the specified number of vertices.
 * The graph is output in planar_code format.
 */
int main(int argc, char** argv) {

    if (argc!=2) {
        fprintf(stderr,"%s n\n",argv[0]);
        return EXIT_FAILURE;
    }
    
    int order = atoi(argv[1]);
    
    fprintf(stdout, ">>planar_code<<");
    
    fprintf(stdout, "%c", (unsigned char) order);
    
    fprintf(stdout, "%c", (unsigned char) order);
    fprintf(stdout, "%c", (unsigned char) 2);
    fprintf(stdout, "%c", (unsigned char) 0);
    int i;
    for (i = 2; i < order; i++) {
        fprintf(stdout, "%c", (unsigned char) (i - 1));
        fprintf(stdout, "%c", (unsigned char) (i + 1));
        fprintf(stdout, "%c", (unsigned char) 0);
    }
    fprintf(stdout, "%c", (unsigned char) order - 1);
    fprintf(stdout, "%c", (unsigned char) 1);
    fprintf(stdout, "%c", (unsigned char) 0);
    
    return (EXIT_SUCCESS);
}

