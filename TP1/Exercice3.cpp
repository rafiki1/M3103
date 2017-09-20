#include <iostream>
#include <time.h>
using namespace std;

int main() {

	int res,a,b;
	int pgcdRec(int a, int b);
	int pgcdIte(int a, int b);
	clock_t t1, t2;
	double temps;

	cout << "Saisir a (a>0) :" << endl;
	cin >> a;
	cout << "Saisir b (b>0) :" << endl;
	cin >> b;

	while (a <= 0 || b <= 0) {
		cout << "Saisir a (a>0) :" << endl;
		cin >> a;
		cout << "Saisir b (b>0) :" << endl;
		cin >> b;
	}
	t1 = clock();
	res = pgcdRec(a, b);
	t2 = clock();
	cout << "Le PGCD de " << a << " et " << b << " est :" << res << endl;
	temps = (float)(t2 - t1)/CLOCKS_PER_SEC*1000;
	printf("temps = %f\n", temps," ms");
	system("pause");
	return 0;
}



// Cette fonction permet de calculer le PGCD entre 2 nombres en mode récursive
// Paramètre : a: 1er entier , b=2ème entier 
// Précondition : a>0
//				  b>0
// Retourne pgcd(a,b)

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


// Cette fonction permet de calculer le PGCD entre 2 nombres en mode itératif
// Paramètre : a: 1er entier , b=2ème entier 
// Précondition : a>0
//				  b>0
// Retourne pgcd(a,b)

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