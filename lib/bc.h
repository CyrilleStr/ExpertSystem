#ifndef bc
#define bc

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
 * creer_base : créer un pointeur sur une base comportant une seule règle vide
 * @param
 * @return BC
 */
BC creer_base();

/**
 * ajout_regle : ajoute une règle à une base en queue
 * @param b base en question
 * @param r règle à ajouter
 * @return BC base mise à jour
 */
BC ajout_regle(BC b, Regle r);

/**
 * regle_tete : accède à la règle se trouvant en tête de la base
 * @param b base en question
 * @return Regle règle de la base
 */
Regle regle_tete(BC b);

/**
 * afficher_bc : affiche les éléments d'une base de connaissance
 * @param b base en question
 * @return void
 */
void afficher_bc(BC b);

#endif