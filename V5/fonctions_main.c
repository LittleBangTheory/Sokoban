/**
*\file fonction_main.c
*\brief Fichier qui regroupe les fonctions utilisées par le main.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

/**
\fn int nombre_cible(struct caseTableau **tab, int niveau)
\brief fonction qui compte le nombre de cibles sur le plateau
\param tab pointeur de pointeur vers le tableau qui stocke le plateau de jeu
\param niveau numéro de niveau pour compter les cibles
*/
int nombre_cible(struct caseTableau **tab, int niveau){
    int i,j,nbCible;
    int nbLigne, nbColonne;
    nbCible=0;
    nbLigne=ligne_niveau(niveau);
    nbColonne=colonne_niveau(niveau);

    for (i = 0; i < nbLigne; i++){
        for (j = 0; j < nbColonne; j++){
            if (tab[i][j].cible == 1) {
                nbCible++;
            }
        }
    }
    return nbCible;
}

/**
\fn int caisse_sur_cible(struct caseTableau **tab, int niveau, int nbCible){
\brief verifie si toutes les caisses sont sur leur cible
\param tab pointeur de pointeur vers le tableau qui stocke le plateau de jeu.
\param niveau numéro de niveau pour compter les cibles.
\param nbCible nombre de cases cibles sur le plateau.
*Cette fonction compte le nombre de cases cibles avec une caisses dessus, et verifie si ce nombre est egal au nombre de cases cibles. Il retourne True si oui, False si non.
*/
int caisse_sur_cible(struct caseTableau **tab, int niveau, int nbCible){
    int i,j,w,cibleValide;
    int nbLigne, nbColonne;
    cibleValide=0;
    w=0;
    nbLigne=ligne_niveau(niveau);
    nbColonne=colonne_niveau(niveau);

    for (i = 0; i < nbLigne; i++){
        for (j = 0; j < nbColonne; j++){
            if(tab[i][j].cible==1 && tab[i][j].caisse==1){
                cibleValide++;
                if (cibleValide==nbCible) {
                    w=1;
                }
                else{
                    w=0;
                }
            }
        }
    }
    return w;
}
