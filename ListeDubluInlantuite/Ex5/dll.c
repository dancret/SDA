#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int display(circ_dll *list1){
    int i;
    node *curr;
    curr = (node*)malloc(sizeof(node));

    if(list1 != NULL && list1->start != NULL){
        curr = list1->start;

        i = 0;
        /*while(curr != NULL){
            i++;
            printf("\n%d. %s", i, curr->value);
            curr = curr->next;
        }*/

        do {
            i++;
            printf("\n%d. %s", i, curr->value);
            curr = curr->next;
        }while(curr != list1->start);
    }
    return 0;
}

char get_value(){
    char nume[40];
    printf("Enter name: ");
    scanf("%d", &nume);
    return nume;
}

void insert_node(node **start, int option, int position, char value[40]){
    int i;
    node *curr,*temp;

    curr = (node*)malloc(sizeof(node));
    temp = (node*)malloc(sizeof(node));

    switch(option){
        case 1: //Beginning
            curr->value = value;
            curr->next = *start;
            *start = curr;
            curr->prev = *start;
            break;
        case 2: //At position
            if(position == 1){
                curr->value = value;
                curr->next = *start;
                *start = curr;
                curr->prev = *start;
            } else {
                temp = *start;
                for(i=1 ; i < position-1 ; i++){
                    temp = temp->next;
                }
                curr->value = value;
                curr->next = temp->next;
                curr->prev = temp;
                temp->next = curr;
            }
            break;
        case 3: //End
            if(*start == NULL) {
                *start = curr;
                curr->next = curr;
                curr->prev = curr;
            } else {
                temp = *start;

                do {
                    temp = temp->next;
                } while (temp != *start);

                curr->next = temp->next;
                curr->prev = temp;
                temp->next->prev = curr;
                temp->next = curr;

                /*while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = curr;
                curr->prev = temp;*/
            }
            curr->value = value;

            break;
        default:
            break;
        }
}

void delete_node(circ_dll *list1, int option, node *delNode){
    node *prev,*temp;

    switch(option){
        case 1: //Beginning
            temp = list1->start;
            if(temp != NULL){
                list1->start = temp->next;
                printf("Node %s deleted\n", temp->value);
                free(temp);
            }
            break;
        case 2: //Having data
			temp = delNode;
            if(temp->next == temp) {
				list1->start = NULL;
                list1->size = 0;
            } else {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                if(temp == list1->start) {
                    list1->start = temp->prev;
                }
                free(temp);
                list1->size--;
            }
            break;
        case 3: //End
            temp = list1->start;
            if(temp->next == NULL){
                printf("Node %d deleted\n", temp->value);
                free(temp);
                list1->start = NULL;
            } else {
                while(temp->next != NULL){
                    prev = temp;
                    temp = temp->next;
                }
                printf("Node %d deleted\n", temp->value);
                free(temp);
                prev->next = NULL;
            }
        default:
            break;
    }
}

node* search_for_node(circ_dll *list1, char searchValue[40]){
    int pos = 1;
    node *temp;

    temp = list1->start;

    if(strcmp(temp->value, searchValue) == 0){
        return temp;
    } else {
        do {
            temp = temp->next;
            if (strcmp(temp->value, searchValue) == 0) {
                return temp;
            }
        } while (temp != list1->start);
        /*while(temp->next != NULL){
            temp = temp->next;
            pos++;
            if(temp->value == value){
                printf("Node found at position %d\n", pos);
                count++;
            }
        }*/
    }
    return NULL;
}
