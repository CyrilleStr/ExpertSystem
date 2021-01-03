#include "interface.h"

BC remplir_bc(BC bc){
    Regle r = creer_regle();
    int choix = 0;
    int choixPrem = 0;
    int compteurRegle = 0;
    int compteurProp = 0;
    char input[100];
    
    while(choix != 2){
        // Menu
        choix = 0;
        while(choix != 1 && choix != 2){
            effacer_terminal();
            printf("\nQue voulez vous faire ?\n1. Ajouter une regle\n2. Ajouter la conclusion\nChoix :");
            gets(input);
            choix = atoi(input);
        }
        // Redirection
        switch (choix)
        {
        case 1:
            compteurRegle++;
            effacer_terminal();
            printf("\nAjout de la regle numero %d :",compteurRegle);
            r = creer_regle();

            // Prémisse
            choixPrem = 0;
            while(choixPrem != 2){

                choixPrem = 0;
                while(choixPrem != 1 && choixPrem != 2){
                    effacer_terminal();
                    printf("\nQue voulez vous faire? \n1.Ajouter une proposition\n2.Ajouter la conclusion\nChoix :");
                    gets(input);
                    choixPrem = atoi(input);
                }

                switch (choixPrem){
                case 1: // Ajouter une proposition
                    compteurProp++;
                    effacer_terminal();
                    printf("\nAjout de la proposition numero %d:",compteurProp);
                    gets(input);
                    if(strlen(input) < 100){
                        r = ajout_proposition(r,input);
                        printf("\nProposition ajoutee");
                    }else{
                        printf("\nErreur : la proposition doit faire moins de 100 caracteres");
                    }
                    break;
                case 2:
                    break;
                
                default:
                    printf("\nError choix menu premisse");
                    break;
                }
            }

        case 2:
            // Ajout de la conclusion
            printf("\nConclusion :");
            gets(input);
            while(strlen(input) > 100){
                effacer_terminal();
                printf("\nLa conclusion doit faire moins de 100 caracteres");
                printf("\nConclusion :");
                gets(input);
            }
            r = ajout_conclusion(r,input);
            afficher_regle(r);
            printf("\nConclusion ajoutee");
            ajout_regle_bc(bc,r);
            afficher_bc(bc);
            printf("\nRegle ajoutee");
            break;
        default:
            printf("\nErreur choix menu");
            break;
        }
    }

    return bc;
    
}

void pause(){
    char enter = 0;
    printf("\nAppuiez sur Entrer pour continer");
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    effacer_terminal();
}