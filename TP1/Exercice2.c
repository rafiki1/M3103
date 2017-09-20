#include <stdio.h>
#include "time.h"

double puissance(double a, int n);

int main() {

  double a;
  int n;

  printf("Saisir a : ");
  scanf("%lf", &a);

  do {
    printf("Saisir n >= 0 : ");
    scanf("%d", &n);
  } while(n < 0);

  clock_t t1 = clock();
  double res = puissance(a, n);
  clock_t t2 = clock();

  printf("%f\n", res);
  printf("%f ms\n", ((double)t2-t1)/CLOCKS_PER_SEC*1000);

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
