#include <iostream>
using namespace std;
int main() {
	int i, j;
	int *p1, *p2;

	i = 2;
	j = 5;
	p1 = &i;
	cout << "Contenu de p1 vaut :" << *p1<< endl; // Le contenu de p1 vaut 2
	i = i + 1; 
	p2 = p1;
	*p2 = *p1 + j;
	cout << "p1 vaut: " << *p1 << " et p2 vaut:" << *p2 << endl; // p1 vaut 8 et p2 vaut 8
	cout << "i vaut: " << i << " et j vaut:" << j<<endl; // i vaut 8 et j vaut 5
	p1 = &j;
	*p1 = i + j;
	cout << "p1 vaut: " << *p1 << " et p2 vaut:" << *p2 <<endl; // p1 vaut 13 et p2 vaut 8
	cout << "i vaut: " << i << " et j vaut: " << j<< endl; // i vaut 8 et j vaut 13
	system("pause");
	return 0;

}