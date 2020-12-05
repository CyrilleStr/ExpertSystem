#include "moteur_inference.h"

BF moteur_inference(BC bc, BF bf){

    BC bcCurseur = bc;
    BF bfCurseur = creer_bf();

    while(!bc_est_vide(bcCurseur)){ // traverse la base de connaissance (accède à chaque prémisse des règles de la bc)
        bfCurseur = bf;
        while(!bf_est_vide(bfCurseur)){ // traverse la base de faits (accède à chaque fait)
            
            // supprime la proposition de la règle si le fait est contenu dans la prémisse (suppr_prop ne fait rien si le fait n'est pas contenu dans la règle)
            bcCurseur->rgl.prem = suppr_prop(bcCurseur->rgl.prem,bcCurseur->rgl.prem,bfCurseur->contenu);

            bfCurseur = bfCurseur->suiv; 
        }
        bcCurseur = bcCurseur->suiv;
    }

    bcCurseur = bc;
    BF faits_verifies = creer_bf();
    
    while(!bc_est_vide(bcCurseur)){ // traverse la base de connaissances (accède à chaque règle)
        if(prem_est_vide(bcCurseur->rgl.prem)){ // la prémisse est vide de la règle = la conclusion est vérifée
            faits_verifies = ajout_fait_bf(faits_verifies,bcCurseur->rgl.ccl); // on ajoute la conclusion au
        }
        bcCurseur = bcCurseur->suiv;
    }

    return faits_verifies;
}