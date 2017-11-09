#include <stdio.h>
#include <stdlib.h>

#include "Arbre.h"

int main() {
	
	void test(int condition);
	
	//démonstration de la procédure test :
	printf("\nPour test(1) : ");
	test(1);
	printf("\nPour test(0) : ");
	test(0);
	
	printf("\n");
	
	
	//initialisation d'un nouvel arbre
	Abin arbre = init();
	
	/*
		Construction de l'arbre suivant :
		
		    A
		   / \
		  B   C
		 / \
		D   E
		   /
		  F
		  
	*/
	
	arbre = enracine('A', enracine('B', enracine('D', NULL, NULL), enracine('E', enracine('F', NULL, NULL), NULL)), enracine('C', NULL, NULL));
	
	
	
	//test des fonctions racine, gauche et droite :
	printf("\n\nTest des fonctions racine, gauche, et droite : ");
	test(racine(gauche(arbre)) == 'B' && racine(droite(arbre)) == 'C');
	
	//test de la fonction estVide :
	printf("\n\nTest de la fonction estVide : ");
	test(!estVide(arbre) && estVide(gauche(droite(arbre))));
	
	//test de la fonction hauteur :
	printf("\n\nTest de la fonction hauteur : ");
	test(hauteur(arbre) == 3);
	
	printf("\n");
	
	
	//parcourLargeur
	printf("\nparcourLargeur : ");
	parcourLargeur(arbre);
	
	//parcourProfondeurPrefixe
	printf("\n\nparcourProfondeurPrefixe : ");
	parcourProfondeurPrefixe(arbre);
	
	//parcourProfondeurInfixe
	printf("\n\nparcourProfondeurInfixe : ");
	parcourProfondeurInfixe(arbre);
	
	//parcourProfondeurPostfixe
	printf("\n\nparcourProfondeurPostfixe : ");
	parcourProfondeurPostfixe(arbre);
	
	printf("\n");
	
	desinit(arbre);
	return 0;
}

void test(int condition) {
	printf("%s", condition ? "OK" : "ERREUR");
}