#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "BinaryTree.h"

medicament *root = NULL;
medicament *root2 = NULL;
date min_date;

void create_bt()
{
	int i;
	char *nume_medicament[20] = {
		"ABILIFY",
		"NEXIUM",
		"CYMBALTA",
		"CRESTOR",
		"HUMIRA",
		"ENBREL",
		"REMICADE",
		"COPAXONE",
		"NEULASTA",
		"RITUXAN",
		"SPIRIVA",
		"ATRIPLA",
		"JANUVIA",
		"OXYCONTIN",
		"AVASTIN",
		"LANTUS",
		"DIOVAN",
		"HERCEPTIN",
		"VYVANSE",
		"TAMIFLU"
	};

	float pret_medicament[20] = { 
		10.0, 6.5, 7.8, 9.0, 9.5, 5.5, 4.5, 15, 17.5, 18,
		20, 7.5, 11, 13.5, 22.5, 25, 55, 23, 8.5, 14
	};

	int cantitate_medicament[20] = {
		100, 250, 350, 900, 550, 780, 950, 300, 430, 120,
		800, 750, 650, 460, 510, 210, 870, 720, 680, 490
	};

	int data_prim_med[20][3] = {
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
		{1, 1, 2012},
	};

	int data_exp_med[20][3] = {
		{31, 12, 2012},
		{19, 11, 2012},
		{22, 10, 2015},
		{20, 1, 2014},
		{25, 2, 2014},
		{29, 3, 2013},
		{3, 9, 2013},
		{1, 9, 2012},
		{1, 8, 2013},
		{1, 7, 2013},
		{5, 10, 2012},
		{12, 11, 2014},
		{10, 7, 2014},
		{12, 7, 2014},
		{15, 12, 2012},
		{21, 11, 2014},
		{20, 10, 2015},
		{17, 4, 2012},
		{1, 5, 2013},
		{2, 6, 2013}
	};

	date data_prim;
	date data_exp;

	if (root != NULL) {
		return;
	}

	for(i =0 ; i < 20; i++) {
		data_prim.day   = data_prim_med[i][0];
		data_prim.month = data_prim_med[i][1];
		data_prim.year  = data_prim_med[i][2];
		data_exp.day    = data_exp_med[i][0];
		data_exp.month  = data_exp_med[i][1];
		data_exp.year   = data_exp_med[i][2];
		insert_node(&root, nume_medicament[i], pret_medicament[i], cantitate_medicament[i], data_prim, data_exp);
	}
}

void add_med()
{
	char nume[50];
	float pret;
	int cantitate;
	date data_prim,data_exp;
	
	system("cls");
	printf("\nNume: ");
	scanf("%s", &nume);

	printf("\nPret: ");
	scanf("%f", &pret);

	printf("\nCantitate: ");
	scanf("%d", &cantitate);

	printf("\n- Data primirii -");
	printf("\nZiua: ");
	scanf("%d", &(data_prim.day));
	printf("\nLuna: ");
	scanf("%d", &(data_prim.month));
	printf("\nAnul: ");
	scanf("%d", &(data_prim.year));

	printf("\n- Data expirarii -");
	printf("\nZiua: ");
	scanf("%d", &(data_exp.day));
	printf("\nLuna: ");
	scanf("%d", &(data_exp.month));
	printf("\nAnul: ");
	scanf("%d", &(data_exp.year));

	insert_node(&root,nume,pret,cantitate,data_prim,data_exp);
	printf("\nMedicamentul a fost adaugat!");
}

void mod_date_med(medicament **med)
{
	int option = 0;
	float pret; int cantitate;
	int zi, luna, an;

	while(option != 5) {
		system("cls");
		printf("\nNume: %s", (*med)->nume);
		printf("\nPret: %f", (*med)->pret);
		printf("\nCantitate: %d", (*med)->cantitate);
		printf("\nData primirii: %d.%d.%d", (*med)->data_primirii.day, (*med)->data_primirii.month, (*med)->data_primirii.year);
		printf("\nData expirarii: %d.%d.%d", (*med)->data_expirarii.day, (*med)->data_expirarii.month, (*med)->data_expirarii.year);
		printf("\n1 - Modifica pret\n2 - Modifica cantitate\n3 - Modifica data primirii\n4 - Modifica data expirarii\n5 - Inapoi");
		printf("\nAlege optiunea:");
		scanf("%d", &option);

		switch(option) {
			case 1:
				printf("\nPret nou: ");
				scanf("%f", &pret);
				(*med)->pret = pret;
				break;
			case 2:
				printf("\nCantitate noua: ");
				scanf("%d", &cantitate);
				(*med)->cantitate = cantitate;
				break;
			case 3:
				printf("\n- Data primirii noua -");
				printf("\nZi: ");
				scanf("%d", &zi);
				(*med)->data_primirii.day = zi;
				printf("\nLuna: ");
				scanf("%d", &luna);
				(*med)->data_primirii.month = luna;
				printf("\nAn: ");
				scanf("%d", &an);
				(*med)->data_primirii.year = an;
				break;
			case 4:
				printf("\n- Data expirarii noua -");
				printf("\nZi: ");
				scanf("%d", &zi);
				(*med)->data_expirarii.day = zi;
				printf("\nLuna: ");
				scanf("%d", &luna);
				(*med)->data_expirarii.month = luna;
				printf("\nAn: ");
				scanf("%d", &an);
				(*med)->data_expirarii.year = an;
				break;
			case 5:
				break;
			default:
				break;
		}
	}
}

