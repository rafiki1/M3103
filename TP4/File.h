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
		
		FileAttente* precedent;
	};
	
	void ajouterEnQueue(FileAttente* file, char* nom);
	void retirerEnTete(FileAttente* file);
	char* consulterEnTete(FileAttente file);
	int longueurFile(FileAttente file);
	void viderFile(FileAttente* file);
	
	void save(FileAttente** file);
	void undo(FileAttente** file);
	
	FileAttente* creerFile();
	void supprimerFile(FileAttente** file);
	
#endif