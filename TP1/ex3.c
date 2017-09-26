#include <stdio.h>
#include <time.h>

int main() {
	int pgcdIte(int a, int b);
	int pgcdRec(int a, int b);
	int a;
	int b;
	int res;
	clock_t t1, t2;
	double temps;
	
	do {
		printf("\n    Saisir a>0 : ");
		scanf("%d", &a);
	} while(a <= 0);
	
	do {
		printf("    Saisir b>0 : ");
		scanf("%d", &b);
	} while(a <= 0);
	
	//itératif
	t1 = clock();
	for(int i = 0 ; i < 100000 ; i++) res = pgcdIte(a, b);
	t2 = clock();
	temps = ( (double)(t2 - t1) / (double)CLOCKS_PER_SEC ) * (double) 1000;
	printf("\n    (Iteratif)\n    PGCD(%d, %d) = %d\n    Temps d'execution : %f ms\n", a, b, res, temps);
	
	//récursif
	t1 = clock();
	for(int i = 0 ; i < 100000 ; i++) res = pgcdRec(a, b);
	t2 = clock();
	temps = ( (double)(t2 - t1) / (double)CLOCKS_PER_SEC ) * (double) 1000;
	printf("\n    (Recursif)\n    PGCD(%d, %d) = %d\n    Temps d'execution : %f ms\n", a, b, res, temps);

	return 0;
}


//	Cette fonction permet de calculer le PGCD entre 2 nombres entier de manière itérative
//	Paramètre(s) :
//		a: 1er entier
//		b: 2ème entier 
//	Précondition :
//		a>0
//		b>0
//	Retourne pgcd(a,b)

int pgcdIte(int a, int b) {

	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;


}


//	Cette fonction permet de calculer le PGCD entre 2 nombres entier de manière récursive
//	Paramètre(s) :
//		a: 1er entier
//		b: 2ème entier 
//	Précondition :
//		a>0
//		b>0
//	Retourne pgcd(a,b)

int pgcdRec(int a, int b) {

	if (a == b) {
		return a;
	}
	else {
		if (a > b) {
			return pgcdRec(a - b, b);
		}
		else {
			return pgcdRec(a, b - a);
		}
	}
}
