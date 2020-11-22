#ifndef REGLES
#define REGLES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/***** Définition des types *****/

/**
 * @brief Element de la liste chaînée 
 * 
 */
typedef struct proposition {
    char* contenu;
    struct proposition* suiv;
} Propostition;

/**
 * @brief Définition d'une prémisse comme une liste chaînée de propositions (pour une meilleure lisibilité du code)
 * 
 */
typedef Propostition* Premisse;

/**
 * @brief Définition d'une conclusion comme étant une chaîne de caractères (meilleure lisibilité du code)
 * 
 */
typedef char* Conclusion;

/**
 * @brief Structure composée d'une prémisse et d'une conclusion.
 * 
 */
typedef struct regle {
    Premisse prem;
    Conclusion ccl;
} Regle;


/***** Définition des prototypes *****/

Regle creer_regle();
bool est_vide(Regle r);
char* contenu(Regle r);
char* conclusion(Regle r);

/**
 * @brief ajoute une proposition à une règle, l'ajout se fait en queue.
 * 
 * @param regle 
 * @param prop 
 * @return Regle 
 */
Regle ajout_proposition(Regle regle, char* prop);
bool ajout_conclusion(Regle r, char* ccl);
bool contient(Regle r, char* prop);
Regle suppr_prop(Regle r, Regle p, char* prop);
void afficher_regle(Regle r);

#endif