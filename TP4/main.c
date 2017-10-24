#include <stdio.h>
#include <stdlib.h>

#include "File.h"

int main() {
	FileAttente* file = creerFile();
	
	int quitter = 0;
	int choix = 0;
	
	while(!quitter) {
		
		printf("\nFILE D'ATTENTE \n");
		printf("1) Ajouter une personne en queue\n");
		printf("2) Retirer la personne en tete\n");
		printf("3) Consulter la personne en tete de file\n");
		printf("4) Calculer la longueur de la file d'attente\n");
		printf("5) Undo\n");
		printf("6) Quitter\n");
		printf("\nSaisir votre choix : ");
		scanf("%d", &choix);
		
		switch(choix) {
			case 1:
				printf("\nSaisir le nom : ");
				char* nom = malloc(sizeof(char)*100);
				scanf("%s", nom);
				
				save(&file);
				ajouterEnQueue(file, nom);
				break;
			case 2:
				save(&file);
				retirerEnTete(file);
				break;
			case 3:
				if(longueurFile(*file) > 0)
					printf("\nTete de file : %s", consulterEnTete(*file));
				else
					printf("\nFile vide");
				break;
			case 4:
				printf("\nLongueur de la file : %d", longueurFile(*file));
				break;
			case 5:
				undo(&file);
				break;				
			case 6:
				supprimerFile(&file);
				quitter = 1;
				break;
			default:
				printf("\nErreur de saisie");
				break;
		}
		
		printf("\n\n");
	}
	
	return 0;
}