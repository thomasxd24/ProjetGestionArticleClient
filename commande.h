#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"client.h"
#include"article.h"
#include"ligneCommande.h"

void saisirCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);
void lireFichierCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);