#include <iostream>
using namespace std;

int main() {

	int res,a,b;
	int pgcd(int a, int b);

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
	res = pgcd(a, b);
	cout << "Le PGCD de " << a << " et " << b << " est :" << res << endl;
	system("pause");
	return 0;
}



// Cette fonction permet de calculer le PGCD entre 2 nombres
// Paramètre : a: 1er entier , b=2ème entier 
// Précondition : a>0
//				  b>0
// Retourne pgcd(a,b)

int pgcd(int a, int b) {

	if (a == b) {
		return a;
	}
	else {
		if (a > b) {
			return pgcd(a - b, b);
		}
		else {
			return pgcd(a, b - a);
		}
	}
}
