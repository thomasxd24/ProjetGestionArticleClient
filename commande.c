#include"commande.h"

void saisirCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    char nomClient[50];
    Article * commandeArt;
    LigneCommande commandeEnAttente;
    int idArt,quantite,i,posArt,posClient,trouve,reste;
    printf("Entrer le nom du client:");
    scanf("%s",nomClient);
    triDicoClient(tabClient,nbClient,2);
    posClient = rechercherDicoClient(nomClient,tabClient,nbClient,&trouve,-1);
    if(!trouve)
    {
        printf("Client non trouvée. Abandon.\n");
        return;
    }
    trouve=0;
    while(!trouve){
        printf("Entrer l'identifiant de l'article:");
    scanf("%d",&idArt);
    posArt = rechercherDicoArticle('\0',tabArt,nbArt,&trouve,idArt);
    if(!trouve)
        printf("Article non trouvée. Retaper;\n");
    }
    commandeArt=tabArt[posArt];
    printf("Entrer la quantité de l'article demandée:");
    scanf("%d",&quantite);
    reste=commandeArt->quantite-quantite;
    if(reste<0)
    {
        commandeArt->quantite=0;
        reste=reste*-1;
        commandeEnAttente.quantite=reste;
        commandeEnAttente.article=commandeArt;
        commandeEnAttente.idCommande=rand()%100;
        commandeEnAttente.idClient=tabClient[posClient].idClient;
        tabClient[posClient].commandes=ajouterCommande(tabClient[posClient].commandes,commandeEnAttente);
        printf("Insuffisante de stock pour ce article.\n");
        printf("Vidé le stock de l'article (%d en stock)\n",quantite-reste);
        printf("Mis en attente le reste (%d en attente)",reste);
        printf("Il porte la commande numéro %d\n",commandeEnAttente.idCommande);
    }
    else if (reste>=0)
    {
        commandeArt->quantite=reste;
        printf("Commande Client réussi. %d de %s commandé, il sera pret dans les 2 jours\n",quantite,commandeArt->designation);
    }
    
    
    

    
    
        

}