#ifndef STRUCTDEF
#define STRUCTDEF

/*-------------------------------------------------- Structure Article -----------------------------------*/

typedef struct{
	int idarticle;
	float prixunitaire;
	int quantite;
    char designation[50];
} Article;	

/*-------------------------------------------------- Structure LigneCommande -------------------------------*/
typedef struct 
{
    int idCommande;
    Article* article;
    int idClient;
    int quantite;
} LigneCommande;

typedef struct maillon{
	LigneCommande v;
	struct maillon * suiv;
}Maillon;

typedef Maillon *Ensemble;

typedef enum {faux,vrai}Booleen;

/*-------------------------------------------------- Structure Client ---------------------------------------*/
typedef struct{
	int idClient;
	char civilite[5];
	char nom[10];
	char prenom[10];
	char adresse[70];
	Ensemble commandesEnAttente;
	Ensemble commandesEnCours;
} Client;

extern char nomFichArt[50];
extern char nomFichClient[50];
extern char nomFichCommande[50];
extern char nomFichLivraison[50];


#endif /* EXAMPLE_H */