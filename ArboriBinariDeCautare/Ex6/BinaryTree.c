#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BinaryTree.h"

void insert_node(medicament **curr, char nume[50], float pret, int cantitate, date data_primirii, date data_expirarii)
{
    if(*curr == NULL){
        *curr = (medicament*)malloc(sizeof(medicament));
		(*curr)->nume	   = (char *)malloc(1 + strlen(nume));
		strcpy( (*curr)->nume, nume);
		(*curr)->pret	   = pret;
		(*curr)->cantitate = cantitate;
		(*curr)->data_primirii.day    = data_primirii.day;
		(*curr)->data_primirii.month  = data_primirii.month;
		(*curr)->data_primirii.year   = data_primirii.year;
		(*curr)->data_expirarii.day   = data_expirarii.day;
		(*curr)->data_expirarii.month = data_expirarii.month;
		(*curr)->data_expirarii.year  = data_expirarii.year;
		(*curr)->left  = NULL;
		(*curr)->right = NULL;
    } else {
		if(strcmp(nume, (*curr)->nume) < 0)
            insert_node( &( (*curr)->left ), nume, pret, cantitate, data_primirii, data_expirarii);
        else if(strcmp(nume, (*curr)->nume) > 0)
            insert_node( &( (*curr)->right), nume, pret, cantitate, data_primirii, data_expirarii);
        else
			printf("\n%d is a duplicate node", (*curr)->nume);
    }
}

void delete_node(medicament **curr, char nume[50]){
    medicament *temp, *prev, *next;
    temp = *curr;

    if(*curr == NULL)
        printf("Tree is empty");
    else {
        //Search node
        while(strcmp(temp->nume, nume) != 0 && temp != NULL){
            prev = temp;
            if(strcmp(nume, (*curr)->nume) < 0)
                temp = temp->left;
            else
                temp = temp->right;
        }

        //Node has 2 Subtress
        if(temp->left != NULL && temp->right != NULL){
            next = temp->right;
            while(next->left != NULL){
                prev = next;
                next = next->left;
            }
			strcpy(temp->nume, next->nume);
			temp->cantitate = next->cantitate;
			temp->pret = next->pret;
			temp->data_primirii.day   = next->data_primirii.day;
			temp->data_primirii.month = next->data_primirii.month;
			temp->data_primirii.year  = next->data_primirii.year;
			temp->data_expirarii.day  = next->data_expirarii.day;
			temp->data_expirarii.month= next->data_expirarii.month;
			temp->data_expirarii.year = next->data_expirarii.year;
            temp = next;
        }

        //Node has left Subtree
        if(temp->left != NULL && temp->right == NULL){
            if(prev->left == temp)
                prev->left = temp->left;
            else
                prev->right = temp->left;
        }

        //Node has right Subtree
        if(temp->left == NULL && temp->right !=NULL){
            if(prev->left == temp)
                prev->left = temp->right;
            else
                prev->right = temp->right;
        }

        //Node has no Subtrees or Children
        if(temp->left == NULL && temp->right == NULL){
            if(prev->left == temp)
                prev->left = NULL;
            else
                prev->right = NULL;
        }

        //Node is header
        if(temp == *curr){
            if(temp->left != NULL)
                *curr = temp->left;
            else
                *curr = temp->right;
        }

        free(temp);
    }
}

medicament* search_for_node(medicament *curr, char nume[50]){
    if(curr == NULL) {
        printf("\nNode not found\n");
		return NULL;
	} else {
        if(strcmp(nume, curr->nume) < 0)
            search_for_node(curr->left, nume);
        else if(strcmp(nume, curr->nume) > 0)
            search_for_node(curr->right, nume);
		else {
			printf("\nNode Found: %d\n", curr->nume);
			return curr;
		}
    }
}

void pre_order(medicament *curr)
{ // Parent - Left - Right
    if(curr != NULL){
		printf("\n- %s", curr->nume);
        pre_order(curr->left);
        pre_order(curr->right);
    }
}

void in_order(medicament *curr)
{ // Left - Parent - Right
    if(curr != NULL){
        in_order(curr->left);
        printf("\n- %s", curr->nume);
        in_order(curr->right);
    }
}

void post_order(medicament *curr)
{ // Left - Right - Parent
    if(curr != NULL){
        post_order(curr->left);
        post_order(curr->right);
        printf("\n- %s", curr->nume);
    }
}