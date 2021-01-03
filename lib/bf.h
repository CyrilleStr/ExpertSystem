#ifndef BASE_FAIT
#define BASE_FAIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regle.h>
#include <bc.h>

/***** Définition des types *****/

/**
 * @brief Définition d'une base de faits comme une liste chaînée de faits (chaîne de caractères)
 * @note Réutilisation du type du donnée "proposition"
 * 
 */
typedef Proposition* BF;

/***** Définition des prototypes *****/

/**
 * @brief Créer une base de faits vide
 * 
 * @return BF 
 */
BF creer_bf();

/**
 * @brief test si une base de faits est vide
 * 
 * @param b BF
 * @return true si la base est vide
 * @return false si la base n'est pas vide
 */
bool bf_est_vide(BF b);

/**
 * @brief Ajoute un fait (string ) une base de faits
 * 
 * @param b BF 
 * @param contenu string 
 * @return BF 
 */
BF ajout_fait_bf(BF b, char* contenu);

/**
 * @brief Affiche le contenu d'une base de faits
 * 
 * @param b 
 */
void afficher_bf(BF b);

/**
 * @brief Libére l'espace alloué en mémoire à une base de faits
 * 
 * @param b BF
 */
void suppr_bf(BF b);

#endif