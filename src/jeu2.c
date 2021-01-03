#include <regle.h>
#include <bc.h>
#include <moteur_inference.h>
#include <interface.h>

int main(){
    
   // Déclaration d'une base de connaissance

    Regle r1 = creer_regle();
    Regle r2 = creer_regle();
    Regle r3 = creer_regle();

    r1 = ajout_proposition(r1,"LO21: notes eliminatoires",false);
    r1 = ajout_proposition(r1,"LO21: plus de la moyenne",true);
    r1 = ajout_conclusion(r1,"6 credits valides");

    r2 = ajout_proposition(r2,"120 credits ECTS valides",true);
    r2 = ajout_proposition(r2,"Plus de 3 absences",false);
    r2 = ajout_proposition(r2,"Plus de 3 retards",false);
    r2 = ajout_conclusion(r2,"Passe en branche");

    r3 = ajout_proposition(r3,"IFD2: notes eleminatoires",false);
    r3 = ajout_proposition(r3,"IFD2: plus de la moyenne",true);
    r3 = ajout_conclusion(r3,"3 credits valides");

    BC bc = creer_bc();
    bc = ajout_regle_bc(bc,r1);
    bc = ajout_regle_bc(bc,r2);
    bc = ajout_regle_bc(bc,r3);

    // Déclaration d'une base de fait

    Regle bf = creer_regle();
    bf = ajout_conclusion(bf,"LO21: notes eliminatoires");
    bf = ajout_conclusion(bf,"LO21: plus de la moyenne");
    bf = ajout_conclusion(bf,"120 credits ECTS valides");
    bf = ajout_conclusion(bf,"Plus de 3 retards");

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