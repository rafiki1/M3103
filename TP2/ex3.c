#include <stdio.h>
#include <stdlib.h>

int main() {
	void quickSort(int tab[], int a, int b);
	int taille;
	int* tab;
	
	printf("\n");
	do {
		printf("taille du tableau ( >0 ) : ");
		scanf("%d", &taille);
	} while(taille <= 0);
	
	tab = malloc(taille*sizeof(int));
	
	printf("\n");	
	for(int i = 0 ; i < taille ; i++) {
		printf("nb %d : ", i+1);
		scanf("%d", tab+i);
	}
	
	quickSort(tab, 0, taille-1);
	
	printf("\n{");
	for(int i = 0 ; i < taille-1 ; i++) {
		printf("%d, ", *(tab+i));
	}
	printf("%d}\n", *(tab+taille-1));
	
	free(tab);	
	return 0;
}

//	Cette procédure tri un tableau d'entier par ordre croissant entre deux positions avec la méthode quickSort
//	Paramètre(s) :
//		tab : le tableau d'entier
//		a : position 1 (Entier)
//		b : position 2 (Entier)
//	Précondition(s) :
//		a >= 0
//		b < taille tableau
//		a <= b
//	Post-condition(s) :
//		Le tableau est trié par ordre croissant

void quickSort(int tab[], int a, int b) {
	int i = a;
	int j = b;
	int pivot = tab[(a+b)/2];
	int tmp;
	
	while(i <= j) {
		while(tab[i] < pivot) i++;
		while(tab[j] > pivot) j--;
		
		if(i <= j) {
			tmp = tab[j];
			tab[j] = tab[i];
			tab[i] = tmp;
			i++;
			j--;
		}
	}
	
	if(a<j) quickSort(tab, a, j);
	if(i<b) quickSort(tab, i, b);
}
