/**
*dll.h
*dll - double linked list
*/
#include <string.h>
#ifndef _DLL_H_
#define _DLL_H_

typedef struct double_linked_list_node{
    int key;
    char *value;
    struct double_linked_list_node *prev;
    struct double_linked_list_node *next;
} node;

typedef struct circular_double_linked_list{
    int size;
    struct double_linked_list_node *start;
} circ_dll;

int display(circ_dll *list1);

char get_nume();

void insert_node(node **start, int option, int position, char value[40]);

void delete_node(circ_dll *list1, int option, node *delNode);

node* search_for_node(circ_dll *list1, char searchValue[40]);

#endif