void search_med()
{
	medicament *med;
	char nume[50];
	int option, found;
	option = 0;
	found = 0;
	
	while(!found) {
		system("cls");
		printf("\nNume: ");
		scanf("%s", &nume);
		med = search_for_node(root, nume);
		if (med == NULL) {
			while(option < 1 || option > 2) {
				system("cls");
				printf("\nNedicamentul nu a fost gasit.");
				printf("\n1 - Continua\n2 - Inapoi\nAlege optiune:");
				scanf("%d", &option);
				if (option == 1) {
					option = 0;
					break;
				} else {
					return;
				}
			}
		} else {
			found = 1;
		}
	}
	mod_date_med(&med);
}

void list_meds()
{
	int option = 0;

	if(root2 == NULL) {
		in_order(root);
	} else {
		while(option < 1 || option > 2) {
			system("cls");
			printf("\n1 - Lista completa\n2 - Lista cu data expirarii mai mica de %d.%d.%d", min_date.day, min_date.month, min_date.year);
			printf("\nAlege optionea: ");
			scanf("%d", &option);
		}
		system("cls");
		if (option == 1) {
			printf("\n-- Lista completa --\n");
			in_order(root);
		} else {
			printf("\n-- Lista cu data expirarii mai mica de %d.%d.%d --\n", min_date.day, min_date.month, min_date.year);
			in_order(root2);
		}
	}	
}

void del_med()
{
	medicament *med;
	char nume[50];
	int option, found;
	option = 0;
	found = 0;
	
	while(!found) {
		system("cls");
		printf("\nNume: ");
		scanf("%s", &nume);
		med = search_for_node(root, nume);
		if (med == NULL) {
			while(option < 1 || option > 2) {
				system("cls");
				printf("\nNedicamentul nu a fost gasit.");
				printf("\n1 - Continua\n2 - Inapoi\nAlege optiune:");
				scanf("%d", &option);
				if (option == 1) {
					option = 0;
					break;
				} else {
					return;
				}
			}
		} else {
			found = 1;
		}
	}
	delete_node(&root, nume);
	printf("\nMedicamentul a fost sters.");
}

void check_dates(medicament *curr)
{
	if(curr != NULL) {
		if (curr->data_expirarii.year < min_date.year) {
			insert_node(&root2,curr->nume,curr->pret,curr->cantitate,curr->data_primirii,curr->data_expirarii);
		} else if (curr->data_expirarii.month < min_date.month && curr->data_expirarii.year <= min_date.year) {
			insert_node(&root2,curr->nume,curr->pret,curr->cantitate,curr->data_primirii,curr->data_expirarii);
		} else if (curr->data_expirarii.day < min_date.day && curr->data_expirarii.month <= min_date.month && curr->data_expirarii.year <= min_date.year) {
			insert_node(&root2,curr->nume,curr->pret,curr->cantitate,curr->data_primirii,curr->data_expirarii);
		}
		check_dates(curr->left);
		check_dates(curr->right);
	}
}

void create_new_bt()
{
	free(root2);
	root2 = NULL;
	system("cls");
	printf("\n- Introduceti data -");
	printf("\nZi: ");
	scanf("%d", &(min_date.day));
	printf("\nLuna: ");
	scanf("%d", &(min_date.month));
	printf("\nAn: ");
	scanf("%d", &(min_date.year));

	check_dates(root);

	if(root2 == NULL) {
		printf("\nNu a fost gasit nici un medicament cu data expirarii mai veche.");
	} else {
		in_order(root2);
	}
}

int main(void)
{
	int option = 0;

	create_bt();

	while(option != 6) {
		system("cls");
		printf("\n1 - Adauga medicament\n2 - Cauta medicament\n3 - Listeaza medicamentele\n4 - Sterge medicament\n5 - Creeaza lista cu medicamentele care au data expirarii mai mica de o data introdusa\n6 - Exit");
		printf("\nAlege optiune: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				add_med();
				getch();
				break;
			case 2:
				search_med();
				break;
			case 3:
				list_meds();
				getch();
				break;
			case 4:
				del_med();
				getch();
				break;
			case 5:
				create_new_bt();
				getch();
				break;
			case 6:
				break;
			default:
				break;
		}
	}

	return 0;
}