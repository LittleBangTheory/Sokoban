/**
*\position_manu.c
*\brief Fichier qui trouve les coordonnées du manutentionnaire.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"


/**
\fn int position_manu(struct caseTableau **tab, int niveau, int *imanu, int *jmanu)
\brief fonction qui determine les coordonnées du manutentionnaire sur le plateau de jeu
\param caseTableau pointeur de pointeur vers le tableau qui stocke le plateau de jeu
\param niveau numéro du niveau pour determiner les dimensions du plateau
\param imanu coordonnée en abscisses du manutentionnaire sur le plateau
\param jmanu coordonnée en ordonnées du manutentionnaire sur le plateau
*Cette fonction parcourt toutes les cases du plateau jusqu'à trouver celle où se situe le manutentionnaire.
*/
int position_manu(struct caseTableau **tab, int niveau, int *imanu, int *jmanu){

    int nbLigne, nbColonne;
    nbLigne=ligne_niveau(niveau);
    nbColonne=colonne_niveau(niveau);

    int i, j;

    for (i = 0; i <nbLigne ; i++) {
        for (j = 0; j <nbColonne ; j++)
        {

            if (tab[i][j].manu == 1 ) {
                *imanu=i;
                *jmanu=j;
            }
        }
    }
    return 0;
}
