/*
* Dinesh P. Weerapurage 
* Department of Electrical Engineering and Computer Science
* University of Tennessee - Knoxville
* 203 Claxton Complex, 1122 Volunteer Boulevard
* Knoxville, TN 37996-3450 USA 
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bitop.h>
#include <graph.h>
#include <gen.h>

int main (int argc, char *argv[])
{
    gen_t *g;
    if (argc < 5)
    {
        fprintf (stderr, "usage: ./gen <number_of_nodes> <edge_density> <number_of_files> <prefix_for_file_name> \n");
        exit (0);
    }
    g = gen_create (argv[4], atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    gen_graph(g);
    return 0;
}

