#ifndef MOTEUR
#define MOTEUR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "regle.h"
#include "bc.h"
#include "bf.h"

/***** Définition des prototypes *****/

/**
 * @brief Déduit une liste de faits vrais, en fonction d'une base de connaissances et d'une base de faits
 * 
 * @param bc BC
 * @param bf BF
 * @return BF une liste chaînées de fatis vrais
 */
BF moteur_inference(BC bc, BF bf);

#endif