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

/**
 * creer_regle : créer un pointeur (de valeur nulle) sur une liste de proposition
 * @param
 * @return Regle
 */
Regle creer_regle();

/**
 * est_vide : test si la prémisse d'une Règle est vide
 * @param Regle r
 * @return Boolean (TRUE si vide et FALSE si non vide)
 */
bool est_vide(Regle r);

/**
 * contenu : accède à la proposition se trouvant en tête d'une prémisse
 * @param Regle r
 * @return string
 */
char* contenu(Regle r);

/**
 * conclusion : accède à la conclusion d'une règle
 * @param Regle r
 * @return string
 */
char* conclusion(Regle r);

/**
 * @brief ajoute une proposition à une règle, l'ajout se fait en queue.
 * 
 * @param regle 
 * @param prop 
 * @return Regle 
 */
Regle ajout_proposition(Regle r, char* prop);

/**
 * ajout_conclusion : ajoute une conlusion à la fin d'une regle (liste chaînées de proposition)
 * @param Regle r, string ccl
 * @return Boolean (TRUE si l'ajout a été fait et FALSE si l'ajout a échoué)
 */ 
Regle ajout_conclusion(Regle r, char* ccl);

/**
 * @brief Teste si une proposition est contenue dans la prémisse d'une règle.
 * 
 * @param p la prémisse de la règle
 * @param prop la proposition à tester
 * @return true la prémisse contient la proposition
 * @return false la prémisse ne contient pas la proposition
 */
bool contient(Premisse p, char* prop);

/**
 * @brief Supprime une proposition d'une prémisse
 * 
 * @param p prémisse
 * @param ptrOriginal idem que p
 * @param prop proposition à supprimer
 * @return Premisse prémisse mise à jour
 */
Premisse suppr_prop(Premisse p, Premisse ptrOriginal, char* prop);

/**
 * @brief Libérer l'espace alloué en mémoire à une règle
 * 
 * @param r Regle
 */
void libere_regle(Regle r);

void afficher_regle(Regle r);

#endif