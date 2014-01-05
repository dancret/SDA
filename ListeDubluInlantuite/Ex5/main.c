#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "dll.h"

circ_dll *list1;
node *startPoint;
int n,m;

void insert_test_data()
{
    int i;
    char *test_data[20];
    test_data[0]  = "Illa Hinrichs";
    test_data[1]  = "Donnie Brand";
    test_data[2]  = "Geraldo Hurn";
    test_data[3]  = "Curt Hank";
    test_data[4]  = "Myrta Waggoner";
    test_data[5]  = "Lisabeth Yother";
    test_data[6]  = "Miguelina Sturgis";
    test_data[7]  = "Lorrine Peake";
    test_data[8]  = "Margery Vasquez";
    test_data[9]  = "Nadia Rathburn";
    test_data[10] = "Bibi Sporer";
    test_data[11] = "Paula Gerrity";
    test_data[12] = "Gretchen Fairchild";
    test_data[13] = "Rickie Daye";
    test_data[14] = "Ezekiel Biddle";
    test_data[15] = "Jestine Gleaves";
    test_data[16] = "Melida Wadlington";
    test_data[17] = "Natalia Sandlin";
    test_data[18] = "Heike Raiford";
    test_data[19] = "Liane Hurley";

    list1 = (circ_dll*)malloc(sizeof(circ_dll));
    list1->start = NULL;
	list1->size  = 0;

    for (i = 0; i < 20 ; i++){
        insert_node(&(list1->start), 3, 0, test_data[i]);
        list1->size++;
    }
}

void insert_data()
{
    int option = 0;
    while (option < 1 || option > 2) {
        system("cls");
        printf("\n1 - Test data\n2 - Console data");
        printf("\nChoose option:");
        scanf("%d", &option);
    }

    switch(option) {
        case 1:
            insert_test_data();
            break;
        case 2:
            break;
        default:
            break;
    }
}

void count_nodes()
{
    node *curr,*temp;
    int i = 1;

    curr = startPoint;
    do {
        if (i == m) {
            printf("\nNode %s removed.", curr->value);
         	temp = curr->next;
			delete_node(list1, 2, curr);
			curr = temp;
            i = 1;		  
        } else {
            i++;
            printf("\n%d", i);
			curr = curr->next;
        }
	} while (list1->size != 1);
	printf("\nEnd game!");
	free(list1);
	list1 = NULL;
}

void start_game()
{
    char nume[40];
    int found = 0;

	if (list1 == NULL) {
        printf("\nInsert data first!");
        return;
    }

    while(!found) {
        system("cls");
        printf("\nName:");
        gets(nume);
        startPoint = search_for_node(list1, nume);
        if (startPoint == NULL) {
            found = 0;
            printf("\nNode not found!");
            getch();
        } else {
            found = 1;
            printf("\nStart point : %s.", startPoint->value);
            getch();
        }
    }

    while(m < 2 || m > list1->size) {
        system("cls");
        printf("\nNumaratoare (>=2):");
        scanf("%d", &m);
    }

    display(list1);
    printf("\nStart point: %s.", startPoint->value);
    count_nodes();
}

int main(void)
{
    int option = 0;

    while (option != 4) {
        system("cls");
        printf("\n1 - Insert data\n2 - Start game\n3 - Display list\n4 - Quit");
        printf("\nChoose option:");
        scanf("%d", &option);
        switch(option) {
            case 1:
                insert_data();
                display(list1);
                getch();
                break;
            case 2:
                start_game();
                getch();
                break;
            case 3:
				display(list1);
                break;
			case 4:
				break;
            default:
                printf("\nInvalid option!");
                getch();
        }
    }

    return 0;
}
