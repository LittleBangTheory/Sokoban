/**
\file affichage_tableau.c
\brief Fonction d'affichage

Affiche le plateau de jeu durant la partie.
*/



#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

/**
\fn void affichage_tableau(struct caseTableau **tab, int niveau)
\fonction d'affichage du plateau
\param tab adresse d'un pointeur de pointeur vers le tableau stockant le plateau de jeu
*/
void affichage_tableau(struct caseTableau **tab, int niveau){

    int nbLigne, nbColonne;
    nbLigne=ligne_niveau(niveau);
    nbColonne=colonne_niveau(niveau);

    int i, j;

    for (i = 0; i <nbLigne ; i++) {
        for (j = 0; j <nbColonne ; j++)
        {


            if (tab[i][j].mur == 1) {
                printf("\033[34m");
                printf("#");
                printf("\033[00m");
            }
            else if (tab[i][j].caisse == 1 && tab[i][j].cible == 1 ) {
                printf("\033[33m");
                printf("*");
                printf("\033[00m");
            }
            else if (tab[i][j].caisse == 1) {
                printf("\033[32m");
                printf("$");
                printf("\033[00m");
            }
            else if (tab[i][j].manu == 1 ) {
                printf("\033[01m");
                printf("@");
                printf("\033[00m");
            }
            else if (tab[i][j].cible == 1 ) {
                printf("\033[45m");
                printf(".");
                printf("\033[00m");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
