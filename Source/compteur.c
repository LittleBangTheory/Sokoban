/**
*\file compteur.c
*\brief Fichier d'archive des mouvements
*Ajoute chaque mouvement a la liste chaînée, les retire lors d'annulation de coups, et affiche dans le terminal chaque mouvement.
*/



#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

/**
\fn void pile_push(Pile **p_pile, int donnee)
\brief fonction d'ajout d'un element a une liste chaînée
\param p_pile adresse d'un pointeur de pointeur vers dernier element de la liste chaînée
\param donnee mouvement a rajouter a la fin de la liste chaînée
*/
void pile_push(Pile **p_pile, int donnee)
{
    Pile *p_nouveau = malloc(sizeof *p_nouveau);
    if (p_nouveau != NULL)
    {
        p_nouveau->donnee = donnee;
        p_nouveau->precedent = *p_pile;
        *p_pile = p_nouveau;
    }
}

/**
\fn int pile_pop(Pile **p_pile)
\brief fonction de suppression du dernier element d'une liste chaînée
\param p_pile adresse d'un pointeur de pointeur vers dernier element de la liste chaînée
\return a completer
*/
int pile_pop(Pile **p_pile)
{
    int ret = -1;
    if (p_pile != NULL)
    {
        Pile *temporaire = (*p_pile)->precedent;
        ret = (*p_pile)->donnee;
        free(*p_pile), *p_pile = NULL;
        *p_pile = temporaire;
    }
    return ret;
}

/**
\fn void listeAffiche(Pile * ptr)
\brief fonction d'affichage du dernier coup joué (le dernier element d'une liste chaînée)
\param ptr pointeur vers le dernier element de la liste chaînée
*/
void liste_affiche(Pile * ptr){
    if ( NULL == ptr )
        printf("Liste vide!") ;
    else
        printf("Contenu de la liste : ") ;
    while ( NULL != ptr )     {
        printf("%d ",ptr->donnee);
        ptr = ptr->precedent ;
    }
    printf("\n") ;
}


int compteur_mouvement(Pile *p_pile){
    int compteur=0;
    while (p_pile->precedent != NULL)
    {
        compteur++;
        p_pile->precedent = p_pile;
    }
    return compteur;
}

/*
 int configureTerminal()
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

 int litClavier()
 {
 char r[MAXSIZE];
 int c;

 if ((c=read(0,r,3)) == - 1 ) return 0;

 switch (r[0]) {
 case 27 :  if ((c==3) && (r[1]==91)) return (r[2]-64); else return 0; break;
 default: return r[0]; break;
 }
 }


 int main (){
 Pile * p_pile = NULL;
 listeAffiche(p_pile);
 configureTerminal();
 pile_push(&p_pile, litClavier());
 listeAffiche(p_pile);
 }*/
