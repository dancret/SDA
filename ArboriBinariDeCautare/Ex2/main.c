#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct bt_node {
    int value;
    struct bt_node *left,*right;
} node;

node *root1 = NULL;
node *root2 = NULL;
node *root_final = NULL;

void insert_node(node **curr, int val){
    if(*curr == NULL){
        *curr = (node*)malloc(sizeof(node));
        (*curr)->value = val;
        (*curr)->left = NULL;
        (*curr)->right = NULL;
    } else {
        if(val < (*curr)->value)
            insert_node( &( (*curr)->left ), val);
        else if(val > (*curr)->value)
            insert_node( &( (*curr)->right), val);
        else
            printf("\n%d este un duplicat!", val);
    }
}

void delete_node(node **curr, int val){
    node *temp, *prev, *next;
    temp = *curr;

    if(*curr == NULL)
        printf("Arborele este gol!");
    else {
        //Search node
        while(temp->value != val && temp != NULL){
            prev = temp;
            if(temp->value > val)
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
            temp->value = next->value;
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
        printf("\nNodul a fost sters.\n");
    }
}

void search_for_node(node *curr, int val){
    if(curr == NULL)
        printf("\nNode not found\n");
    else {
        if(val < curr->value)
            search_for_node(curr->left, val);
        else if(val > curr->value)
            search_for_node(curr->right, val);
        else
            printf("\nNode Found: %d\n", curr->value);
    }
}

void pre_order(node *curr){ // Parent - Left - Right
    if(curr != NULL){
        printf("%d  ", curr->value);
        pre_order(curr->left);
        pre_order(curr->right);
    }
}

void in_order(node *curr){ // Left - Parent - Right
    if(curr != NULL){
        in_order(curr->left);
        printf("%d  ", curr->value);
        in_order(curr->right);
    }
}

void post_order(node *curr){ // Left - Right - Parent
    if(curr != NULL){
        post_order(curr->left);
        post_order(curr->right);
        printf("%d  ", curr->value);
    }
}

void add_node()
{
	int option,value;
	option = 0;

	while (option < 1 || option > 3) {
		system("cls");
		printf("\n1 - Primul arbore\n2 - Al doilea arbore\n3 - Inapoi");
		printf("\nAlege optiune: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				printf("\nIntroduceti valoarea: ");
                scanf("%d", &value);
				insert_node(&root1,value);
				option = 0;
				getch();
				break;
			case 2:
				printf("\nIntroduceti valoarea: ");
                scanf("%d", &value);
				insert_node(&root2,value);
				option = 0;
				getch();
				break;
			case 3:
				return;
				break;
			default:
				break;
		}
	}
}

void del_node()
{
	int option,value;
	option = 0;

	while (option < 1 || option > 3) {
		system("cls");
		printf("\n1 - Primul arbore\n2 - Al doilea arbore\n3 - Inapoi");
		printf("\nAlege optiune: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				printf("\nIntroduceti valoarea: ");
                scanf("%d", &value);
				delete_node(&root1,value);
				option = 0;
				getch();
				break;
			case 2:
				printf("\nIntroduceti valoarea: ");
                scanf("%d", &value);
				delete_node(&root2,value);
				option = 0;
				getch();
				break;
			case 3:
				return;
				break;
			default:
				break;
		}
	}
}

void search()
{
	int option,value;
	option = 0;

	while (option < 1 || option > 3) {
		system("cls");
		printf("\n1 - Primul arbore\n2 - Al doilea arbore\n3 - Inapoi");
		printf("\nAlege optiune: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				printf("\nIntroduceti valoarea: ");
                scanf("%d", &value);
				search_for_node(&root1,value);
				option = 0;
				getch();
				break;
			case 2:
				printf("\nIntroduceti valoarea: ");
                scanf("%d", &value);
				search_for_node(&root2,value);
				option = 0;
				getch();
				break;
			case 3:
				return;
				break;
			default:
				break;
		}
	}
}

void display_btree()
{
	int option,value;
	option = 0;

	while (option < 1 || option > 3) {
		system("cls");
		printf("\n1 - Primul arbore\n2 - Al doilea arbore\n3 - Arborele interclasat\n4 - Inapoi");
		printf("\nAlege optiune: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				if (root1 == NULL) {
					printf("\nArborele este gol!");
				} else {
					printf("\n-- Primul arbore --\n");
					in_order(root1);
				}
				option = 0;
				getch();
				break;
			case 2:
				if (root2 == NULL) {
					printf("\nArborele este gol!");
				} else {
					printf("\n-- Al doilea arbore --\n");
					in_order(root2);
				}
				getch();
				option = 0;
				break;
			case 3:
				if (root_final == NULL) {
					printf("\nArborele este gol!");
				} else {
					printf("\n-- Arborele interclasat --\n");
					in_order(root_final);
				}
				getch();
				option = 0;
				break;
			case 4:
				return;
				break;
			default:
				break;
		}
	}	
}

void traverseaza(node *curr)
{
	if(curr != NULL) {
		traverseaza(curr->left);
		insert_node(&root_final, curr->value);
		traverseaza(curr->right);
	}
}

void interclaseaza()
{
	if (root_final != NULL)	{
		free(root_final);
		root_final == NULL;
	}

	traverseaza(root1);
	traverseaza(root2);
	system("cls");
	printf("\n-- Arborele interclasat --\n");
	in_order(root_final);
	getch();
}

int main(){
    int option = 0;

    while(option != 6){
        system("cls");
        printf("\n1.Adauga nod\n2.Sterge nod\n3.Cauta nod\n4.Afiseaza arbore\n5.Interclaseaza arborii\n6.Exit");
        printf("\nAlege optiune: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                add_node();
                break;
            case 2:
                del_node();
                break;
            case 3:
                search();
                break;
            case 4:
                display_btree();
                break;
            case 5:
				interclaseaza();
                break;
            case 6:
                break;
			default:
				break;
        }
    }

    return 0;
}
