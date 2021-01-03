#include <regle.h>
#include <bc.h>
#include <moteur_inference.h>

int main(){

    char input[10];
    int choix = 0;
    BC bc = creer_bc();
    // Déclaration d'une base de connaissance
    
    Regle r1 = creer_regle();
    Regle r2 = creer_regle();
    Regle r3 = creer_regle();

    r1 = ajout_proposition(r1,"fievre");
    r1 = ajout_proposition(r1,"perte de goût");
    r1 = ajout_proposition(r1,"toux");
    r1 = ajout_conclusion(r1,"covid");

    r2 = ajout_proposition(r2,"epuisements");
    r2 = ajout_proposition(r2,"maux de tete");
    r2 = ajout_proposition(r2,"maux de ventre");
    r2 = ajout_proposition(r2,"eternuments");
    r2 = ajout_conclusion(r2,"grippe");

    r3 = ajout_proposition(r3,"diarrhee");
    r3 = ajout_proposition(r3,"nausees");
    r3 = ajout_proposition(r3,"fievre");
    r3 = ajout_conclusion(r3,"gastro enterite");

    BC bc = creer_bc();
    bc = ajout_regle_bc(bc,r1);
    bc = ajout_regle_bc(bc,r2);
    bc = ajout_regle_bc(bc,r3); 

    // Déclaration d'une base de fait

    BF bf = creer_bf();
    bf = ajout_fait_bf(bf,"perte de gout");
    bf = ajout_fait_bf(bf,"nausees");
    bf = ajout_fait_bf(bf,"diarrhee");
    bf = ajout_fait_bf(bf,"fievre");
    bf = ajout_fait_bf(bf,"toux");

    afficher_bc(bc);
    afficher_bf(bf);

    // Moteur d'inference

    BF faits_verifies = creer_bf();
    faits_verifies = moteur_inference(bc,bf);

    printf("\n\nFaits verifies :");
    afficher_bf(faits_verifies);

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
