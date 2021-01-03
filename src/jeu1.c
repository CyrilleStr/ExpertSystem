#include <regle.h>
#include <bc.h>
#include <moteur_inference.h>
#include <interface.h>

int main(){
    
   // Déclaration d'une base de connaissance

    Regle r1 = creer_regle();
    Regle r2 = creer_regle();
    Regle r3 = creer_regle();

    r1 = ajout_proposition(r1,"fievre",true);
    r1 = ajout_proposition(r1,"perte de gout",true);
    r1 = ajout_proposition(r1,"toux",true);
    r1 = ajout_conclusion(r1,"covid");

    r2 = ajout_proposition(r2,"epuisements",true);
    r2 = ajout_proposition(r2,"maux de tete",true);
    r2 = ajout_proposition(r2,"maux de ventre",true);
    
    r3 = ajout_proposition(r3,"diarrhee",true);
    r3 = ajout_proposition(r3,"nausees",true);
    r3 = ajout_proposition(r3,"fievre",true);
    r3 = ajout_conclusion(r3,"gastro enterite");

    BC bc = creer_bc();
    bc = ajout_regle_bc(bc,r1);
    bc = ajout_regle_bc(bc,r2);
    bc = ajout_regle_bc(bc,r3); 

    // Déclaration d'une base de fait

    Regle bf = creer_regle();
    bf = ajout_conclusion(bf,"perte de gout");
    bf = ajout_conclusion(bf,"nausees");
    bf = ajout_conclusion(bf,"diarrhee");
    bf = ajout_conclusion(bf,"fievre");
    bf = ajout_conclusion(bf,"toux");

    afficher_bc(bc);
    pause();
    afficher_bf(bf);
    pause();

    // Moteur d'inference

    Regle faits_verifies = creer_regle();
    faits_verifies = moteur_inference(bc,bf);

    afficher_faits_verifies(faits_verifies);
    pause();

    // Libération de l'espace

    suppr_bc(bc);
    suppr_regle(bf);
    suppr_regle(faits_verifies);
    return 0;
}