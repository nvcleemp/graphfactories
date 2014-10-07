/*
 * Main developer: Nico Van Cleemput
 * 
 * Copyright (C) 2014 Ghent University.
 * Licensed under the GNU GPL, read the file LICENSE.txt for details.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Constructs the plane graph corresponding to the diminished trapezohedron
 * with the specified base.
 * The graph is output in planar_code format.
 */
int main(int argc, char** argv) {

    if (argc!=2) {
        fprintf(stderr,"%s n\n",argv[0]);
        return EXIT_FAILURE;
    }
    
    int base = atoi(argv[1]);

    if (base < 3) {
        fprintf(stderr,"Size of base should at least be 3.\n");
        return EXIT_FAILURE;
    }
    
    fprintf(stdout, ">>planar_code<<");
    
    //the order of the graph
    fprintf(stdout, "%c", (unsigned char) (2*base + 1));
    
    int i;
    //the neighbourhood of the hub
    for (i = 0; i < base; i++) {
        fprintf(stdout, "%c", (unsigned char) (i + 2));
    }
    fprintf(stdout, "%c", (unsigned char) 0);
    
    //the neighbourhood of the triangle tips
    for (i = base + 2; i < 2*base+1; i++) {
        fprintf(stdout, "%c", (unsigned char) 1);
        fprintf(stdout, "%c", (unsigned char) i);
        fprintf(stdout, "%c", (unsigned char) (i + 1));
        fprintf(stdout, "%c", (unsigned char) 0);
    }
    fprintf(stdout, "%c", (unsigned char) 1);
    fprintf(stdout, "%c", (unsigned char) (2*base + 1));
    fprintf(stdout, "%c", (unsigned char) (base + 2));
    fprintf(stdout, "%c", (unsigned char) 0);
    
    //the neighbourhood of the rim vertices
    fprintf(stdout, "%c", (unsigned char) 2);
    fprintf(stdout, "%c", (unsigned char) (base + 1));
    fprintf(stdout, "%c", (unsigned char) (2*base + 1));
    fprintf(stdout, "%c", (unsigned char) (base + 3));
    fprintf(stdout, "%c", (unsigned char) 0);
    for (i = 3; i < base+1; i++) {
        fprintf(stdout, "%c", (unsigned char) i);
        fprintf(stdout, "%c", (unsigned char) (i - 1));
        fprintf(stdout, "%c", (unsigned char) (base + i - 1));
        fprintf(stdout, "%c", (unsigned char) (base + i + 1));
        fprintf(stdout, "%c", (unsigned char) 0);
    }
    fprintf(stdout, "%c", (unsigned char) (base + 1));
    fprintf(stdout, "%c", (unsigned char) base);
    fprintf(stdout, "%c", (unsigned char) (2*base));
    fprintf(stdout, "%c", (unsigned char) (base + 2));
    fprintf(stdout, "%c", (unsigned char) 0);
    
    return (EXIT_SUCCESS);
}

