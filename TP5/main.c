#include <stdio.h>
#include "ListeCirculaire.h"

#define TRUE 1
#define FALSE 0

typedef int boolean;

int main() {
	
	ListeCirculaire liste = creerListe();
	
	int choix;
	boolean quitter = FALSE;
	
	do {
		printf("\n1) inserer une valeur\n");
		printf("2) afficher la liste\n");
		printf("3) rotation de la liste\n");
		printf("4) taille de la liste\n");
		printf("5) supprimer le dernier element\n");
		printf("6) quitter\n\n");
		
		printf("choix : ");
		scanf("%d", &choix);
		
		switch(choix) {
			case 1: {
				int num;
				printf("Saisir la valeur a inserer : ");
				scanf("%d", &num);
				
				inserer(&liste, num);
			} break;
			case 2:
				afficher(liste);
				break;
			case 3:
				rotation(&liste);
				break;
			case 4: {
				int tailleListe = taille(liste);
				
				if(tailleListe == 0) {
					printf("\nLa liste est vide\n");
				}
				else {
					printf("\nLa liste contient %d elements\n", tailleListe);
				}
			} break;
			case 5:
				supprimerDernier(&liste);
				break;
			case 6:
				detruireListe(&liste);
				quitter = TRUE;
				break;
			default:
				printf("Erreur de saisie");
		}
		
	} while(!quitter);
	
	return 0;
}
