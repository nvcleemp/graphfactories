/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2014 Nico Van Cleemput.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Constructs the double wheel graph with the specified number of equator vertices.
 * The graph is output in planar_code format.
 */
int main(int argc, char** argv) {

    if (argc!=2) {
        fprintf(stderr,"%s n\n",argv[0]);
        return EXIT_FAILURE;
    }
    
    int equatorVertices = atoi(argv[1]);

    if (equatorVertices < 3) {
        fprintf(stderr,"Number of equator vertices should at least be 3.\n");
        return EXIT_FAILURE;
    }
    
    fprintf(stdout, ">>planar_code<<");
    
    //the order of the graph
    fprintf(stdout, "%c", (unsigned char) (equatorVertices + 2));
    
    int i;
    //the neighbourhood of the poles
    for (i = 0; i < equatorVertices; i++) {
        fprintf(stdout, "%c", (unsigned char) (i + 3));
    }
    fprintf(stdout, "%c", (unsigned char) 0);
    for (i = equatorVertices - 1; i >= 0; i--) {
        fprintf(stdout, "%c", (unsigned char) (i + 3));
    }
    fprintf(stdout, "%c", (unsigned char) 0);
    
    //the neighbourhood of the equator vertices
    fprintf(stdout, "%c", (unsigned char) 1);
    fprintf(stdout, "%c", (unsigned char) (equatorVertices + 2));
    fprintf(stdout, "%c", (unsigned char) 2);
    fprintf(stdout, "%c", (unsigned char) 4);
    fprintf(stdout, "%c", (unsigned char) 0);
    for (i = 4; i < equatorVertices + 2; i++) {
        fprintf(stdout, "%c", (unsigned char) 1);
        fprintf(stdout, "%c", (unsigned char) (i - 1));
        fprintf(stdout, "%c", (unsigned char) 2);
        fprintf(stdout, "%c", (unsigned char) (i + 1));
        fprintf(stdout, "%c", (unsigned char) 0);
    }
    fprintf(stdout, "%c", (unsigned char) 1);
    fprintf(stdout, "%c", (unsigned char) equatorVertices+1);
    fprintf(stdout, "%c", (unsigned char) 2);
    fprintf(stdout, "%c", (unsigned char) 3);
    fprintf(stdout, "%c", (unsigned char) 0);
    
    return (EXIT_SUCCESS);
}

