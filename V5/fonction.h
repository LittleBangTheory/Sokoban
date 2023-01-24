/**
*\file fonctions.h
*\brief Header qui liste les déclrations de toutes les fonctions et structures.
*/

/**
 * \struct caseTableau
 * \brief caractérise l'état de chaque case du plateau.
 * caseTableau indique pour chaque case quels sont les elements dessus (mur, sol, cible, manutentionnaire, caisse).
 */
struct caseTableau
{
    int mur;
    int sol;
    int cible;
    int manu;
    int caisse;
};

/**
 * \struct pile
 * \brief Définit un élement de la liste chaînée.
 * pile permet de stocker à chaque coup le mouvement effectué.
 */
typedef struct pile
{
    int donnee; /* La donnée que notre pile stockera. */
    struct pile *precedent; /* Pointeur vers l'élément précédent de la pile. */
} Pile;

void affichage_tableau(struct caseTableau **tab,int niveau);
struct caseTableau ** lire_tableau( int niveau);
int trouver_debut_plateau (int niveau);
int ligne_niveau(int niveau);
int colonne_niveau(int niveau);

void initialisation(int nbniveau);

int position_manu(struct caseTableau **tab, int niveau,int *imanu, int *jmanu);



void deplacement_manu_haut (struct caseTableau **tab, int *imanu, int *jmanu);
void poussee_caisse_haut (struct caseTableau **tab, int *imanu, int *jmanu);
void deplacement_manu_bas (struct caseTableau **tab, int *imanu, int *jmanu);
void poussee_caisse_bas (struct caseTableau **tab, int *imanu, int *jmanu);
void deplacement_manu_droite (struct caseTableau **tab, int *imanu, int *jmanu);
void poussee_caisse_droite (struct caseTableau **tab, int *imanu, int *jmanu);
void deplacement_manu_gauche (struct caseTableau **tab, int *imanu, int *jmanu);
void poussee_caisse_gauche (struct caseTableau **tab, int *imanu, int *jmanu);

void mouvement_manu(struct caseTableau **tab, int *imanu, int *jmanu, int *reset, int *quit, int *next);

int nombre_cible(struct caseTableau **tab, int niveau);

int caisse_sur_cible(struct caseTableau **tab, int niveau, int nbCible);

void liste_affiche(Pile * ptr);
int pile_pop(Pile **p_pile);
void pile_push(Pile **p_pile, int donnee);
int compteur_mouvement(Pile * p_pile);
