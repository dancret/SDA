#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define Size 100

int ht_size = 0;

typedef struct nod
{
	char *id;
	char *s;
}NOD;

void print_menu()
{
    printf("\n Alegeti optiune\n");
    printf("1 - Inserare\n");
    printf("2 - Afisare\n");
    printf("3 - Stergere\n");
    printf("4 - Cautare\n");
	printf("5 - Listare alfabetica\n");
    printf("6 - Iesire\n");
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

int hash_cautare(NOD T[], char id[50])
{
	int i,j;
	i = 0;
	while(i!=Size)
        {
	    j = hash_function(id) % Size;
	    if((strcmp(T[j].id, id) == 0) && (T[j].s == "FULL"))
            {
	    	return j;
	    }
	    i++;
	}
	return -1;
}

void hash_stergere(NOD *T, char id[50])
{
	int i;
	i = hash_function(id) % Size;
	if(i != -1) {
		T[i].s = "Sters!!";
		ht_size--;
		printf("\nElementul a fost sters.\n");
	}
	else
        {
		printf("Elementul nu a fost gasit in tabela!!\n");
	}
	return;
}

void hash_inserare(NOD *T, char id[50])
{
	int j,h;
    h = hash_function(id);
	j = h % Size;
    if(T[j].s == "NULL" || T[j].s == "Sters!!"){
            T[j].id = (char *)malloc(1 + strlen(id));
            strcpy(T[j].id, id);
            T[j].s = "FULL";
			ht_size++;
	} else {
		printf("Tabela este full -> overflow\n");
	}
}

void listeaza_alfabetic(NOD *T)
{
	char **idArray = malloc(ht_size * sizeof(char*));
	int i,j = 0;
	char *tempId;

	for(i = 0 ; i < Size ; i++) {
		if(T[i].s == "FULL") {
			idArray[j] = malloc((strlen(T[i].id)+1) * sizeof(char));
			idArray[j] = T[i].id;
			j++;
		}		
	}

	for(i = 0 ; i < ht_size ; i++) {
		for(j = i+1 ; j < ht_size-1 ; j++) {
			if(strcmp(idArray[j], idArray[i]) < 0) {
				tempId = idArray[i];
				idArray[i] = idArray[j];
				idArray[j] = tempId;
			}
		}
	}

	for(i = 0 ; i < ht_size ; i++) {
		printf("\n%d. %s", i+1, idArray[i]);
	}
}

int main(){
	int i,a,k=0;
	char id[50];
	NOD T[Size];

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
                scanf("%s", &id);
                hash_inserare(T,id);
                getch();
                break;
            case 2:
				for(i = 0;i<Size;i++) {
					if(T[i].s == "FULL") {
                        printf("\n%d. %s\n", i, T[i].id);
					} else {
                        printf("\n%d. %s", i, T[i].s);
					}
				}
				getch();
				break;
			case 3:
				printf("Introduceti valoarea care doriti sa o stergeti: ");
				scanf("%s", &id);
				hash_stergere(T,id);
				printf("\n");
				getch();
				break;
			case 4:
				printf("Introduceti valoarea de cautat: ");
				scanf("%s", &id);
				i = hash_cautare(T,id);
				printf("Elementul %s este prezent in tabela la pozitia %d !\n", id,i);
				printf("\n");
				getch();
				break;
			case 5:
			    listeaza_alfabetic(T);
				getch();
			    break;
			case 6:
				break;
			default:
				printf("Optiune gresita!!!\n");
				getch();
				break;

		}
	}
	return 0;
}