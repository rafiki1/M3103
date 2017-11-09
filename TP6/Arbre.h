#ifndef ARBRE_H
#define ARBRE_H
	
	typedef char Elt;
	
	typedef struct Noeud Noeud;
	
	struct Noeud {
		Elt etiquette;
		Noeud* ag;
		Noeud* ad;
	};
	
	typedef Noeud* Abin;
	
	//Cette fonction initialise un arbre et le retourne
	//retourne : un arbre initialisé
	Abin init();
	
	//Cette Procédure libère un arbre et tout ses sous arbre de la mémoire
	//paramètres : 
	//		a : l'arbre
	//préconditions : non estVide(a)
	//postcondition : non estVide(a) (Mémoire libérée mais pointeur non NULL)
	void desinit(Abin a);
	
	//Cette fonction retourne un nouvel arbre après lui avoir attribué une étiquette, un arbre gauche et un arbre droit
	//paramètre :
	//	e : l'étiquette
	//	ag : l'arbre gauche
	//	ad : l'arbre droit
	//retourne : le nouvel arbre
	Abin enracine(Elt e, Abin ag, Abin ad);
	
	//Cette fonction retourne l'arbre gauche d'un arbre a
	//paramètres :
	//	a : un arbre
	//préconditions : non estVide(a)
	//retourne : l'arbre gauche de a
	Abin gauche(Abin a);
	
	//Cette fonction retourne l'arbre droit d'un arbre a
	//paramètres :
	//	a : un arbre
	//préconditions : non estVide(a)
	//retourne : l'arbre droit de a
	Abin droite(Abin a);
	
	//Cette fonction détermine si un arbre est vide ou non
	//paramètre :
	//		a : l'arbre
	//retourne : 1 (VRAI) si a est vide  OU  0 (FAUX) si a n'est pas vide
	int estVide(Abin a);
	
	//Cette fonction calcul la hauteur d'un arbre
	//paramètre
	//		a : l'arbre
	//préconditions : non estVide(a)
	//retourne : la hauteur de a
	int hauteur(Abin a);
	
	//Cette fonction renvoie la racine d'un arbre abort
	//paramètre
	//		a : l'arbre
	//préconditions : non estVide(a)
	Elt racine(Abin a);
	
	//Cette Procédure parcour en largeur avec affichage un arbre a
	//paramètre :
	//		a : l'arbre
	//préconditions : non estVide(a)
	void parcourLargeur(Abin a);
	
	//Cette Procédure parcour en profondeur préfixe avec affichage un arbre a
	//paramètre :
	//		a : l'arbre
	//préconditions : non estVide(a)
	void parcourProfondeurPrefixe(Abin a);
	
	//Cette Procédure parcour en profondeur infixe avec affichage un arbre a
	//paramètre :
	//		a : l'arbre
	//préconditions : non estVide(a)
	void parcourProfondeurInfixe(Abin a);
	
	//Cette Procédure parcour en profondeur postfixe avec affichage un arbre a
	//paramètre :
	//		a : l'arbre
	//préconditions : non estVide(a)
	void parcourProfondeurPostfixe(Abin a);
	
	//Cette Procédure affiche une ligne d'un arbre
	//paramètre :
	//		a : l'arbre
	//		numLigne : le numéro de la ligne a afficher
	//préconditions : non estVide(a)
	void afficherLigne(Abin a, int numLigne);
	
#endif