#include <stdio.h>
#include <time.h>

int main() {
	double puissanceIte(double a, int n);
	double puissanceRec(double a, int n);
	double a;
	int n;
	double res;
	clock_t t1;
	clock_t t2;
	double temps;

	printf("Saisir a : ");
	scanf("%lf", &a);

	do {
		printf("Saisir n >= 0 : ");
		scanf("%d", &n);
	} while(n < 0);
	
	//itératif
	t1 = clock();
	res = puissanceIte(a, n);
	t2 = clock();
	temps = ( (double)(t2 - t1) / (double)CLOCKS_PER_SEC ) * (double) 1000;
	printf("\n(Iteratif)\n%f^%d = %f\nTemps d'execution : %f ms\n", a, n, res, temps);
	
	//récursif
	t1 = clock();
	res = puissanceRec(a, n);
	t2 = clock();
	temps = ( (double)(t2 - t1) / (double)CLOCKS_PER_SEC ) * (double) 1000;
	printf("\n(Recursif)\n%f^%d = %f\nTemps d'execution : %f ms\n", a, n, res, temps);

	return 0;
}

//	Cette fonction calcul la puissance d'un nombre "a" a la puissance "n" de manière itérative
//	Paramètre(s) :
//		a : nombre (Réel)
//		n : exposant (Entier)
//	Précondition(s) :
//		n >= 0
//	retourne : a^n

double puissanceIte(double a, int n) {
	
	double res = 1.0;

	if(n%2 == 0) {
		for(int i = n/2 ; i > 0 ; i--) {
			res *= a;
		}
		res = res * res;
	}
	else {
		for(int i = (n-1)/2 ; i > 0 ; i--) {
			res *= a;
		}
		res = a*res*res;
	}

	return res;
}


//	Cette fonction calcul la puissance d'un nombre "a" a la puissance "n" de manière récursif
//	Paramètre(s) :
//		a : nombre (Réel)
//		n : exposant (Entier)
//	Précondition(s) :
//		n >= 0
//	retourne : a^n

double puissanceRec(double a, int n) {

	double res;

	if(n == 0) {
		res = 1;
	}
	else if(n%2 == 0) {
		res = puissanceRec(a, n/2);
		res = res*res;
	}
	else {
		res = puissanceRec(a, (n-1)/2);
		res = a*res*res;
	}

	return res;
}
