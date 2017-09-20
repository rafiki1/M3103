#include <stdio.h>

double puissance(double a, int n);

int main() {

  double a;
  int n;

  printf("Saisir a : ");
  scanf("%f", &a);

  printf("Saisir n : ");
  scanf("%d", &n);

  printf("%f", puissance(a, n));

  return 0;
}

// Cette fonction calcul la puissance d'un nombre "a" a la puissance "n"
// Paramètres : a (Réel)
//              n (Entier)
// Précondition : n >= 0
// retourne : a^n
/*
double puissance(double a, int n) {

  double res;

  if(n == 0) {
    res = 1;
  }
  else if(n%2 == 0) {
    res = puissance(a, n/2);
    res = res*res;
  }
  else {
    res = puissance(a, (n-1)/2);
    res = a*res*res;
  }

  return res;
}
*/
double puissance(double a, int n) {
  double res = 1;

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
