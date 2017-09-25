 #include <iostream>
#include <time.h>

using namespace std;
int main() {

	int n;
	int res;
	int sommeNPremierRec(int n);
	int sommeNPremierIte(int n);
	clock_t t1, t2;
	double temps;

	cout << "Saisir entier :" << endl;
	cin >> n;
	while (n <= 0) {
		cout << "Saisir entier positif  :" << endl;
		cin >> n;
	}
	t1 = clock();
	res = sommeNPremierIte(n);
	t2 = clock();
	cout <<"La somme des n premiers entier de "<<n<<" vaut :"<<res << endl;
	temps = (float)(t2 - t1) / CLOCKS_PER_SEC * 1000;
	printf("temps = %f\n", temps, " ms");
	system("pause");
}



// Cette fonction calcul la somme des n premiers entier avec la récursivité          
// Paramètre n: entier positif ou nul												 
// Précondition : n>=0																 
// retourne n premer entier


int sommeNPremierRec(int n) {
	
	if (n == 0) {
		return 0;
	}
	else {
		return n + sommeNPremierRec(n - 1);

	}

}


// Cette fonction calcul la somme des n premiers entier en itération       
// Paramètre n: entier positif ou nul												 
// Précondition : n>=0																 
// retourne n premer entier

int sommeNPremierIte(int n) {
	
	int i;
	int res=0;
	for (i = 1; i <= n; i++)
	{
		res = res+ i;
	}
	return res;
}
