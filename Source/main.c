/**
*\file main.c
*\brief Fichier principal qui articule toutes les fonctionnalités.
*/

#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

//char *fileName="/Users/maximegobet/Documents/ESISAR/2A/Projet SI/Info/Projet Si/Projet Si/levels.lvl";
char *fileName="levels.lvl";


/**
\fn int main()
\brief fonction main

\*Initialisation : création du tableau qui stocke le plateau de jeu, récupération du numéro du niveau à charger
\*Fonctionnement : main.c charge le plateau dans le tableau, l'affiche, puis déplace le manutentionnaire et les caisses jusqu'à ce que :\n
\-le niveau soit terminé (alors il passe au niveau d'après)\n
\-le joueur décide de quitter la partie (alors il sauvegarde l'état de la partie et ferme l'écran de jeu)
*/
int main(){

    int imanu;
    int jmanu;
    int w=0;
    int niveau;
    int reset = 0;
    int quit = 0;
    int next = 0;
    struct caseTableau **tab;


    /* TESTS UNITAIRES */

     printf("Tests unitaires:\n\n");
     niveau=3;

     tab=lire_tableau(niveau);
     affichage_tableau(tab,niveau);
     printf("Test lire_tableau et affichage_tableau OK\n");


     if (trouver_debut_plateau(niveau)==34) {
     printf("Test trouver_debut_plateau OK\n");
     }
     if (ligne_niveau(niveau)==10) {
     printf("Test ligne_niveau OK\n");
     }
     if (colonne_niveau(niveau)==17) {
     printf("Test colonne_niveau OK\n");
     }

     position_manu(tab, niveau, &imanu, &jmanu);
     if (imanu == 1 && jmanu == 14) {
     printf("Test position_manu OK\n");
     }
     if (nombre_cible(tab,niveau)==11) {
     printf("Test nombre_cible OK\n");
     }
     

    printf("Bienvenue sur le sokoban, entrer un niveau entre 1 et 88:   ");
    scanf("%d", &niveau);
    printf("\e[1;1H\e[2J");
    if (niveau>=1 && niveau<=88) {
        printf("Niveau %d \n", niveau);
    }
    else{
        printf("Ce niveau n'existe pas");
    }


    while (niveau <= 88 && quit !=1)
    {
        tab=lire_tableau(niveau);
        affichage_tableau(tab,niveau);
        position_manu (tab, niveau, &imanu, &jmanu);
        reset = 0;
        while (w != 1 && reset != 1 && quit != 1 && next !=1)
        {
            printf("\e[1;1H\e[2J");
            mouvement_manu(tab, &imanu, &jmanu, &reset, &quit, &next);
            position_manu (tab, niveau, &imanu, &jmanu);
            printf("\033[36m");
            printf("Niveau %d \n", niveau);
            affichage_tableau(tab,niveau);
            w=caisse_sur_cible(tab,niveau,nombre_cible(tab, niveau));
        }
        free(tab);
        if ((reset == 0 && quit == 0) || next == 1)
        {
            printf("Niveau %d terminé !\n", niveau);
            niveau++;
            w = 0;
            next = 0;
        }
        else if (quit == 1){
            printf("Fermeture du niveau, merci d'avoir joué\n");
        }
        else {
            printf("\e[1;1H\e[2J");
            printf("Reprise du niveau : \n");
            printf("Niveau %d \n", niveau);
        }
    }
    return 0;
}
