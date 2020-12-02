#include "moteur_inference.h"

BF creer_bf(){
    BF b = NULL;
    return b;
}

bool bf_est_vide(BF b){
    return b == NULL;
}

BF ajout_fait_bf(BF b, char* contenu){
    if(bf_est_vide(b)){
        b = (BF) malloc(sizeof(Proposition));
        b->contenu = malloc(strlen(contenu));
        strcpy(b->contenu,contenu);
        b->suiv = NULL;
    }else{
        BF curseur = b;
        while(!bf_est_vide(curseur->suiv)){
            curseur = curseur->suiv;
        }
        BF nouvFait = (BF) malloc(sizeof(Proposition));
        nouvFait->contenu = malloc(strlen(contenu));
        strcpy(nouvFait->contenu,contenu);
        nouvFait->suiv = NULL;
        curseur->suiv = nouvFait; 
    }
    return b;
}

void afficher_bf(BF b){
    if(bf_est_vide(b)){
        printf("\nLa base de faits est vide");
    }else{
        BF curseur = b; 
        printf("\n************Base de faits************");
        while(curseur != NULL){
            printf("\n\t%s",curseur->contenu);
            curseur = curseur->suiv;
        }
        printf("\n*************************************");
    }
}

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

void suppr_bf(BF b){
    if(bf_est_vide(b)){
        printf("\nPas d'espace à liberer, la base de faits est deja vide");
    }else{
        BF curseur = b;
        BF tmp = NULL;
        while(!bf_est_vide(curseur)){
            tmp = curseur->suiv;
            free(curseur->contenu);
            free(curseur);
            curseur = tmp;
        }
        printf("\nBase de faits supprimee correctement");
    }
}