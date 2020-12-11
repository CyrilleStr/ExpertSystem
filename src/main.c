#include "regle.h"
#include "bc.h"
#include "moteur_inference.h"
#include "interface.h"

int main(){

    char input[10];
    int choix = 0;
    BC bc = creer_bc();

    while(choix != 4){ 
        // Menu
        choix = 0;
        while(choix != 1 && choix != 2 && choix != 3 && choix != 4){
            printf("\nQue voulez-vous faire ? \n1. Creer une nouvelle base de connaissances \n2. Creer une nouvelle base de faits \n3. Monteur inference \n4. Quitter \n Choix :");
            gets(input);
            choix = atoi(input);
        }
        // Redirection
        switch (choix){
        case 1:
            bc = remplir_bc(bc);
            afficher_bc(bc);
            break;
        case 2:
            printf("remplir bf");
            break;
        case 3:
            printf("choisir_bc_bf");
            break;
        case 4:
            break;
        default:
            printf("Erreur menu");
            choix = 4;
            break;
        }
    }

    
    return 0;
}