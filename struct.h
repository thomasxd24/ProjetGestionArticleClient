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
	char adresse[50];
	Ensemble commandes;
} Client;


#endif /* EXAMPLE_H */