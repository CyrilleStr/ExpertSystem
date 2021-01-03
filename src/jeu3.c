#include <regle.h>
#include <bc.h>
#include <moteur_inference.h>
#include <interface.h>

int main(){
    
   // Déclaration d'une base de connaissance
    Regle r1 = creer_regle();
    Regle r2 = creer_regle();

    r1 = ajout_proposition(r1,"aime jouer sur son ordinateur",true);
    r1 = ajout_proposition(r1,"aime bricoler sur son ordinateur",true);
    r1 = ajout_proposition(r1,"aime creer des programmes",true);
    r1 = ajout_proposition(r1,"est autodidacte",true);
    r1 = ajout_proposition(r1,"aime travailler en plein air",false);

    r1 = ajout_conclusion(r1,"FISE informatique");

    r2 = ajout_proposition(r2,"aime la physique",true);
    r2 = ajout_proposition(r2,"aime les maths appliques a la physique",true);
    r2 = ajout_proposition(r2,"aime la conception",true);
    r2 = ajout_proposition(r2,"aime construire",true);
    r2 = ajout_conclusion(r2,"FISE mecanique");

    BC bc = creer_bc();
    bc = ajout_regle_bc(bc,r1);
    bc = ajout_regle_bc(bc,r2);

    // Déclaration d'une base de fait

    Regle bf = creer_regle();
    bf = ajout_conclusion(bf,"aime la physique");
    bf = ajout_conclusion(bf,"aime les maths appliques a la physique");
    bf = ajout_conclusion(bf,"aime la conception");
    bf = ajout_conclusion(bf,"aime construire");
    bf = ajout_conclusion(bf,"aime travailler en plein air");
    bf = ajout_conclusion(bf,"est autodidacte");

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