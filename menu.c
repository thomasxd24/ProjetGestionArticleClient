#include "menu.h"
#include <unistd.h>
#include <termios.h>

#define UN 49
#define DEUX 50
#define TROIS 51
#define QUATRE 52
#define CINQ 53
#define SIX 54
#define SEPT 55
#define HUIT 56

int getch(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
 }


int choixMenu(void)
{
    int n;
  n = getch();
    return n;
}

/*-------------------------------------------- Menu ---------------------------------------------------------*/

void afficheMenuPrinciple(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\tGestion des Clients et Articles et Commandes\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Article\t\t\t\t\t┃\n");
    printf("┃\t2.  Client\t\t\t\t\t┃\n");
    printf("┃\t3.  Commande\t\t\t\t\t┃\n");
    printf("┃\t4.  Réapprovisonnement\t\t\t\t┃\n");
    printf("┃\t5.  Sauvegarde / Restaurer\t\t\t┃\n");
    printf("┃\t0. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}



void menuPrinciple(Article *tabArt[], int *tailleArt, Client tabClient[], int *nbClient)
{
    int choix;
    while (choix != 48)
    {
afficheMenuPrinciple();
  choix = choixMenu();
        
        switch (choix)
        {
        case UN:
            menuArticle(tabArt, tailleArt);
            break;

        case DEUX:
            menuClient(tabClient, nbClient);
            break;
        
        case TROIS:
            menuCommande(tabClient, nbClient,tabArt,tailleArt);
            break;

        case QUATRE:
            menuReappro(tabClient, nbClient,tabArt,tailleArt);
            break;

        case CINQ:
            menuReglage(tabArt, tailleArt,tabClient,nbClient);
            break;

        case 48:
            break;

        default:
            break;
        }
    }
}

/*-------------------------------------------- Menu Article -------------------------------------------------*/

void afficheMenuArticle(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tMenu Article\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Afficher la liste des articles\t\t┃\n");
    printf("┃\t2.  Ajouter un article\t\t\t\t┃\n");
    printf("┃\t3.  Enlever un article\t\t\t\t┃\n");
    printf("┃\t4.  Modifier un article\t\t\t\t┃\n");
    printf("┃\t5.  Afficher les articles en rupture\t\t┃\n");
    printf("┃\t0. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void afficheMenuCommande(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tMenu Commande\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Saisir une commande client\t\t┃\n");
    printf("┃\t2.  Charger un commande a partir d'un fichier\t┃\n");
    printf("┃\t0. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void afficheMenuReappro(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tMenu Réapprovisonnement\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Saisir une livraison\t\t┃\n");
    printf("┃\t2.  Charger une livraison a partir d'un fichier\t┃\n");
    printf("┃\t0. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void afficheChoixTriArticle(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tAfficher Article\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Afficher par ID\t\t\t\t┃\n");
    printf("┃\t2.  Afficher par désignation\t\t\t┃\n");
    printf("┃\t3.  Afficher par prix\t\t\t\t┃\n");
    printf("┃\t4.  Afficher par quantité\t\t\t┃\n");
    printf("┃\t0. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void menuChoixTriArticle(Article *tabArticle[], int *nbArticle)
{
    int choix;
    while (choix != 48)
    {
        afficheChoixTriArticle();
        choix = choixMenu();
        system("clear");
        switch (choix)
        {
        case UN:
            triDicoArticle(tabArticle, *nbArticle, 1);
            afficherTabArticle(tabArticle, *nbArticle);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 48;
            break;

        case DEUX:
            triDicoArticle(tabArticle, *nbArticle, 2);
            afficherTabArticle(tabArticle, *nbArticle);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 48;
            break;

        case TROIS:
            triDicoArticle(tabArticle, *nbArticle, 3);
            afficherTabArticle(tabArticle, *nbArticle);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 48;
            break;

        case QUATRE:
            triDicoArticle(tabArticle, *nbArticle, 4);
            afficherTabArticle(tabArticle, *nbArticle);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 48;
            break;

        case 48:
            break;

        default:
            printf("Mauvaise saisie");
            break;
        }
    }
}

void menuArticle(Article *tabArt[], int *tailleArt)
{
    int choix;
    while (choix != 48)
    {
        afficheMenuArticle();
        choix = choixMenu();
        system("clear");
        switch (choix)
        {
        case UN:
            menuChoixTriArticle(tabArt, tailleArt);
            break;

        case DEUX:
            triDicoArticle(tabArt, *tailleArt, 2);
            *tailleArt = ajouterArticle(tabArt, *tailleArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            break;

        case TROIS:
            triDicoArticle(tabArt, *tailleArt, 2);
            *tailleArt = supprimeArticle(tabArt, *tailleArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            break;

        case CINQ:
            triDicoArticle(tabArt, *tailleArt, 1);
            afficherTabArticleRupture(tabArt, *tailleArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            break;

        case 48:
            break;

        default:
            printf("Mauvaise saisie");
            break;
        }
    }
}

/*-------------------------------------------- Menu Client --------------------------------------------------*/

void afficheMenuClient(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tMenu Client\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Afficher la liste des clients\t\t┃\n");
    printf("┃\t2.  Ajouter un client\t\t\t\t┃\n");
    printf("┃\t3.  Enlever un client\t\t\t\t┃\n");
    printf("┃\t4.  Consulter un client\t\t\t\t┃\n");
    printf("┃\t0. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void afficheChoixTriClient(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tAfficher Client\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Afficher par ID\t\t\t\t┃\n");
    printf("┃\t2.  Afficher par nom\t\t\t\t┃\n");
    printf("┃\t3.  Afficher par prénom\t\t\t\t┃\n");
    printf("┃\t4.  Afficher par adresse\t\t\t┃\n");
    printf("┃\t0. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void menuChoixTriClient(Client tabClient[], int *nbClient)
{
    int choix;
    while (choix != 48)
    {
        afficheChoixTriClient();
        choix = choixMenu();
        system("clear");
        switch (choix)
        {
        case UN:
            triDicoClient(tabClient, *nbClient, 1);
            afficherTabClient(tabClient, *nbClient);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 48;
            break;

        case DEUX:
            triDicoClient(tabClient, *nbClient, 2);
            afficherTabClient(tabClient, *nbClient);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 48;
            break;

        case TROIS:
            triDicoClient(tabClient, *nbClient, 3);
            afficherTabClient(tabClient, *nbClient);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 48;
            break;


        case 48:
            break;

        default:
            printf("Mauvaise saisie");
            break;
        }
    }
}

void menuClient(Client tabClient[], int *nbClient)
{
    int choix;
    afficheMenuClient();
    choix = choixMenu();
    if (choix == 48)
        return;
    switch (choix)
    {
    case UN:
        menuChoixTriClient(tabClient, nbClient);
        break;

    case DEUX:
        tabClient = ajouterClient(tabClient, nbClient);
        triDicoClient(tabClient, *nbClient, 1);
        printf("Appuyer sur une touche pour afficher les changements...\n");
        getchar();
        afficherTabClient(tabClient, *nbClient);
        printf("Appuyer sur une touche pour continuer...\n");
        getchar();
        break;

    case TROIS:
        triDicoClient(tabClient, *nbClient, 1);
        *nbClient = supprimeClient(tabClient, *nbClient);
        printf("Appuyer sur une touche pour afficher les changements...\n");
        getchar();
        afficherTabClient(tabClient, *nbClient);
        printf("Appuyer sur une touche pour continuer...\n");
        getchar();
        break;
    case QUATRE:
    system("clear");
        consulterClient(tabClient, *nbClient);
        printf("Appuyer sur une touche pour continuer...\n");
        getchar();
        break;

    case 48:
        break;

    default:
        printf("Mauvaise saisie");
        break;
    }
    menuClient(tabClient, nbClient);
}

/*-------------------------------------------- Menu Commande ------------------------------------------------*/

void menuCommande(Client tabClient[], int *nbClient,Article * tabArt[], int *nbArt)
{
    int choix;
    afficheMenuCommande();
    choix = choixMenu();
    if (choix == 48)
        return;
    switch (choix)
    {
        case UN:
        system("clear");
            saisirCommande(tabClient,*nbClient,tabArt,*nbArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            getchar();
            break;

        case DEUX:
            lireFichierCommande(tabClient,*nbClient,tabArt,*nbArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            break;

    default:
        printf("Mauvaise saisie");
        break;
    }
    menuCommande(tabClient, nbClient,tabArt,nbArt);
}


void menuReappro(Client tabClient[], int *nbClient,Article * tabArt[], int *nbArt)
{
    int choix;
    afficheMenuReappro();
    choix = choixMenu();
    if (choix == 48)
        return;
    switch (choix)
    {
        case UN:
            saisirReappro(tabClient,*nbClient,tabArt,*nbArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            getchar();
            getchar();
            break;

        case DEUX:
            printf("hi2");
            break;

    default:
        printf("Mauvaise saisie");
        break;
    }
    menuReappro(tabClient, nbClient,tabArt,nbClient);
}
/*-------------------------------------------- Menu Reglage -------------------------------------------------*/

void afficheMenuReglage(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\tGestion des Client et Article et Commande\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Sauvegarder le fichier articles\t\t┃\n");
    printf("┃\t2.  Sauvegarder le fichier client\t\t┃\n");
    printf("┃\t3.  Sauvegarder le fichier commande\t\t┃\n");
    printf("┃\t4.  Sauvegarder tous les fichiers\t\t┃\n");
    printf("┃\t\t\t\t\t\t\t┃\n");
    printf("┃\t0. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void menuReglage(Article *tabArt[], int *tailleArt,Client tabClient[], int *nbClient)
{
    int choix;
    while (choix != 48)
    {
        afficheMenuReglage();
        choix = choixMenu();
        system("clear");
        switch (choix)
        {
        case UN:
            sauvegardeTabArticle(tabArt,*tailleArt);
            break;

        case DEUX:
            sauvegardeTabClient(tabClient,*nbClient);
            break;

        case TROIS:
            sauvegardeListeCommandes(tabClient,*nbClient);
            break;

        case QUATRE:
            sauvegardeTabArticle(tabArt,*tailleArt);
            sauvegardeTabClient(tabClient,*nbClient);
            break;

        
        case 48:
            break;

        default:
            printf("Mauvais saisi");
            break;
        }
    }
}

/*-----------------------------------------------------------------------------------------------------------*/

