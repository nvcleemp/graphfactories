/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2013 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Constructs the wheel graph with the specified number of spokes.
 * The graph is output in planar_code format.
 */
int main(int argc, char** argv) {

    if (argc!=2) {
        fprintf(stderr,"%s n\n",argv[0]);
        return EXIT_FAILURE;
    }
    
    int spokes = atoi(argv[1]);

    if (spokes < 3) {
        fprintf(stderr,"Number of spokes should at least be 3.\n");
        return EXIT_FAILURE;
    }
    
    fprintf(stdout, ">>planar_code<<");
    
    //the order of the graph
    fprintf(stdout, "%c", (unsigned char) (spokes + 1));
    
    int i;
    //the neighbourhood of the hub
    for (i = 0; i < spokes; i++) {
        fprintf(stdout, "%c", (unsigned char) (i + 2));
    }
    fprintf(stdout, "%c", (unsigned char) 0);
    
    //the neighbourhood of the rim vertices
    fprintf(stdout, "%c", (unsigned char) 1);
    fprintf(stdout, "%c", (unsigned char) (spokes + 1));
    fprintf(stdout, "%c", (unsigned char) 3);
    fprintf(stdout, "%c", (unsigned char) 0);
    for (i = 3; i < spokes + 1; i++) {
        fprintf(stdout, "%c", (unsigned char) 1);
        fprintf(stdout, "%c", (unsigned char) (i - 1));
        fprintf(stdout, "%c", (unsigned char) (i + 1));
        fprintf(stdout, "%c", (unsigned char) 0);
    }
    fprintf(stdout, "%c", (unsigned char) 1);
    fprintf(stdout, "%c", (unsigned char) spokes);
    fprintf(stdout, "%c", (unsigned char) 2);
    fprintf(stdout, "%c", (unsigned char) 0);
    
    return (EXIT_SUCCESS);
}

