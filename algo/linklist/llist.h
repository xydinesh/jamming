#ifndef __LLIST_H_
#define __LLIST_H_


typedef struct nodeT {
    int data;
    struct nodeT *next;
}node_t;

typedef struct listT {
    node_t *head;
}slist_t;

node_t *create_node (int i);

void free_node (node_t *n);

slist_t *create_list ();

void free_list (slist_t *list);

void add_element (slist_t *list, int i);

node_t *find_element (slist_t *list, int i);

void print_list (slist_t *list);

void delete_element (slist_t *list, int pos);

void insert_element (slist_t *list, int i, int pos);


#endif  /* __LLIST_H_ */
