#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_NODES 100

int *graph_matrix = NULL;
int no_of_nodes = 0;

void create_graph()
{
	int i,j;
	int rel = -1;

	if(graph_matrix != NULL) {
		free(graph_matrix);
		graph_matrix = NULL;
	}

	no_of_nodes = 0;

	while (no_of_nodes < 1 || no_of_nodes > MAX_NODES) {
		system("cls");
		printf("\nNumar de noduri: ");
		scanf("%d", &no_of_nodes);
	}

	graph_matrix = (int *)malloc(no_of_nodes * no_of_nodes * sizeof(int));

	for (i = 0 ; i < no_of_nodes; i++) {
		for (j = i; j < no_of_nodes; j++) {

			if (i == j) {
				graph_matrix[i*no_of_nodes + j] = 0;
			} else {
				while (rel < 0 || rel > 1) {
					printf("\nRelatia dintre nodul %d si nodul %d(0 - nu sunt legate, 1 - sunt legate): ", i+1, j+1);
					scanf("%d", &rel);
				}
				graph_matrix[i*no_of_nodes + j] = rel;
				graph_matrix[j*no_of_nodes + i] = rel;
				rel = -1;
			}
		}
	}
}

void print_graph_matrix()
{
	int i,j;

	if (graph_matrix == NULL) {
		printf("\nGraful nu exista!");
		return;
	}

	if (no_of_nodes < 10) {
		printf("\n \t");
		for (i = 0; i < no_of_nodes; i++) {
			printf(" %d", i+1);
		}
		printf("\n");	
		
		for (i = 0; i < no_of_nodes ; i++) {
			printf("\n%d\t", i+1);
			for (j = 0; j < no_of_nodes; j++)  {
				printf(" %d", graph_matrix[i*no_of_nodes + j]);		
			}
		}
	} else if (no_of_nodes < 100) {
		printf("\n  \t  1  2  3  4  5  6  7  8  9");
		for (i = 9; i < no_of_nodes; i++) {
			printf(" %d", i+1);
		}
		printf("\n");

		for (i = 0; i < 9 ; i++) {
			printf("\n %d\t", i+1);
			for (j = 0; j < no_of_nodes; j++)  {
				printf("  %d", graph_matrix[i*no_of_nodes + j]);		
			}
		}

		for (i = 9; i < no_of_nodes ; i++) {
			printf("\n%d\t", i+1);
			for (j = 0; j < no_of_nodes; j++)  {
				printf("  %d", graph_matrix[i*no_of_nodes + j]);		
			}
		}
	} else {
		printf("\n  \t   1   2   3   4   5   6   7   8   9");
		for (i = 9; i < no_of_nodes-1; i++) {
			printf("   %d", i+1);
		}
		printf(" 100\n");

		for (i = 0; i < 9; i++) {
			printf("\n  %d\t", i+1);
			for (j = 0; j < no_of_nodes; j++)  {
				printf("   %d", graph_matrix[i*no_of_nodes + j]);		
			}
		}

		for (i = 9; i < no_of_nodes ; i++) {
			printf("\n %d\t", i+1);
			for (j = 0; j < no_of_nodes; j++)  {
				printf("  %d", graph_matrix[i*no_of_nodes + j]);		
			}
		}

		printf("\n100\t");
		for (j = 0; j < no_of_nodes; j++)  {
			printf("  %d", graph_matrix[i*no_of_nodes + j]);		
		}
	}	
}

void get_min_number_of_colors()
{
	int i,j;
	int no_of_colors = 1;

	if (graph_matrix == NULL) {
		printf("\nGraful nu exista!");
		return;
	}

	for (i = 0; i < no_of_nodes; i++)  {
		for (j = i+1; j < no_of_nodes-1; j++) {
			if (graph_matrix[i*no_of_nodes + j] == 1) {
				no_of_colors++;	
			}	
		}
	}

	printf("\nNumarul minim de culori este: %d.", no_of_colors);
}

int main(void)
{
	int option = 0;

	while (option != 4)
	{
		system("cls");
		printf("\n1 - Creeaza graf neorientat\n2 - Afiseaza graf\n3 - Nr. minim de culori\n4 - Exit");
		printf("\nAlege optionea: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				create_graph();
				getch();
				break;
			case 2:
				print_graph_matrix();
				getch();
				break;
			case 3:
				get_min_number_of_colors();
				getch();
				break;
			case 4:
				break;
			default:
				break;
		}
	}

	return 0;
}