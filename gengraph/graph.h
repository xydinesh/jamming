/*
* Dinesh P. Weerapurage 
* Department of Electrical Engineering and Computer Science
* University of Tennessee - Knoxville
* 203 Claxton Complex, 1122 Volunteer Boulevard
* Knoxville, TN 37996-3450 USA 
*
*/

#ifndef __KURUTU_GRAPH_H__
#define __KURUTU_GRAPH_H__

typedef struct _kurutu_graph_t {
    int nodes;
    int edges;
    int nsize;
    unsigned long *barray;
}graph_t;


typedef struct _kurutu_neighbors_t {
    int size;
    int id;
    int *nbrs;
}nbrs_t;


/* _FLINE_ is for print line number */
#define _FLINE_ fprintf(stderr, "%s %2d\n", __FILE__, __LINE__)

/* bzero */
#define bzero(a,b) memset((void *)a, 0, b)

/* creates graph structure */
graph_t *
graph_create (int nodes, int edges);


/* creates graph structure from a file*/
graph_t *
graph_create_file (const char *file);


/* adds a new edge to graph */
void
graph_add_edge (graph_t *g, int a, int b);


/* check whether egde exsists, return 1 if exsists , else return 0 */
int
graph_is_edge (graph_t *g, int a, int b);


/* returns degress of a node */
int 
graph_node_degree (graph_t *g, int a);


/* returns neighbors list, nbrs_t */
nbrs_t *
graph_node_nbrs (graph_t *g, int node);

void 
print_graph (graph_t *g);

/* free graph structure */
void
graph_free (graph_t *g); 

void
graph_reset (graph_t *g);

void
graph_complement (graph_t *g);

#endif  /* __KURUTU_GRAPH_H__ */
