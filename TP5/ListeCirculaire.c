#include <stdio.h>
#include <stdlib.h>
#include "ListeCirculaire.h"

// Cette fonction créé une nouvelle ListeCirculaire
// retourne nouvelle ListeCirculaire
ListeCirculaire creerListe() {
	return NULL;
}

// Cette fonction détruit une ListeCirculaire
// paramètres :
//		pListe : pointeur sur la liste circulaire
void detruireListe(ListeCirculaire* pListe) {
	while(*pListe != NULL) {
		supprimerDernier(pListe);
	}
}

// Cette procédure permet d'afficher une liste circulaire
// Paramètres : 
//		liste : la liste a afficher
void afficher(ListeCirculaire liste) {
	
	if(liste == NULL) {
		printf("La liste est vide\n");
		return;
	}
	
	Maillon* debut = liste;
	
	do {
		printf("%d\n", (*liste).numero);
		rotation(&liste);
	} while(liste != debut);
}

// Cette procédure effectue une rotation d'une liste circulaire
// paramètres :
//		pListe : pointeur sur la liste circulaire
void rotation(ListeCirculaire* pListe) {
	
	if(*pListe != NULL) {
		*pListe = (*(*(pListe))).suivant;
	}
}

// Cette procédure insert une valeur dans une liste circulaire
// paramètres :
//		pListe : pointeur sur la liste circulaire
//		numero : valeur a inserer
void inserer(ListeCirculaire* pListe, int numero) {
	
	Maillon* dernier(ListeCirculaire pListe);
	
	Maillon* nouvMaillon = malloc(sizeof(Maillon));
	
	(*nouvMaillon).numero = numero;
	
	if(*pListe == NULL) {
		(*nouvMaillon).suivant = nouvMaillon;
	}
	else {
		(*nouvMaillon).suivant = *pListe;
		
		Maillon* dernierMaillon = dernier(*pListe);
		(*dernierMaillon).suivant = nouvMaillon;
	}
	
	*pListe = nouvMaillon;
}

// Cette procédure supprime le dernier element d'une liste circulaire
// paramètres :
//		pListe : pointeur sur la liste circulaire
void supprimerDernier(ListeCirculaire* pListe) {
	
	if(*pListe == NULL) {
		return;
	}
	
	Maillon* avantDernier(ListeCirculaire pListe);
	Maillon* dernier(ListeCirculaire pListe);
	
	Maillon* dernierMaillon = dernier(*pListe);
	
	if(dernierMaillon == (Maillon*)(*pListe)) {
		free(*pListe);
		*pListe = NULL;
	}
	else {
		Maillon* avantDernierMaillon = avantDernier(*pListe);
		
		(*avantDernierMaillon).suivant = *pListe;
		free(dernierMaillon);
	}
}

// Cette fonction retourne la taille d'une liste circulaire
// Paramètres : 
//		liste : la liste a afficher
int taille(ListeCirculaire liste) {
	
	if(liste == NULL) {
		return 0;
	}
	
	Maillon* debut = liste;
	int i = 0;
	
	do {
		rotation(&liste);
		i++;
	} while(liste != debut);
	
	return i;
}

// Cette fonction retourne un pointeur vers l'avant dernier maillon de la chaine
// Cette fonction est interne au module
//	paramètres :
//		liste : la liste
// préconditions :
//		liste non null
// retourne : le pointeur de l'avant dernier maillon
Maillon* avantDernier(ListeCirculaire liste) {
	
	Maillon* avatDernierMaillon;
	Maillon* debut = liste;
	
	do {
		avatDernierMaillon = liste;
		rotation(&liste);
	} while((*liste).suivant != debut);
	
	rotation(&liste);
	
	return avatDernierMaillon;
}

// Cette fonction retourne un pointeur vers le dernier maillon de la chaine
// Cette fonction est interne au module
//	paramètres :
//		liste : la liste
// préconditions :
//		liste non null
// retourne : le pointeur du dernier maillon
Maillon* dernier(ListeCirculaire liste) {
	
	Maillon* dernierMaillon;
	Maillon* debut = liste;
	
	do {
		dernierMaillon = liste;
		rotation(&liste);
	} while(liste != debut);
	
	return dernierMaillon;
}
