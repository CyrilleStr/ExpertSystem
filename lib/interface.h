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

/**
 * @brief attend une entrée de l'utilisateur pour continuer le programme
 * 
 */
void pause();

/**
 * @brief Affiche les éléments d'une base de connaissance
 * 
 * @param bc BC
 */
void afficher_bc(BC bc);

/**
 * @brief Affiche le contenu d'une règle
 * 
 * @param r Regle
 */
void afficher_regle(Regle r);

/**
 * @brief Affiche un base de fait
 * 
 * @param bf Regle
 */
void afficher_bf(Regle bf);


#endif