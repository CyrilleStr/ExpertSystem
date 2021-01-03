#ifndef INTERFACE
#define INTERFACE

#define WINDOWS
#ifdef WINDOWS
#define effacer_terminal() system("cls");
#endif

#ifdef UNIX
#define effacer_terminal() system("clear");
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "regle.h"
#include "bc.h"
#include "bf.h"

/**
 * @brief Interface utilisateur lui permettant de remplir une base de connaissance
 * 
 * @param bc BC la base de connsaisance à remplir
 * @return BC 
 */
BC remplir_bc(BC bc);

/**
 * @brief attend une entrée de l'utilisateur pour continuer le programme
 * 
 */
void pause();

#endif