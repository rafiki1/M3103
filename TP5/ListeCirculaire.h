#ifndef LISTE_CIRCULAIRE_H
#define LISTE_CIRCULAIRE_H

	typedef struct Maillon Maillon;
	struct Maillon {
		int numero;
		Maillon* suivant;
	};
	
	typedef Maillon* ListeCirculaire;
	
	// Cette fonction créé une nouvelle ListeCirculaire
	// retourne : nouvelle ListeCirculaire
	ListeCirculaire creerListe();
	
	// Cette fonction détruit une ListeCirculaire
	// paramètres :
	//		pListe : pointeur sur la liste circulaire
	void detruireListe(ListeCirculaire* pListe);
	
	// Cette procédure permet d'afficher une liste circulaire
	// Paramètres : 
	//		liste : la liste a afficher
	void afficher(ListeCirculaire liste);
	
	// Cette procédure effectue une rotation d'une liste circulaire
	// paramètres :
	//		pListe : pointeur sur la liste circulaire	
	void rotation(ListeCirculaire* pListe);
	
	// Cette procédure insert une valeur dans une liste circulaire
	// paramètres :
	//		pListe : pointeur sur la liste circulaire
	//		numero : valeur a inserer
	void inserer(ListeCirculaire* pListe, int numero);
	
	// Cette procédure supprime le dernier element d'une liste circulaire
	// paramètres :
	//		pListe : pointeur sur la liste circulaire	
	void supprimerDernier(ListeCirculaire* pListe);
	
	// Cette fonction retourne la taille d'une liste circulaire
	// Paramètres : 
	//		liste : la liste
	// retourne : le nombre de maillons de la liste
	int taille(ListeCirculaire liste);
	
#endif