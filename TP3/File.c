#include <stdio.h>
#include <stdlib.h>
#include "File.h"

void ajouterEnQueue(FileAttente* file, int numPersonne) {
	
	Maillon* nouveauMaillon = malloc(sizeof(Maillon));
	nouveauMaillon->numero = numPersonne;
	nouveauMaillon->suivant = NULL;
	
	if(file->tete == NULL)
		file->tete = nouveauMaillon;
	else
		file->queue->suivant = nouveauMaillon;
	
	printf("%d", file->tete->numero);
	
	file->queue = nouveauMaillon;
}

void retirerEnTete(FileAttente* file) {
	if(file->tete==NULL)
		return;
	
	Maillon* tmp = file->tete;
	file->tete=tmp->suivant;
	free(tmp);
}

int consulterEnTete(FileAttente file) {
	return file.tete->numero;
}

int longueurFile(FileAttente file) {
	
	int compteur = 0;
	Maillon* tmp = file.tete;
	
	while(tmp != NULL) {
		tmp = tmp->suivant;
		compteur++;
	}
	
	return compteur;
}