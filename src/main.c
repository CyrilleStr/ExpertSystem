#include "regle.h"
#include "bc.h"
#include "moteur_inference.h"

int main(){

    // Déclaration d'une base de connaissance

    Regle r1 = creer_regle();
    Regle r2 = creer_regle();
    Regle r3 = creer_regle();

    r1 = ajout_proposition(r1,"bcp de bouton");
    r1 = ajout_proposition(r1,"mal de tete");
    r1 = ajout_conclusion(r1,"gastro");

    r2 = ajout_proposition(r2,"slips sales");
    r2 = ajout_proposition(r2,"pue du cul");
    r2 = ajout_conclusion(r2,"manque de PQ");

    r3 = ajout_proposition(r3,"accro a la weed");
    r3 = ajout_proposition(r3,"accro a la meth");
    r3 = ajout_proposition(r3,"accro a la morphine");
    r3 = ajout_proposition(r3,"accro au taz");
    r3 = ajout_conclusion(r3,"junkie");

    BC bc = creer_bc();
    bc = ajout_regle_bc(bc,r1);
    bc = ajout_regle_bc(bc,r2);
    bc = ajout_regle_bc(bc,r3); 

    // Déclaration d'une base de fait

    BF bf = creer_bf();
    bf = ajout_fait_bf(bf,"accro au taz");
    bf = ajout_fait_bf(bf,"accro a la morphine");
    bf = ajout_fait_bf(bf,"accro a la weed");
    bf = ajout_fait_bf(bf,"accro a la meth");
    bf = ajout_fait_bf(bf,"pue du cul");
    bf = ajout_fait_bf(bf,"slips sales");


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