#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Définition des types :
 * Regle : liste chaînées de proposition, dont le dernier élément est la conclusion de la règle
 * Booléen : peut prendre la valeur TRUE (1) ou FALSE (0)
 */

typedef struct proposition{
    char* contenu;
    struct proposition* suiv;
}Propostition;
typedef Propostition* Regle;

typedef enum{
    FALSE = 0,
    TRUE = 1
}Boolean; 

/**
 * Définition des prototypes de fonctions :
 */

Regle creer_regle();
Boolean est_vide(Regle r);
char* contenu(Regle r);
char* conclusion(Regle r);
Regle ajout_proposition(Regle regle, char* prop);
Boolean ajout_conclusion(Regle r, char* ccl);
Boolean contient(Regle r, char* prop);
Regle suppr_prop(Regle r, Regle p, char* prop);
void afficher_regle(Regle r);