/*
* Dinesh P. Weerapurage 
* Department of Electrical Engineering and Computer Science
* University of Tennessee - Knoxville
* 203 Claxton Complex, 1122 Volunteer Boulevard
* Knoxville, TN 37996-3450 USA 
*
*/

#ifndef __GEN_H__
#define __GEN_H__

#include <graph.h>
#include <pthread.h>

#define MAXT 20

typedef struct _gen {
    graph_t *g;
    int nodes;
    int edges;
    int density;
    int n;
    int i;
    pthread_mutex_t *lock;
    pthread_t **pt;
    const char *fname;
}gen_t;

gen_t *
gen_create (const char *filename, int k, int density, int n);

void 
gen_free (gen_t *gen);


void
gen_graph (gen_t *gen);

void
gen_gprint (gen_t *gen);

void
gen_genprint (gen_t *gen);


#endif  /* __GEN_H__ */
