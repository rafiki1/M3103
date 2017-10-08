#ifndef FILE_H
#define FILE_H
	
	typedef struct Maillon Maillon;
	struct Maillon {
		int numero;
		Maillon* suivant;
	};
	
	typedef struct FileAttente FileAttente;
	struct FileAttente {
		Maillon* tete;
		Maillon* queue;
	};
	
	void ajouterEnQueue(FileAttente* file, int numPersonne);
	void retirerEnTete(FileAttente* file);
	int consulterEnTete(FileAttente file);
	int longueurFile(FileAttente file);
	
#endif