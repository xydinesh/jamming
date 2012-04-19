#include "llist.h"
#include <stdlib.h>
#include <stdio.h>

node_t *create_node (int i)
{
    node_t *t = (node_t *) malloc (sizeof(node_t));
    if (!t)
    {
        fprintf (stderr, "no enough memory\n");
        exit (-1);
    }

    t->data = i;
    t->next = NULL;
    return t;
}

void free_node (node_t *n)
{
    if (n)
    {
        free (n);
        n = NULL;
    }
    return;
}

slist_t *create_list ()
{
    slist_t *l = (slist_t *) malloc (sizeof(slist_t));
    if (!l)
    {
        fprintf (stderr, "no enough memory\n");
        exit (0);
    }
    l->head = NULL;

    return l;
}


void add_element (slist_t *list, int i)
{
    node_t *n = create_node (i);
    if (list->head)
    {
        n->next = list->head;
    }
    list->head = n;
}


node_t *find_element (slist_t *list, int i)
{
    node_t *n = list->head;
    while (n)
    {
        if (n->data == i)
        {
            return n;
        }
        n = n->next;
    }
    return NULL;
}


void print_list (slist_t *list)
{
    node_t *n = list->head;
    while (n)
    {
        printf ("%d ", n->data);
        n = n->next;
    }
    printf ("\n");
}

void delete_element (slist_t *list, int pos)
{
    node_t *n = list->head;
    node_t *prev = NULL;
    while ((pos > 0) && (n))
    {
        prev = n;
        n = n->next;
        pos--;
    }
    
    if (n)
    {
        if (n == list->head)
        {
            list->head = n->next;
            return;
        }

        if (n->next)
        {
            prev->next = n->next;
        }
    }

    free_node (n);
}


void insert_element (slist_t *list, int i, int pos)
{
    if (pos == 0)
    {
        add_element(list, i);
        return;
    }

    node_t *n = list->head;
    node_t *next = NULL;
    node_t *nn = create_node (i);
    while ((pos > 0) && (n))
    {
        n = n->next;
        pos--;
    }
    
    if (n)
    {
        if (n->next)
        {
            next = n->next;
        }
        n->next = nn;
        nn->next = next;
    }
}


void free_list (slist_t *list)
{
    if (!list)
        return;

    node_t *n = list->head;
    node_t *tmp = NULL;
    while (n)
    {
        tmp = n;
        n = n->next;
        free_node (tmp);
    }

    free (list);
}
