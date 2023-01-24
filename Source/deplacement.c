/**
\file deplacement.c
\brief Gestion des deplacements du manutentionnaire
*/


#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "fonction.h"

#define MAXSIZE 10

/**
\fn int configure_terminal()
\brief Fonction qui configure le terminal sous un mode adapté à l'affichage du plateau de jeu
*/
int configure_terminal()
{
    struct termios new;
    if (tcgetattr(0,&new)==-1) {
        perror("tcgetattr");
        return -1;
    }
    new.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
    new.c_lflag &= ~(ECHO);   // les touches tapées ne s'inscriront plus dans le terminal
    new.c_cc[VMIN]=1;
    new.c_cc[VTIME]=0;
    if (tcsetattr(0,TCSANOW,&new)==-1) {
        perror("tcsetattr");
        return 0;
    }
    return 1;
}

/**
\fn int lit_clavier()
\brief fonction de lecture des entrees clavier. Touches directionnelles : Haut=1, Bas=2, Droite=3, Gauche=4
*/
int lit_clavier()
{
    char r[MAXSIZE];
    int c;

    if ((c=read(0,r,3)) == - 1 ) return 0;

    switch (r[0]) {
        case 27 :  if ((c==3) && (r[1]==91)) return (r[2]-64); else return 0; break;
        default: return r[0]; break;
    }
}


/**
\fn void deplacement_manu_haut (struct caseTableau **tab, int *imanu, int *jmanu)
\brief fonction de deplacement du manutentionnaire vers la case au dessus. Similaire pour bas, droite et gauche.
\param tab pointeur de pointeur vers le tableau qui stocke le plateau de jeu
\param imanu pointeur vers la position en abscisse du manutentionnaire
\param jmanu pointeur vers la position en ordonnées du manutentionnaire
*/
void deplacement_manu_haut (struct caseTableau **tab, int *imanu, int *jmanu) {
    int i= *imanu;
    int j = *jmanu;

    if (tab[i-1][j].mur == 1) {
        tab[i][j].manu=1;
    }
    else if (tab[i-1][j].cible == 1){
        tab[i-1][j].manu=1;
        tab[i][j].manu=0;
        //compteurMouvement ++;
    }
    else {
        tab[i-1][j].manu=1;
        tab[i][j].manu=0;
        //compteurMouvement ++;
    }
    //printf("Compteur Mouvements = %d\n", compteurMouvement);

}

/**
\fn void poussee_caisse_haut (struct caseTableau **tab, int *imanu, int *jmanu)
\brief fonction de poussée de la caisse vers la case au dessus. Similaire pour bas, droite et gauche.
\param tab pointeur de pointeur vers le tableau qui stocke le plateau de jeu
\param imanu pointeur vers la position en abscisse du manutentionnaire
\param jmanu pointeur vers la position en ordonnées du manutentionnaire
*/
void poussee_caisse_haut (struct caseTableau **tab, int *imanu, int *jmanu) {
    int i= *imanu;
    int j = *jmanu;
    if (tab[i-2][j].mur == 1 || tab[i-2][j].caisse == 1) {
        tab[i][j].manu=1;
    }
    else {
        tab[i-1][j].manu=1;
        tab[i][j].manu=0;
        tab[i-1][j].caisse=0;
        tab[i-2][j].caisse=1;

        //compteurPoussee ++;
        //printf("Compteur poussees = %d\n", compteurPoussee);

    }
}

// Déplacement et poussée bas
void deplacement_manu_bas (struct caseTableau **tab, int *imanu, int *jmanu) {
    int i= *imanu;
    int j = *jmanu;

    if (tab[i+1][j].mur == 1) {
        tab[i][j].manu=1;
    }
    else if (tab[i+1][j].cible == 1){
        tab[i+1][j].manu=1;
        tab[i][j].manu=0;
        // compteurMouvement ++;
    }
    else {
        tab[i+1][j].manu=1;
        tab[i][j].manu=0;
        //compteurMouvement ++;
    }
    // printf("Compteur Mouvements = %d\n", compteurMouvement);
}

void poussee_caisse_bas (struct caseTableau **tab, int *imanu, int *jmanu) {
    int i= *imanu;
    int j = *jmanu;

    if (tab[i+2][j].mur == 1 || tab[i+2][j].caisse == 1) {
        tab[i][j].manu=1;
    }
    else {
        tab[i+1][j].manu=1;
        tab[i][j].manu=0;
        tab[i+1][j].caisse=0;
        tab[i+2][j].caisse=1;

        //compteurPoussee ++;
        //printf("Compteur poussees = %d\n", compteurPoussee);

    }
}

