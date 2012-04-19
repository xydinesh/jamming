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


graph_t *
graph_create (int nodes, int edges)
{
    unsigned long i = 0;
    unsigned long  bie = 0;
    unsigned long nsize = 0;
    graph_t *g = NULL;

    i = (unsigned long) nodes*(nodes-1)/2;
    bie = (unsigned long) U_CHAR_L * BITS_IN_BYTE;
    while ((i % bie) != 0) i++;
    nsize = i/bie;
    g = (graph_t *) malloc (sizeof (graph_t));
    if (!g)
    {
        fprintf (stderr, "no enough memory %s %d", __FILE__, __LINE__);
        exit (0);
    }
    bzero (g, sizeof(graph_t));

    g->barray = (unsigned long *) malloc (sizeof (unsigned long) * nsize);
    if (!g->barray)
    {
        fprintf (stderr, "no enough memory %s %d", __FILE__, __LINE__);
        free (g);
        exit (0);
    }
    bzero(g->barray, sizeof(unsigned long) * nsize);

    g->nodes = nodes;
    g->edges = edges;
    g->nsize = nsize;
    return g;
}


/* adds a new edge to graph */
void
graph_add_edge (graph_t *g, int a, int b)
{
    int aa, bb;
    unsigned long pos = 0;

    aa = a%g->nodes;
    bb = b%g->nodes;
    pos = (unsigned long)BITPOS(aa,bb,g->nodes);
    BitTrue(g->barray,pos);
}



/* returns degress of a node */
int 
graph_node_degree (graph_t *g, int a)
{
    int i, n;
    unsigned int aa, bb;
    unsigned long pos;

    n = 0;
    for (i = 0; i < g->nodes; i++)
    {
        aa = (unsigned int)a;
        bb = (unsigned int)i;
        pos = 0;
        pos = (unsigned long)BITPOS(aa,bb,g->nodes); 
        if (BitValue(g->barray,pos) && (a != i))
        {
            n++;
        }
    }
    return n;
}


nbrs_t *
graph_node_nbrs (graph_t *g, int node)
{
    unsigned int aa, bb;
    int i, j;
    unsigned long pos;
    int nodes;
    int nsize;
    nbrs_t *nb;

    nsize = graph_node_degree (g, node);

    nb = (nbrs_t *) malloc (sizeof (nbrs_t));
    if (!nb)
    {
        fprintf (stderr, "no enough memory abort\n");
        _FLINE_;
        exit (0);
    }
    nb->size = nsize;
    nb->id = node;

    nb->nbrs = (int *) malloc (sizeof(int) * nsize);
    if (!nb->nbrs)
    {
        fprintf (stderr, "no enough memory abort %s %d\n", __FILE__, __LINE__);
        exit (0);
    }
    bzero(nb->nbrs, sizeof(int)*nsize);

    if (!nsize)
    {
        return nb;
    }

    nodes = g->nodes;
    j = 0;
    for (i = 0; ((i < nodes) && (nsize)); i++)
    {
        aa = (unsigned int)i;
        bb = (unsigned int)node;
        pos = (unsigned long)BITPOS(aa,bb,nodes);
        if ((node != i) && (BitIsTrue(g->barray,pos)))
        {
            nb->nbrs[j++] = i;
            nsize --;
        }
    }
    return nb;
}


/* creates graph structure from a file*/
graph_t *
graph_create_file (const char *filename)
{
    int i, j, c;
    FILE *file;
    graph_t *g;

    if (!filename)
    {
        fprintf (stderr, "file name is null \n");
        _FLINE_;
        exit (0);
    }

    file = fopen (filename, "r");
    if (!file)
    {
        fprintf (stderr, "file %s can not open\n", filename);
        _FLINE_;
        exit (0);
    }

    c = fscanf (file, "%d %d", &i, &j);
    if (!(i > 0 && j > 0))
    {
        fprintf (stderr, "Node number and Edge number should be positive \n");
        _FLINE_;
        exit (0);
    }
    g = graph_create (i, j);
    if (!g)
    {
        fprintf (stderr, "graph creation failed for nodes %2d and edges %2d \n", i, j);
        _FLINE_;
        exit (0);
    }

    c = fscanf (file, "%d %d", &i, &j);
    while (c != EOF)
    {
        if ((i < 0 || j < 0))
        {
            fprintf (stderr, "Nodes should be positive \n");
            _FLINE_;
            exit (0);
        }
        graph_add_edge (g, i, j);
        c = fscanf (file, "%d %d", &i, &j);
    }

    (void)fclose (file);
    return g;
}


void 
print_graph (graph_t *g)
{
    int n;
    int i;
    unsigned long pos;
    int j = 0;

    n = g->nodes;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j > i)
            {
                pos = (unsigned long)BITPOS(i,j,g->nodes);
                if (BitValue(g->barray, pos))
                {
                    printf ("e %2d %2d\n", i, j);
                }
            }
        }
    }
}


int
graph_is_edge (graph_t *g, int a, int b)
{
    int aa, bb;
    unsigned long pos;

    aa = a;
    bb = b;
    if (a == b)
    {
        return 0;
    }

    pos = (unsigned long)BITPOS(aa, bb, g->nodes);
    return (int)BitValue(g->barray, pos);
}


void
graph_free (graph_t *g)
{
    if (!g)
    {
        return;
    }

    if (g->barray)
    {
        free (g->barray);
        g->barray = NULL;
    }

    free (g);
    g = NULL;
}


void
graph_reset (graph_t *g)
{
    int i;
    for (i = 0; i < g->nsize; i++)
    {
        g->barray[i] &= 0;
    }
}


void
graph_complement (graph_t *g)
{
    int i;
    for (i = 0; i < g->nsize; i++)
    {
        g->barray[i] = ~ g->barray[i];
    }
}
