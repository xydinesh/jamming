#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "llist.h"

int main (int argc, const char **argv)
{
    slist_t *list;
    int i = 0;
    int n = 0;
    int j = 0;

    if (argc < 2)
    {
        fprintf (stderr, "usage:%s #of elements\n", argv[0]);
        exit(0);
    }
    n = atoi(argv[1]);
    list = create_list ();
    srand(time(NULL));
    
    for (i = 0; i < n; i++)
    {
        j = rand()%100;
        add_element (list, j);
    }
    
    print_list (list);
    delete_element (list, 2);
    print_list (list);
    delete_element (list, 0);
    print_list (list);
    delete_element (list, 100);
    print_list (list);
    insert_element (list, 1200, 2);
    insert_element (list, 1200, 2);
    insert_element (list, 0, 9);
    insert_element (list, 0, 20);
    print_list (list);
    return 0;
}
