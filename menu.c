#include "menu.h"

void afficheMenuArticle(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tMenu Article\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1. Affichage la liste des article\t\t┃\n");
    printf("┃\t2. Trier les article\t\t\t\t┃\n");
    printf("┃\t3. Adjouter un article\t\t\t\t┃\n");
    printf("┃\t4. Enlever un article\t\t\t\t┃\n");
    printf("┃\t5. Modifier un article\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void afficheMenuClient(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tMenu Client\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1. Affichage la liste des client\t\t┃\n");
    printf("┃\t2. Trier les client\t\t\t\t┃\n");
    printf("┃\t3. Adjouter un client\t\t\t\t┃\n");
    printf("┃\t4. Enlever un client\t\t\t\t┃\n");
    printf("┃\t5. Modifier un client\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

int afficheMenuPrinciple(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\tGestion des Client et Article et Commande\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t\t1. Article\t\t\t\t┃\n");
    printf("┃\t\t2. Client\t\t\t\t┃\n");
    printf("┃\t\t3. Commande\t\t\t\t┃\n");
    printf("┃\t\t4. Reapprovisonnement\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    return 10;
}

int choixMenu(void)
{
    int n;
    printf("\n Option choisie : ");
    scanf("%d%*c", &n);
    return n;
}

void menuClient(Client tabClient[],int *nbClient)
{
    int choix;
    afficheMenuClient();
    choix = choixMenu();
    if (choix == 10)
        return;
    switch (choix)
    {
    case 1:
            afficherTabClient(tabClient,*nbClient);
            printf("Press ENTER key to Continue\n");  
            getchar();
            break;


        case 3:
            triDicoClient(tabClient,*nbClient,0);
            *nbClient=adjouterClient(tabClient,*nbClient);
            printf("Press ENTER key to Continue\n");  
            getchar();
            break;

        case 4:
            
            *nbClient=supprimeClient(tabClient,*nbClient);
            triDicoClient(tabClient,*nbClient,1);
            printf("Press ENTER key to Continue\n");  
            getchar();
            break;

        

        case 10:
            break;

        default:
            printf("Mauvais saisi");
            break;
    }
    menuClient(tabClient,nbClient);
}

void menuArticle(Article * tabArt[], int *tailleArt)
{
    int choix;
    while (choix != 10)
    {
        afficheMenuArticle();
        choix = choixMenu();
        system("clear");
        switch (choix)
        {
        case 1:
            afficherTabArticle(tabArt,*tailleArt);
            printf("Press ENTER key to Continue\n");  
            getchar();
            break;


        case 3:
            triDicoArticle(tabArt,*tailleArt,2);
            *tailleArt=adjouterArticle(tabArt,*tailleArt);
            printf("Press ENTER key to Continue\n");  
            getchar();
            break;

        case 4:
            triDicoArticle(tabArt,*tailleArt,2);
            *tailleArt=supprimeArticle(tabArt,*tailleArt);
            printf("Press ENTER key to Continue\n");  
            getchar();
            break;

        

        case 10:
            break;

        default:
            printf("Mauvais saisi");
            break;
        }
    }
}

void menuPrinciple(Article * tabArt[], int *tailleArt,Client tabClient[],int *nbClient)
{
    int choix;
    while (choix != 10)
    {
        afficheMenuPrinciple();
        choix = choixMenu();
        switch (choix)
        {
        case 1:
            menuArticle(tabArt,tailleArt);
            break;

        case 2:
            menuClient(tabClient,nbClient);
            break;

        case 10:
            break;

        default:
            break;
        }
    }
}
/*-------------------------------------------- Menu (v2) --------------------------------------------------------*/
