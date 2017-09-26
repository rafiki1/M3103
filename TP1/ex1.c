#include <stdio.h>
#include <time.h>

int main() {
	
	int sommeNPremierIte(int n);
	int sommeNPremierRec(int n);
	int n;
	int res;

	do {
		printf("Saisir n>=0  : ");
		scanf("%d", &n);
	} while (n < 0);
	
	//itératif
	res = sommeNPremierIte(n);
	printf("\n(Iteratif)\nLa somme des %d premiers entier vaut : %d\n", n, res);
	
	//récursif
	res = sommeNPremierRec(n);
	printf("\n(Recursif)\nLa somme des %d premiers entier vaut : %d\n", n, res);
	
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
	
	if (n == 0) {
		return 0;
	}
	else {
		return n + sommeNPremierRec(n - 1);
	}

}
