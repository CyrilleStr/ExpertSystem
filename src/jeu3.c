#include <regle.h>
#include <bc.h>
#include <moteur_inference.h>

int main(){
    
   // Déclaration d'une base de connaissance
    Regle r1 = creer_regle();
    Regle r2 = creer_regle();

    r1 = ajout_proposition(r1,"aime jouer sur son ordinateur");
    r1 = ajout_proposition(r1,"aime bricoler sur son ordinateur");
    r1 = ajout_proposition(r1,"aime creer des programmes");
    r1 = ajout_proposition(r1,"est autodidacte");
    r1 = ajout_conclusion(r1,"FISE informatique");

    r2 = ajout_proposition(r2,"aime la physique");
    r2 = ajout_proposition(r2,"aime les maths appliques a la physique");
    r2 = ajout_proposition(r2,"aime la conception");
    r2 = ajout_proposition(r2,"aime construire");
    r2 = ajout_conclusion(r2,"FISE mecanique");

    BC bc = creer_bc();
    bc = ajout_regle_bc(bc,r1);
    bc = ajout_regle_bc(bc,r2);

    // Déclaration d'une base de fait

    BF bf = creer_bf();
    bf = ajout_fait_bf(bf,"aime la physique");
    bf = ajout_fait_bf(bf,"aime les maths appliques a la physique");
    bf = ajout_fait_bf(bf,"aime la conception");
    bf = ajout_fait_bf(bf,"aime construire");
    bf = ajout_fait_bf(bf,"est autodidacte");

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