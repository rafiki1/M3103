#include <stdio.h>
#include <stdlib.h>
#include "File.h"

//Cette procédure permet d'ajouter une personne à la queue  de la file d'attente
//Paramètres :
//		file : la file d'attente
//		nom : le nom de la personne
void ajouterEnQueue(FileAttente* file, char* nom) {
	
	Maillon* nouveauMaillon = malloc(sizeof(Maillon));
	(*nouveauMaillon).nom = nom;
	(*nouveauMaillon).suivant = NULL;
	
	if((*file).tete == NULL)
		(*file).tete = nouveauMaillon;
	else
		(*((*file).queue)).suivant = nouveauMaillon;
	
	(*file).queue = nouveauMaillon;
}

//Cette procédure permet de retirer la personne en tete de la file d'attente
//Paramètres :
//		file : la file d'attente
void retirerEnTete(FileAttente* file) {
	if((*file).tete==NULL)
		return;
	
	Maillon* tmp = (*file).tete;
	(*file).tete=(*tmp).suivant;
	free((*tmp).nom);
	free(tmp);
}

//Cette fonction retourne le nom de la personne en tete de la file d'attente
//Paramètre :
//		file : la file d'attente
//retourne : le nom dela personne en tete
char* consulterEnTete(FileAttente file) {
	return (*((*file).tete)).nom;
}

//Cette fonction retourne le nombre de personne dans la file d'attente
//Paramètres :
//		file : file d'attente
//retourne : le nombre de personne dans la file d'attente
int longueurFile(FileAttente file) {
	
	int compteur = 0;
	Maillon* tmp = file.tete;
	
	while(tmp != NULL) {
		tmp = (*tmp).suivant;
		compteur++;
	}
	
	return compteur;
}

//Cette procédure retire toutes les personne
//Paramètres : 
//		file : la file d'attente
void vider(FileAttente* file) {
	while((*file).tete != NULL) {
		retirerEnTete((*file).tete);
	}
}
