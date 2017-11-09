#include <stdio.h>
#include <stdlib.h>

#include "Arbre.h"

//Cette fonction initialise un arbre et le retourne
//retourne : un arbre initialisé
Abin init() {
	return NULL;
}

//Cette Procédure libère un arbre et tout ses sous arbre de la mémoire
//paramètres : 
//		a : l'arbre
//préconditions : non estVide(a)
//postcondition : non estVide(a) (Mémoire libérée mais pointeur non NULL)
void desinit(Abin a) {
	if(!estVide(gauche(a)))
		desinit(gauche(a));
	
	if(!estVide(droite(a)))
		desinit(droite(a));
	
	free(a);
}

//Cette fonction retourne un nouvel arbre après lui avoir attribué une étiquette, un arbre gauche et un arbre droit
//paramètre :
//	e : l'étiquette
//	ag : l'arbre gauche
//	ad : l'arbre droit
//retourne : le nouvel arbre
Abin enracine(Elt e, Abin ag, Abin ad) {
	Abin arbre = malloc(sizeof(Noeud));
	
	(*arbre).etiquette = e;
	(*arbre).ag = ag;
	(*arbre).ad = ad;
	
	return arbre;
}

//Cette fonction retourne l'arbre gauche d'un arbre a
//paramètres :
//	a : un arbre
//préconditions : non estVide(a)
//retourne : l'arbre gauche de a

Abin gauche(Abin a) {
	return (*a).ag;
}

//Cette fonction retourne l'arbre droit d'un arbre a
//paramètres :
//	a : un arbre
//préconditions : non estVide(a)
//retourne : l'arbre droit de a

Abin droite(Abin a) {
	return (*a).ad;
}

//Cette fonction détermine si un arbre est vide ou non
//paramètre :
//		a : l'arbre
//retourne : 1 (VRAI) si a est vide  OU  0 (FAUX) si a n'est pas vide

int estVide(Abin a) {
	return a == NULL;
}

//Cette fonction calcul la hauteur d'un arbre
//paramètre
//		a : l'arbre
//préconditions : non estVide(a)
//retourne : la hauteur de a
int hauteur(Abin a) {
	int hg, hd;
	
	if(!estVide(gauche(a))) {
		hg = hauteur(gauche(a)) + 1;
	}
	else {
		hg = 0;
	}
	
	if(!estVide(droite(a))) {
		hd = hauteur(droite(a)) + 1;
	}
	else {
		hd = 0;
	}
	
	if(hg >= hd)
		return hg;
	else
		return hd;
}

//Cette fonction renvoie la racine d'un arbre abort
//paramètre
//		a : l'arbre
//préconditions : non estVide(a)
Elt racine(Abin a) {
	return (*a).etiquette;
}

//Cette Procédure parcour en largeur avec affichage un arbre a
//paramètre :
//		a : l'arbre
//préconditions : non estVide(a)
void parcourLargeur(Abin a) {
	int h = hauteur(a);
	
	printf("%c", racine(a));
	
	for(int i = 1 ; i <= h ; i++) {
		afficherLigne(a, i);
	}
}

//Cette Procédure parcour en profondeur préfixe avec affichage un arbre a
//paramètre :
//		a : l'arbre
//préconditions : non estVide(a)
void parcourProfondeurPrefixe(Abin a) {
	
	printf("%c", racine(a));
	
	if(!estVide(gauche(a)))
		parcourProfondeurPrefixe(gauche(a));
	
	if(!estVide(droite(a)))
		parcourProfondeurPrefixe(droite(a));
}
	
//Cette Procédure parcour en profondeur infixe avec affichage un arbre a
//paramètre :
//		a : l'arbre
//préconditions : non estVide(a)
void parcourProfondeurInfixe(Abin a) {
	
	if(!estVide(gauche(a)))
		parcourProfondeurInfixe(gauche(a));
	
	printf("%c", racine(a));
	
	if(!estVide(droite(a)))
		parcourProfondeurInfixe(droite(a));
}

//Cette Procédure parcour en profondeur postfixe avec affichage un arbre a
//paramètre :
//		a : l'arbre
//préconditions : non estVide(a)
void parcourProfondeurPostfixe(Abin a) {
	if(!estVide(gauche(a)))
		parcourProfondeurPostfixe(gauche(a));
	
	if(!estVide(droite(a)))
		parcourProfondeurPostfixe(droite(a));
	
	printf("%c", racine(a));
}

//Cette Procédure affiche une ligne d'un arbre
//paramètre :
//		a : l'arbre
//		numLigne : le numéro de la ligne a afficher
//préconditions : non estVide(a)
void afficherLigne(Abin a, int numLigne) {
	
	if(numLigne == 0) {
		printf("%c", racine(a));
	}
	else {
		if(!estVide(gauche(a)))
			afficherLigne(gauche(a), numLigne - 1);
		
		if(!estVide(droite(a)))
			afficherLigne(droite(a), numLigne - 1);
	}
}
