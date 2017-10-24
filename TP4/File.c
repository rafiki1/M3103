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
	return (*(file.tete)).nom;
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
void viderFile(FileAttente* file) {
	while((*file).tete != NULL) {
		retirerEnTete(file);
	}
}

//creer une nouvelle file
FileAttente* creerFile() {
	FileAttente* nouvFile = malloc(sizeof(FileAttente));
	(*nouvFile).tete = NULL;
	(*nouvFile).queue = NULL;
	(*nouvFile).precedent = NULL;
	
	return nouvFile;
}

//supprimer la file et toutes ses précédentes
void supprimerFile(FileAttente** file) {
	while((*(*file)).precedent!=NULL) {
		undo(file);
	}
	viderFile(*file);
	free(*file);
}

//sauvegarder la file actuelle
void save(FileAttente** file) {
	
	FileAttente* copieFile(FileAttente* f);
	
	FileAttente* nouvFile = copieFile(*file);
	
	(*nouvFile).precedent = *file;
	
	*file = nouvFile;
}

//revient a la dernière sauvegarde
void undo(FileAttente** file) {
	if((*(*file)).precedent==NULL) {
		printf("rien a annuler");
		return;
	}
	
	FileAttente* tmp = *file;
	*file = (*(*file)).precedent;
	
	viderFile(tmp);
	free(tmp);
}

//copie d'une FileAttente (utile uniquement a l'interieur du module)
FileAttente* copieFile(FileAttente* f) {
	
	Maillon* copieMaillon(Maillon* m);
	
	FileAttente* nouvFile = creerFile();
	
	if((*f).precedent == NULL)
		return nouvFile;
	
	Maillon* nouvMaillon;
	Maillon* tmp = (*f).tete;
	
	nouvMaillon = copieMaillon(tmp);
	(*nouvFile).tete = nouvMaillon;
	
	while((*tmp).suivant != NULL) {
		tmp = (*tmp).suivant;
		
		(*nouvMaillon).suivant = copieMaillon(tmp);
		nouvMaillon = (*nouvMaillon).suivant;
	}
	
	(*nouvFile).queue = nouvMaillon;
	
	return nouvFile;
}

//copie d'un Maillon (utile uniquement a l'interieur du module)
Maillon* copieMaillon(Maillon* m) {
	
	if(m == NULL)
		return NULL;
	
	Maillon* nouvMaillon = malloc(sizeof(Maillon));
	
	(*nouvMaillon).nom = malloc(sizeof(char)*100);
	int i = 0;
	while((*m).nom[i] != '\0') {
		(*nouvMaillon).nom[i] = (*m).nom[i];
		i++;
	}
	(*nouvMaillon).nom[i] = '\0';
	
	(*nouvMaillon).suivant = (*m).suivant;
	
	return nouvMaillon;
}
