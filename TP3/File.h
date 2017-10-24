#ifndef FILE_H
#define FILE_H
	
	typedef struct Maillon Maillon;
	struct Maillon {
		char* nom;
		Maillon* suivant;
	};
	
	typedef struct FileAttente FileAttente;
	struct FileAttente {
		Maillon* tete;
		Maillon* queue;
	};
	
	//Cette procédure permet d'ajouter une personne à la queue  de la file d'attente
	//Paramètres :
	//		file : la file d'attente
	//		nom : le nom de la personne
	void ajouterEnQueue(FileAttente* file, char* nom);
	
	//Cette procédure permet de retirer la personne en tete de la file d'attente
	//Paramètres :
	//		file : la file d'attente
	void retirerEnTete(FileAttente* file);
	
	//Cette fonction retourne le nom de la personne en tete de la file d'attente
	//Paramètre :
	//		file : la file d'attente
	//retourne : le nom dela personne en tete
	char* consulterEnTete(FileAttente file);
	
	//Cette fonction retourne le nombre de personne dans la file d'attente
	//Paramètres :
	//		file : file d'attente
	//retourne : le nombre de personne dans la file d'attente
	int longueurFile(FileAttente file);
	
	//Cette procédure retire toutes les personne
	//Paramètres : 
	//		file : la file d'attente
	void vider(FileAttente* file);
	
#endif