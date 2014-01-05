#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_SIZE 100

int *A = NULL;
int *B = NULL;
int sizeA = 0;
int sizeB = 0;

void afiseaza_multimile()
{
	int i;

	if(A == NULL || B == NULL) {
		printf("\nMultimile sunt goale!");
		return;
	}

	printf("\nA = [%d", A[0]);
	for(i = 1 ; i < sizeA ; i++) {
		printf(", %d", A[i]);
	}
	printf("]\n");

	printf("\nB = [%d", B[0]);
	for(i = 1 ; i < sizeB ; i++) {
		printf(", %d", B[i]);
	}
	printf("]\n");
}

void creeaza_multimile()
{
	int i;

	while(sizeA < 1 || sizeA > MAX_SIZE) {
		system("cls");
		printf("\n-- Multimea A --\n");
		printf("Nr. elemente multimea A: ");
		scanf("%d", &sizeA);
	}

	A = (int*)malloc(sizeA * sizeof(int));

	for(i = 0 ; i < sizeA ; i++) {
		printf("\nA[%d]: ", i);
		scanf("%d", &A[i]);
	}

	while(sizeB < 1 || sizeB > MAX_SIZE) {
		system("cls");
		printf("\n-- Multimea B --\n");
		printf("Nr. elemente multimea B: ");
		scanf("%d", &sizeB);
	}

	B = (int*)malloc(sizeB * sizeof(int));

	for(i = 0 ; i < sizeB ; i++) {
		printf("\nB[%d]: ", i);
		scanf("%d", &B[i]);
	}
}

void AwithB(int a[], int b[], int m, int n)
{
	if(a == NULL || b == NULL) {
		printf("\nMultimile sunt goale!");
		return;
	}

	if (m < 0) {
		return;
	} 
	else if (n < 0) {
		printf("\n");
		AwithB(a, b, m-1, sizeB-1);
	} else {	
		printf("f(%d) = %d  ", a[m], b[n]);
		AwithB(A, B, m, n-1);
	}
}

int main(void)
{
	int option = 0;

	while(option != 4) {
		system("cls");
		printf("\nAlegeti optiunea:");
		printf("\n1 - Creeaza multimile\n2 - Afiseaza multimile\n3 - Genereaza functiile\n4 - Exit\n");
		scanf("%d", &option);
		switch(option) {
			case 1:
				creeaza_multimile();
				getch();
				break;
			case 2:
				afiseaza_multimile();
				getch();
				break;
			case 3:
				AwithB(A, B, sizeA-1, sizeB-1);
				getch();
				break;
			case 4:
				break;
			default:
				break;
		}
	}
}