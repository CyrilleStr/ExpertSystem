#ifndef MOTEUR
#define MOTEUR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regle.h>
#include <bc.h>

/***** Définition des prototypes *****/

/**
 * @brief Déduit une liste de faits vrais, en fonction d'une base de connaissances et d'une base de faits
 * 
 * @param bc BC
 * @param bf Regle
 * @return Regle une liste chaînées de faits vrais
 */
Regle moteur_inference(BC bc, Regle bf);

/**
 * @brief Affiche les faits vérifiés
 * 
 * @param bf 
 */
void afficher_faits_verifies(Regle bf);


#endif