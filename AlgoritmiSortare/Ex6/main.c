#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_SIZE 50

int m,n;
int *sortList = NULL;

void print_list()
{
	int i;

	if (sortList == NULL) {
		printf("\nVectorul este gol!");
		getch();
	}

	for(i = 0 ; i < n; i++) {
		printf("\nA[%d]: %d", i, sortList[i]);
	}
}

void sort_inserare_directa(int start, int end, int a[])
{
	int i,j,x;

	for(j = 1 ; j < n ; j++) {
		x = a[j];
		i = j-1;
		while(i >= 0 && x < a[i]) {
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = x;
	}
}

int partition(int a[], int l, int r) 
{
	int i, j;
	float pivot, x;
    pivot = a[l];
    i = l; j = r+1;
		
    while(1)	{
	    do {
			++i;
		} while( a[i] <= pivot && i <= r );
	    do {
			--j;
		} while( a[j] > pivot );
   	    if( i >= j ) break;
		x = a[i]; a[i] = a[j]; a[j] = x;
    }
    x = a[l]; a[l] = a[j]; a[j] = x;
    return j;
}

void quicksort( int a[], int l, int r)
{
	int j;

	if(r - l <= m) {
		return;	
	}

    if( l < r) {
   		// divide and conquer
        j = partition( a, l, r);
		quicksort( a, l, j-1);
		quicksort( a, j+1, r);
	}
}

void custom_sort()
{
	int i = 0;

	m = -1;
	while(m < 1 || m > n) {
		system("cls");
		printf("\nMarime partitie ( <%d): ", n);
		scanf("%d", &m);
	}

	quicksort(sortList, 0, n-1);
	print_list();
	printf("\n");
	sort_inserare_directa(0, n, sortList);
}

void sorteaza()
{
	int option = 0;

	if (sortList == NULL) {
		printf("\nVectorul este gol!");
		getch();
		return;
	}

	while(option < 1 || option > 3) {
		system("cls");
		printf("\n1 - Inserare directa\n2 - Quicksort\n3 - Combinat");
		printf("\nAlege optiune: ");
		scanf("%d", &option);
	}

	switch(option) {
		case 1:
			sort_inserare_directa(0,n,sortList);
			break;
		case 2:
			quicksort(sortList, 0, n-1);
			break;
		case 3:
			custom_sort();
			break;
		default:
			break;
	}

	print_list();
	getch();
}

void create_list()
{
	int i;

	if (sortList != NULL) {
		free(sortList);
		sortList = NULL;
	}

	n = 0;
	while(n < 1 || n > MAX_SIZE) {
		system("cls");
		printf("\nMarimea vectorului ( < 50): ");
		scanf("%d", &n);
	}

	sortList = (int *)malloc(n * sizeof(int));

	for(i = 0 ; i < n; i++) {
		printf("\nA[%d]: ", i);
		scanf("%d", &sortList[i]);
	}

	print_list();
	getch();
}

int main(void)
{
	int option = 0;

	while(option != 4) {
		system("cls");
		printf("\n1 - Creeaza vector\n2 - Afiseaza vector\n3 - Sorteaza\n4 - Exit");
		printf("\nAlege optiune: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				create_list();
				break;
			case 2:
				print_list();
				getch();
				break;
			case 3:
				sorteaza();
				break;
			case 4:
				break;
			default:
				break;
		}
	}

	return 0;
}