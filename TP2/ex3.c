#include <stdio.h>

int main() {
	void quickSort(int tab[], int a, int b);
	int taille;
	int* tab;
	//int tab[9] = {9, 7, 5, 6, 2, 8, 4, 3, 1};
	
	quickSort(tab, 0, 8);
	
	printf("\n{");
	for(int i = 0 ; i < 8 ; i++) {
		printf("%d, ", tab[i]);
	}
	printf("%d}\n", tab[8]);
	
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
