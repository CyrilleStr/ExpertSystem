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
    bool valeur;
    struct proposition* suiv;
} Proposition;

/**
 * @brief Définition d'une règle comme une liste chaînée de propositions dont le dernier élément est la conclusion
 * 
 */
typedef Proposition* Regle;


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
 * contenu : accède à la proposition se trouvant en tête d'une prémisse
 * @param Regle r
 * @return string
 */
char* contenu(Regle r);

/**
 * @brief renvoie (sous forme de chaîne de caractères) la valeur de la proposition
 * 
 * @param r Regle
 * @return char* (vrai ou faux) 
 */
char* valeur(Regle r);

/**
 * conclusion : accède à la conclusion d'une règle (dernier élément de la liste)
 * @param r Regle
 * @return string
 */
char* conclusion(Regle r);

/**
 * @brief ajoute une proposition à une règle, l'ajout se fait en queue.
 * 
 * @param r 
 * @param prop 
 * @return Regle 
 */
Regle ajout_proposition(Regle r, char* prop, bool valeur);

/**
 * @brief ajoute la conclusion d'une règle, dernier élément de la liste de proposition
 * 
 * @param r 
 * @param ccl 
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
bool contient(Regle p, char* prop);

/**
 * @brief Supprime une proposition d'une prémisse
 * 
 * @param p prémisse
 * @param ptrOriginal prémisse (identique à p, lors du premier à appel de la fonction)
 * @param prop proposition à supprimer
 * @return Premisse prémisse mise à jour
 */
Regle suppr_prop(Regle p, Regle ptrOriginal, char* prop);

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