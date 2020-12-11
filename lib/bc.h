#ifndef BASE_CONNAISSANCE
#define BASE_CONNAISSANCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regle.h"

/***** Définition des types *****/

/**
 * @brief Element de la liste chaînée de règle 
 * 
 */
typedef struct elemRegle{
    Regle rgl;
    struct elemRegle* suiv;
}ElemRegle;

/**
 * @brief Définition d'une base de connaissnces (liste chaînée de règle)
 * 
 */
typedef ElemRegle* BC;

/***** Définition des prototypes *****/

/**
 * @brief Créer un pointeur sur une base comportant une seule règle vide
 * 
 * @return BC
 */
BC creer_bc();

/**
 * @brief Test si une base de connaissances est vide 
 * 
 * @param b BC
 * @return true la base de connsaissances est vide 
 * @return false la base de connaissances n'est pas vide
 */
bool bc_est_vide(BC b);

/**
 * @brief Ajoute une règle à une base en queue
 * 
 * @param b BC
 * @param r Regle
 * @return BC La base mise à jour
 */
BC ajout_regle_bc(BC b, Regle r);

/**
 * @brief Accède à la règle se trouvant en tête de la base
 * 
 * @param b BF
 * @return Regle règle de la base
 */
Regle regle_tete_bc(BC b);

/**
 * @brief Libére l'espace alloué en mémoire à une base de connaissance
 * 
 * @param b BF
 */
void suppr_bc(BC b);

/**
 * @brief Affiche les éléments d'une base de connaissance
 * 
 * @param b BFn
 */
void afficher_bc(BC b);

#endif