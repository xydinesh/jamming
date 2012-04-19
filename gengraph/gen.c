/*
* Dinesh P. Weerapurage 
* Department of Electrical Engineering and Computer Science
* University of Tennessee - Knoxville
* 203 Claxton Complex, 1122 Volunteer Boulevard
* Knoxville, TN 37996-3450 USA 
* June-01-2009 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <graph.h>
#include <bitop.h> 
#include <gen.h>

static void *graph_fill_thread(void *x);
static unsigned long count = 0;

gen_t *
gen_create (const char *filename, int k, int density, int n)
{
    gen_t *gen;
    int i;

    gen = (gen_t *) malloc (sizeof(gen_t));
    if (!gen)
    {
        fprintf (stderr, "no enough memory \n");
        _FLINE_;
        exit (0);
    }

    if (!(k > 0))
    {
        fprintf (stderr, "number of nodes should be positive \n");
        _FLINE_;
        exit (0);
    }

    if (!(n > 0))
    {
        fprintf (stderr, "number of files should be positive \n");
        _FLINE_;
        exit (0);
    }


    if (!(density > 0) || (density > 100))
    {
        fprintf (stderr, "Enter value in the range 0 - 100 for density\n");
        _FLINE_;
        exit (0);
    }

    if (!filename)
    {
        fprintf (stderr, "Please give prefix for filename\n");
        _FLINE_;
        exit (0);
    }

    gen->fname = filename;
    gen->nodes = k;
    gen->edges = density*k*(k-1)/(200);
    gen->density = density;
    gen->n = n;
    gen->i = 0;
    gen->g = graph_create (gen->nodes, gen->edges);
    if (!gen->g)
    {
        fprintf (stderr, "graph creation failed\n");
        _FLINE_;
        exit (0);
    }

    gen->pt = (pthread_t **) malloc(sizeof(pthread_t *)*MAXT);
    if (!gen->pt)
    {
        fprintf (stderr, "thread array creation failed\n");
        _FLINE_;
        exit (0);
    }

    for (i = 0; i < MAXT; i++)
    {
        gen->pt[i] = (pthread_t *) malloc(sizeof(pthread_t));
        if (!gen->pt[i])
        {
            fprintf (stderr, "thread creation failed %d\n", i);
            _FLINE_;
            exit (0);
        }
    }

    gen->lock = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t));
    if (!gen->lock)
    {
        fprintf (stderr, "mutex creation failed\n");
        _FLINE_;
        exit (0);
    }
   
    if(pthread_mutex_init (gen->lock, NULL))
    {
        fprintf (stderr, "mutex init failed\n");
        _FLINE_;
        exit (0);
    }

    return gen;
}


void 
gen_free (gen_t *gen)
{

    if (!gen)
    {
        return;
    }

    if (gen->g)
    {
        graph_free (gen->g);
        gen->g = NULL;
    }

    free (gen);
}


void
gen_graph (gen_t *gen)
{
    graph_t *g;
    int i, j, l;
    char s[100];
    FILE *f;
    time_t t1, t2;

    printf ("\n\tStart File Generation\n\n");
    t1 = time (0);
    g = gen->g;
    for (l = 0; l < gen->n; l++)
    {
        graph_reset (g);
        gen->i = 0;

        sprintf (s, "%s_%d_%d-%d.dim", gen->fname, g->nodes, gen->density, l);
        for (i = 0; i < MAXT; i++)
        {
            if(pthread_create(gen->pt[i], NULL, graph_fill_thread, (void *)gen))
            {
                fprintf (stderr, "thread creation failed\n");
                _FLINE_;
                exit (0);
            }
        }

        for (i = 0; i < MAXT; i++)
        {
            pthread_join(*gen->pt[i], NULL);
        }

        f = fopen (s, "w");
        if (!f)
        {
            fprintf (stderr, "can not open file %s for write\n", s);
            _FLINE_;
            exit (0);
        }

        fprintf (f, "%d %d\n", g->nodes, g->edges);
        for (i = 0; i < g->nodes; i++)
        {
            for (j = 0; j < g->nodes; j++)
            {
                if (j > i)
                {
                    if (graph_is_edge (g, i, j))
                    {
                        fprintf (f, "%d %d\n", i, j);
                    }
                }

            }
        }
        fclose (f);
        t2 = time(0);
        printf ("\t%2d. %s\n", l+1, s);
    }
    printf ("\n\tFile Generation Finished\n\n");
    printf ("\tTotal time for file generation %2ld seconds\n\n",(long int)(t2-t1));

}

static void*
graph_fill_thread(void *x)
{
    int i,j;
    gen_t *gen;
    graph_t *g;
    gen = (gen_t *)x;
    g = gen->g;
    for (; gen->i < g->edges; )
    {
        srandom(time(0)- count++);
        i = (int)random ()%(g->nodes);
        srandom(time(0)-i);
        j = ((int)random ())%(g->nodes);
        pthread_mutex_lock (gen->lock);
        if (!(graph_is_edge (g, i, j)) && (i != j))
        {
            graph_add_edge (g, i, j); 
            gen->i++;
        }
        pthread_mutex_unlock (gen->lock);
    }
    return 0;
}
