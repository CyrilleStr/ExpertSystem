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
} Proposition;

/**
 * @brief Définition d'une prémisse comme une liste chaînée de propositions (pour une meilleure lisibilité du code)
 * 
 */
typedef Proposition* Premisse;

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
 * est_vide : test si la prémisse et la conlsuion d'une Règle sont vides
 * @param Regle r
 * @return Boolean (TRUE si vide et FALSE si non vide)
 */
bool regle_est_vide(Regle r);

/**
 * @brief test si une prémisse est vide
 * 
 * @param p Premsisse
 * @return true si p est vide
 * @return false si p n'est pas vide
 */
bool prem_est_vide(Premisse p);

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
 * @param Regle r
 * @param ccl string
 * @return Regle
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
 * @param ptrOriginal prémisse (identique à p, lors du premier à appel de la fonction)
 * @param prop proposition à supprimer
 * @return Premisse prémisse mise à jour
 */
Premisse suppr_prop(Premisse p, Premisse ptrOriginal, char* prop);

/**
 * @brief Libére l'espace alloué en mémoire à une règle
 * 
 * @param r Regle
 */
void suppr_regle(Regle r);

/**
 * @brief Affiche le contenu d'une règle
 * 
 * @param r Regle
 */
void afficher_regle(Regle r);

#endif