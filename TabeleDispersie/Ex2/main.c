#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define Size 100

typedef struct nod
{
	char *nume_prenume;
	char *s;
}NOD;

void print_menu()
{
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n    Alegeti optiune      \n");
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("1) Inserare\n");
    printf("2) Afisare\n");
    printf("3) Stergere\n");
    printf("4) Cautare\n");
    printf("5) Iesire\n");
}

int polynomial_f(char ch,int pos, int x){
    int character = ch,result =0;
    result = character*(x^pos);
    return result;
}

int hash_function(char *input){
    int i,sum = 0,hash_sum = 0;

    for(i=0 ; i < strlen(input) ; i++){
        sum+= input[i];
    }

    for(i=0 ; i < strlen(input) ; i++){
        hash_sum += polynomial_f(input[i], i, sum);
    }

    return hash_sum;
}

int hash_cautare(struct nod T[], char nume_prenume[50])
{
	int i,j;
	i = 0;
	while(i!=Size)
        {
	    j = hash_function(nume_prenume) % Size;
	    if((strcmp(T[j].nume_prenume, nume_prenume) == 0) && (T[j].s == "FULL"))
            {
	    	return j;
	    }
	    i++;
	}
	return -1;
}

void hash_stergere(struct nod *T, char nume_prenume[50])
{
	int i;
	i = hash_function(nume_prenume) % Size;
	if(i != -1) {
		T[i].s = "Sters!!";
		printf("\nElementul a fost sters.\n");
	}
	else
        {
		printf("Elementul nu a fost gasit in tabela!!\n");
	}
	return;
}

void hash_inserare(struct nod *T, char nume_prenume[50])
{
	int j,h;
    h = hash_function(nume_prenume);
    printf("\nHash: %d\n", h);
	j = h % Size;
    if(T[j].s == "NULL" || T[j].s == "Sters!!"){
            T[j].nume_prenume = malloc(1 + strlen(nume_prenume));
            strcpy(T[j].nume_prenume, nume_prenume);
            T[j].s = "FULL";
	} else {
		printf("Tabela este full -> overflow\n");
	}
}

int main(){
	int i,a,k=0;
	char nume_prenume[50];
	struct nod T[Size];

    for (i = 0; i< Size; i++){
        T[i].s = "NULL";
    }

	while(k!=5) {
        system("cls");
        print_menu();
        printf("\nAlegeti optiunea: ");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
                printf("\nIntroduceti valoarea:");
                scanf("%s", &nume_prenume);
                hash_inserare(T,nume_prenume);
                getch();
                break;
            case 2:
				for(i = 0;i<Size;i++) {
					if(T[i].s == "FULL") {
                        printf("\n%d. %s\n", i, T[i].nume_prenume);
					} else {
                        printf("\n%d. %s", i, T[i].s);
					}
				}
				getch();
				break;
			case 3:
				printf("Introduceti valoarea care doriti sa o stergeti: ");
				scanf("%s", &nume_prenume);
				hash_stergere(T,nume_prenume);
				printf("\n");
				getch();
				break;
			case 4:
				printf("Introduceti valoarea de cautat: ");
				scanf("%s", &nume_prenume);
				i = hash_cautare(T,nume_prenume);
				printf("Elementul %s este prezent in tabela la pozitia %d !\n", nume_prenume,i);
				printf("\n");
				getch();
				break;
			case 5:
			    exit(5);
			    break;
			default:
				printf("Optiune gresita!!!\n");
				getch();
				break;

		}
	}
	return 0;
}
