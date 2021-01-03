#include <moteur_inference.h>

Regle moteur_inference(BC bc, Regle bf){

    BC bcCurseur = bc;
    Regle bfCurseur = creer_regle();

    while(!bc_est_vide(bcCurseur)){ // traverse la base de connaissance (accède à chaque proposition des règles de la bc)
        bfCurseur = bf;
        while(!regle_est_vide(bfCurseur)){ // traverse la base de faits (accède à chaque fait)
            
            // supprime la proposition de la règle si le fait est contenu dans la prémisse (suppr_prop ne fait rien si le fait n'est pas contenu dans la règle)
            bcCurseur->rgl = suppr_prop(bcCurseur->rgl,bcCurseur->rgl,contenu(bfCurseur));

            bfCurseur = bfCurseur->suiv; 
        }
        bcCurseur = bcCurseur->suiv;
    }

    bcCurseur = bc;
    Regle faits_verifies = creer_regle();
    
    while(!bc_est_vide(bcCurseur)){ // traverse la base de connaissances (accède à chaque règle)
        if(regle_est_vide(bcCurseur->rgl->suiv)){ // il ne reste plus qu'un element dans la rèlge (la conclusion) <=> la prémisse est vide
            faits_verifies = ajout_proposition(faits_verifies,contenu(bcCurseur->rgl),true); // on ajoute la conclusion au
        }
        bcCurseur = bcCurseur->suiv;
    }

    return faits_verifies;
}

void afficher_faits_verifies(Regle bf){
    if(regle_est_vide(bf)){
        printf("\nAucune conclusion n'est verife");
    }else{
        printf("\nConlusions verifees :");
        while(!regle_est_vide(bf)){
            printf("\n\t%s",contenu(bf));
            bf = bf->suiv;
        }
    }

}