/**
*\file lire_tableau.c
*\brief Fichier qui regroupe les fonctions qui lisent un niveau depuis le fichier des niveaux.
*/

#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

extern char *fileName;

/**
\fn int trouver_debut_plateau (int niveau)
\brief fonction qui positionne l'emplacement du premier caractère du niveau demandé
\param niveau numéro de niveau
\cette fonction parcourt la liste des niveaux en identifiant le format ";LEVEL" jusqu'à trouver le bon numéro.
*/
int trouver_debut_plateau (int niveau){
    FILE* fd;
    fd = fopen(fileName, "r");
    if (fd==NULL) {printf("error file not found ");};
    int c;
    int ligne = 0;
    int newLvl = 0;
    while (newLvl < niveau){
        c = fgetc(fd);
        if (c == '\n')
        {
            ligne++;
        }
        if (c == ';')
        {
            c = fgetc(fd);
            if(c == 'L')
            {
                c = fgetc(fd);
                if (c == 'E')
                {
                    newLvl++;
                }
            }
        }

    }
    while (c!='#') {
        c = fgetc(fd);
        if (c==';') {
            ligne++;
        }
    }

    fclose(fd);
    return ligne;
}

/**
\fn int ligne_niveau(int niveau)
\brief fonction qui calcule le nombre de lignes du plateau pour un niveau donné.
\param niveau numéro de niveau.
*/
int ligne_niveau(int niveau)
{
    FILE* fd;
    fd = fopen(fileName, "r");
    int c;
    int ligne = 0;
    int newLvl = 0;
    while (newLvl < niveau){
        c = fgetc(fd);
        if (c == '\n')
        {
            ligne++;
        }
        if (c == ';')
        {
            c = fgetc(fd);
            if(c == 'L')
            {
                c = fgetc(fd);
                if (c == 'E')
                {
                    newLvl++;
                }
            }
        }
    }    while (c!='#') {
        c = fgetc(fd);
        if (c==';') {
            ligne++;
        }
    }
    int ligneDebut = ligne;
    while (newLvl <= niveau && c!=EOF)
    {
        c = fgetc(fd);
        if (c == '\n')
        {
            ligne++;
        }
        if (c == ';')
        {
            c = fgetc(fd);
            if(c == 'L')
            {
                c = fgetc(fd);
                if (c == 'E')
                {
                    newLvl++;
                }
            }
        }
    }
    int ligneFin = ligne;
    int ligneTotal = ligneFin - ligneDebut ;
    fclose(fd);
    return ligneTotal;
}

/**
\fn int colonne_niveau(int niveau)
\brief fonction qui calcule le nombre de colonnes du plateau pour un niveau donné.
\param niveau numéro de niveau.
*/
int colonne_niveau(int niveau){
    FILE* fd;
    fd = fopen(fileName, "r");
    int c;
    int ligne = 0;
    int newLvl = 0;
    while (newLvl < niveau){
        c = fgetc(fd);
        if (c == '\n')
        {
            ligne++;
        }
        if (c == ';')
        {
            c = fgetc(fd);
            if(c == 'L')
            {
                c = fgetc(fd);
                if (c == 'E')
                {
                    newLvl++;
                }
            }
        }
    }
    while (c!='#') {
        c = fgetc(fd);
        if (c==';') {
            ligne++;
        }
    }
    while (c != '\n')
    {
        c = fgetc(fd);
    }

    int maxCol = 0;
    int maxTot = 0;
    c = fgetc(fd);
    while (c != ';'&& c!=EOF)
    {
        while (c != '\n')
        {
            maxCol++;
            c = fgetc(fd);
        }
        if (maxCol > maxTot)
        {
            maxTot = maxCol;
        }
        maxCol = 0;
        c = fgetc(fd);
    }


    fclose(fd);
    return maxTot;

}

/**
\fn struct caseTableau ** lire_tableau(int niveau)
\brief fonction qui importe le plateau de jeu dans un tableau.
\param niveau numéro de niveau.
\Tableau de type pointeur vers pointeur vers un type caseTableau
\La fonction détermine la taille du plateau et alloue l'espace mémoire nécessaire au tableau
\Puis elle parcourt le plateau du niveau et le tableau créé pour remplir le tableau case par case, en initialisant les élements de type structure selon les cases du plateau.
*/
struct caseTableau ** lire_tableau(int niveau){

    FILE* fd;
    fd = fopen(fileName, "r");
    int  i, j, c, findeligne;
    int ligne=0;
    int nbLigne,nbColonne,debutPlateau;
    char valeur;

    nbLigne=ligne_niveau(niveau);
    //nbLigne=2;
    nbColonne=colonne_niveau(niveau)+1; //add one for /n

    debutPlateau= trouver_debut_plateau(niveau)+1; // add one to skip to data
    // printf("nbligne  %d\n", nbLigne);
    //printf("nbcolonne  %d\n", nbColonne);
    //  printf("debut plateau   %d\n", debut_plateau);



    struct caseTableau **tabdef;
    tabdef = (struct caseTableau**) malloc(sizeof(struct caseTableau*) * nbLigne);


    for (i = 0; i < nbLigne; i++){
        tabdef[i] = (struct caseTableau*)malloc(nbColonne * sizeof(struct caseTableau));
    }


    for (i = 0; i < nbLigne; i++){
        for (j = 0; j < nbColonne; j++){
            tabdef[i][j].mur=0;
            tabdef[i][j].caisse=0;
            tabdef[i][j].sol=0;
            tabdef[i][j].manu=0;
            tabdef[i][j].cible=0;

        }}

    while (ligne!=debutPlateau) {
        c = fgetc(fd);
        if (c == '\n')
        {
            ligne++;
        }
    }
    //printf("ligne  %d\n", ligne);


    for (i = 0; i < nbLigne; i++){
        findeligne=0;
        //printf("i=  %d\n", i);

        for (j = 0; j < nbColonne; j++){
            //printf("j=  %d\n", j);
            if (findeligne==0){
                valeur = fgetc(fd);
                // printf("valeur= %x\n", valeur);


            }
            if (valeur == '\n') {
                findeligne=1;
                tabdef[i][j].sol=1;

            }
            if (valeur == ' ') {
                tabdef[i][j].sol=1;
            }
            if (valeur == '$') {
                tabdef[i][j].caisse=1;
            }
            if (valeur == '.') {
                tabdef[i][j].cible=1;
            }
            if (valeur == '#') {
                tabdef[i][j].mur=1;
            }
            if (valeur == '@') {
                tabdef[i][j].manu=1;
            }
            if (valeur == '*') {
              tabdef[i][j].caisse=1;
              tabdef[i][j].cible=1;
            }

        }
    }
    fclose(fd);


    return(tabdef);
}
