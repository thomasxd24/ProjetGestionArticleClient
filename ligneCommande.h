#ifndef SOME_HEADER_GUARD_WITHh_UNIQUE_NAME
#define SOME_HEADER_GUARD_WITHh_UNIQUE_NAME
#include"article.h"
typedef struct 
{
    int idCommande;
    Article* artCommande;
    int quantite;
} LigneCommande;

typedef struct Maillon{
	LigneCommande v;
	struct Maillon * suiv;
}Maillon;

typedef Maillon *Ensemble;

typedef enum {faux,vrai}Booleen;
#endif /* EXAMPLE_H */