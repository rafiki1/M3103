 #include <iostream>
/*
using namespace std;
int main() {

	int n;
	int res;
	int sommeNPremierRec(int n);
	int sommeNPremierIte(int n);

	cout << "Saisir entier :" << endl;
	cin >> n;
	while (n <= 0) {
		cout << "Saisir entier positif  :" << endl;
		cin >> n;
	}
	res = sommeNPremierIte(n);

	cout <<"La somme des n premiers entier de "<<n<<" vaut :"<<res << endl;
	
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
*/