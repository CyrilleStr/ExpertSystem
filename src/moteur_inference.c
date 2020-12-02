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
    BF bfCurseur = bf;
    // Premisse tmp = NULL;
    BF bfcurseur = creer_bf();

    while(!bc_est_vide(bcCurseur)){ // traverse la base de connaissance (chaque prémisse des règles de la bc)
        bfcurseur = bf;
        printf("\n*%s",bfcurseur->contenu);
        printf("\n**%s",bcCurseur->rgl.ccl);
        while(!bf_est_vide(bfCurseur)){ // traverse la base de faits (chaque fait)
        
            // supprime la proposition de la règle si le fait est contenu dans la règle (suppr_prop ne fait rien si le fait n'est pas contenu dans la règle)
            bcCurseur->rgl.prem = suppr_prop(bcCurseur->rgl.prem,bcCurseur->rgl.prem,bfcurseur->contenu);

            bfCurseur = bfCurseur->suiv;
        }
        bcCurseur = bcCurseur->suiv;
    }

    afficher_bc(bc);

    bcCurseur = bc;
    BF resultat = creer_bf();
    
    while(!bc_est_vide(bcCurseur)){
        if(prem_est_vide(bcCurseur->rgl.prem)){ // la prémisse est vide, la conclusion est vérifée
            resultat = ajout_fait_bf(resultat,bcCurseur->rgl.ccl);
            printf("\n**%s",bcCurseur->rgl.ccl);
        }
        bcCurseur = bcCurseur->suiv;
    }

    return resultat;
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