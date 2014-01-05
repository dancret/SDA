/**
* BinaryTree.h
*/

#include <string.h>
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

typedef struct simple_date {
	int day;
	int month;
	int year;
} date;

typedef struct bt_node {
    char *nume;
	float pret;
	int cantitate;
	date data_primirii,data_expirarii;
	struct bt_node *left,*right;
} medicament;

void insert_node(medicament **curr, char nume[50], float pret, int cantitate, date data_primirii, date data_expirarii);

void delete_node(medicament **curr, char nume[50]);

medicament* search_for_node(medicament *curr, char nume[50]);

void pre_order(medicament *curr);

void in_order(medicament *curr);

void post_order(medicament *curr);

#endif