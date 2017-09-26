#include <stdio.h>
#include <time.h>

int main() {
	
	int sommeNPremierIte(int n);
	int sommeNPremierRec(int n);
	int n;
	int res;
	clock_t t1
	clock_t t2;
	double temps;

	do {
		printf("Saisir n>=0  : ");
		scanf("%d", &n);
	} while (n < 0);
	
	//itératif
	t1 = clock();
	res = sommeNPremierIte(n);
	t2 = clock();
	temps = ( (double)(t2 - t1) / (double)CLOCKS_PER_SEC ) * (double) 1000;
	printf("\n(Iteratif)\nLa somme des %d premiers entier vaut : %d\nTemps d'execution : %f ms\n", n, res, temps);
	
	//récursif
	t1 = clock();
	res = sommeNPremierRec(n);
	t2 = clock();
	temps = ( (double)(t2 - t1) / (double)CLOCKS_PER_SEC ) * (double) 1000;
	printf("\n(Recursif)\nLa somme des %d premiers entier vaut : %d\nTemps d'execution : %f ms\n", n, res, temps);
	
	return 0;
}


//	Cette fonction calcul la somme des n premiers entier de manière itérative
//	Paramètre(s) :
//		n : entier											 
//	Précondition(s) :
//		n>=0
//	retourne n premer entier

int sommeNPremierIte(int n) {
	
	int res=0;
	
	for (int i = 1 ; i <= n ; i++) {
		for(int j = 0 ; j < 1000 ; j++); //boucle pour allonger le temps d'execution
		res = res+ i;
	}
	
	return res;
}


//	Cette fonction calcul la somme des n premiers entier de manière récursive
//	Paramètre(s) :
//		n : entier
//	Précondition(s) :
//		n>=0
//	retourne n premer entier

int sommeNPremierRec(int n) {
	
	for(int i = 0 ; i < 1000 ; i++); //boucle pour allonger le temps d'execution
	
	if (n == 0) {
		return 0;
	}
	else {
		return n + sommeNPremierRec(n - 1);
	}

}
