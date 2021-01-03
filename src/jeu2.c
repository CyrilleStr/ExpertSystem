#include <regle.h>
#include <bc.h>
#include <moteur_inference.h>

int main(){
    
   // Déclaration d'une base de connaissance
    Regle r1 = creer_regle();
    Regle r2 = creer_regle();
    Regle r3 = creer_regle();

    r1 = ajout_proposition(r1,"LO21: pas de notes eliminatoires");
    r1 = ajout_proposition(r1,"LO21: plus de la moyenne");
    r1 = ajout_conclusion(r1,"6 credits valides");

    r2 = ajout_proposition(r2,"120 crédits ECTS valides");
    r2 = ajout_proposition(r2,"aucune absence");
    r2 = ajout_proposition(r2,"aucun retard");
    r2 = ajout_conclusion(r2,"Passe en branche");

    r3 = ajout_proposition(r3,"IFD2: pas de notes eliminatoires");
    r3 = ajout_proposition(r3,"IFD2: plus de la moyenne");
    r3 = ajout_conclusion(r3,"3 credits valides");

    BC bc = creer_bc();
    bc = ajout_regle_bc(bc,r1);
    bc = ajout_regle_bc(bc,r2);
    bc = ajout_regle_bc(bc,r3);

    // Déclaration d'une base de fait

    BF bf = creer_bf();
    bf = ajout_fait_bf(bf,"LO21: pas de notes eliminatoires");
    bf = ajout_fait_bf(bf,"LO21: plus de la moyenne");
    bf = ajout_fait_bf(bf,"IFD2: pas de notes eliminatoires");
    bf = ajout_fait_bf(bf,"120 credits ECTS valides");
    bf = ajout_fait_bf(bf,"IFD2: plus de la moyenne");
    bf = ajout_fait_bf(bf,"aucun retard");

    afficher_bc(bc);
    afficher_bf(bf);

    // Moteur d'inference

    BF faits_verifies = creer_bf();
    faits_verifies = moteur_inference(bc,bf);

    printf("\n\nFaits verifies :");
    afficher_bf(faits_verifies);

    // Libération de l'espace 
    suppr_bc(bc);
    suppr_bf(bf);
    suppr_bf(faits_verifies);
    return 0;
}