#include <iostream>

using namespace std;

int main() {
	int i, j;
	int *p1, *p2;

	i = 2;
	j = 5;
	
	p1 = &i; // la valeur de p1 est l'adresse de i
	cout << endl << "Contenu de p1 vaut : " << *p1 << endl; // Le contenu de p1 vaut 2
	
	i = i + 1;
	cout << "Contenu de p1 vaut : " << *p1 << endl; // Le contenu de p1 vaut 3
	
	p2 = p1; // la valeur de p1 est la valeur de p1 (l'adresse de i)
	*p2 = *p1 + j; // Le contenu de p2 (i) prend la valeur du contenu de p1(i) + j
	cout << endl << "*p1 = " << *p1 << "    *p2 = " << *p2 << endl; // *p1 = 8   et   *p2 = 8
	cout << "i   = " << i  << "    j   = "  << j << endl; // i = 8   et   j = 5
	
	p1 = &j; // la valeur de p1 est maintenant l'adresse de j
	*p1 = i + j; // Le contenu de p1 (j) prend la valeur de i+j 
	cout << endl << "*p1 = " << *p1 << "   *p2 = " << *p2 << endl; // *p1 = 13   et   *p2 = 8
	cout << "i   = " << i  << "    j   = "  << j << endl;	 // i = 8   et   j = 13
	
	return 0;
}