// Déplacement et poussée droite
void deplacement_manu_droite (struct caseTableau **tab, int *imanu, int *jmanu) {
    int i= *imanu;
    int j = *jmanu;
    if (tab[i][j+1].mur == 1) {
        tab[i][j].manu=1;
    }
    else if (tab[i][j+1].cible == 1){
        tab[i][j+1].manu=1;
        tab[i][j].manu=0;
        //compteurMouvement ++;
    }
    else {
        tab[i][j+1].manu=1;
        tab[i][j].manu=0;
        //compteurMouvement ++;
    }
    //printf("Compteur Mouvements = %d\n", compteurMouvement);

}


void poussee_caisse_droite (struct caseTableau **tab, int *imanu, int *jmanu) {
    int i= *imanu;
    int j = *jmanu;
    if (tab[i][j+2].mur == 1 || tab[i][j+2].caisse == 1) {
        tab[i][j].manu=1;
    }
    else {
        tab[i][j+1].manu=1;
        tab[i][j].manu=0;
        tab[i][j+1].caisse=0;
        tab[i][j+2].caisse=1;

        //compteurPoussee ++;
        //printf("Compteur poussees = %d\n", compteurPoussee);

    }
}

// Déplacement et poussée gauche
void deplacement_manu_gauche (struct caseTableau **tab, int *imanu, int *jmanu) {

    int i= *imanu;
    int j = *jmanu;

    if (tab[i][j-1].mur == 1) {
        tab[i][j].manu=1;
    }
    else if (tab[i][j-1].cible == 1){
        tab[i][j-1].manu=1;
        tab[i][j].manu=0;
        //compteurMouvement ++;
    }
    else {
        tab[i][j-1].manu=1;
        tab[i][j].manu=0;
        //compteurMouvement ++;
    }
    //printf("Compteur Mouvements = %d\n", compteurMouvement);

}

void poussee_caisse_gauche (struct caseTableau **tab, int *imanu, int *jmanu) {
    int i= *imanu;
    int j = *jmanu;
    if (tab[i][j-2].mur == 1 || tab[i][j-2].caisse == 1) {
        tab[i][j].manu=1;
    }
    else {
        tab[i][j-1].manu=1;
        tab[i][j].manu=0;
        tab[i][j-1].caisse=0;
        tab[i][j-2].caisse=1;

        //compteurPoussee ++;
        //printf("Compteur poussees = %d\n", compteurPoussee);
    }
}
Pile * p_pile;

/**
\fn void mouvement_manu(struct caseTableau **tab, int *imanu, int *jmanu)
\brief fonction de deplacement du manutentionnaire dans toutes les directions, qui fait appel aux fonctions directionnelles.
\param tab pointeur de pointeur vers le tableau qui stocke le plateau de jeu
\param imanu pointeur vers la position en abscisse du manutentionnaire
\param jmanu pointeur vers la position en ordonnées du manutentionnaire
\La fonction deplacement_manu a pour but d'effectuer le déplacement demandé en vérifiant la valeur de  la touche qui a été frappé afin de savoir quelle direction prendre.\n
 Si un touche autre que les flèches a été frappé, alors on reste aux mêmes coordonnées\n
 Si on appuie sur une des flèches, alors on appelle la fonction de déplacemetn correspondant à la direction de la flèche frappée.\n
 Haut : 1 - Bas : 2 - Droite : 3 -Gauche : 4
*/
void mouvement_manu(struct caseTableau **tab, int *imanu, int *jmanu, int *reset, int *quit, int *next){

    int i= *imanu;
    int j = *jmanu;
    configure_terminal();
    switch (lit_clavier()) {

            // Déplacement vers le haut
        case 1 :
            pile_push(&p_pile, 1);
            if (tab[i-1][j].caisse == 1) {
                poussee_caisse_haut(tab, &i, &j); }
            else {
                deplacement_manu_haut(tab, &i, &j); }
            break;

            // Déplacement vers le bas
        case 2 :
            pile_push(&p_pile, 2);
            if(tab[i+1][j].caisse == 1) {
                poussee_caisse_bas (tab, &i, &j); }
            else {
                deplacement_manu_bas (tab, &i, &j); }
            break;

            // Déplacement vers la droite
        case 3 :
            pile_push(&p_pile, 3);
            if(tab[i][j+1].caisse == 1) {
                poussee_caisse_droite (tab, &i, &j); }
            else {
                deplacement_manu_droite (tab, &i, &j); }
            break;

            // Déplacement vers la gauche
        case 4 :
            pile_push(&p_pile, 4);
            if(tab[i][j-1].caisse == 1) {
                poussee_caisse_gauche (tab, &i, &j); }
            else {
                deplacement_manu_gauche (tab, &i, &j); }
            break;
            // Reset du niveau
        case 114 :
            *reset = 1;
            break;
            //quitter le jeu
        case 113 :
            *quit = 1;
            break;
            //Passer au niveau suivant
        case 110 :
            *next = 1;
            break;

            // Annulation du mouvement
            //        case 127 :
            //            pile_pop(*p_pile);
            //            break;

            //default :
            //coordonneeManu;
    }
    //liste_affiche(p_pile);
}
