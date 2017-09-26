#include <iostream>
using namespace std;
int main() {
	int i, j;
	int *p1, *p2;

	i = 2;
	j = 5;
	p1 = &i; // Le pointeur p1 pointe vers l'adresse de i
	cout << "Contenu de p1 vaut :" << *p1<< endl; // Le contenu de p1 vaut 2
	i = i + 1; 
	p2 = p1; // Le poiteur p2 pointe vers le contenu du pointeur 1 (L'adresse de i)
	*p2 = *p1 + j; // Le contenu de p2 (i) prend la valeur du contenu de p1(i) + j
	cout << "p1 vaut: " << *p1 << " et p2 vaut:" << *p2 << endl; // p1 vaut 8 et p2 vaut 8
	cout << "i vaut: " << i << " et j vaut:" << j<<endl; // i vaut 8 et j vaut 5
	p1 = &j; // Le pointeur p1 pointe maintenant vers l'adresse de j
	*p1 = i + j; // Le contenu de p1 (j) prend la valeur de i+j 
	cout << "p1 vaut: " << *p1 << " et p2 vaut:" << *p2 <<endl; // p1 vaut 13 et p2 vaut 8
	cout << "i vaut: " << i << " et j vaut: " << j<< endl; // i vaut 8 et j vaut 13
	system("pause");
	return 0;

}
