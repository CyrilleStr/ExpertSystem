#include "bc.h"


BC creer_base(){
    BC nouvBase = NULL;
    return nouvBase;
}

BC ajout_regle(BC b, Regle r){
    if(b == NULL){
        b = creer_base();
        b = (BC) malloc(sizeof(ElemRegle));
        b->rgl = r;
        b->suiv = NULL;
    }else{
        BC curseur = b;
        while(curseur->suiv != NULL){
            curseur = curseur->suiv;
        }
        curseur->suiv = (BC) malloc(sizeof(ElemRegle));
        curseur->suiv->rgl = r;
        curseur->suiv->suiv = NULL;
    }
    return b;
}

Regle regle_tete(BC b){
    return b->rgl;
}

void afficher_bc(BC b){
    if(b==NULL){
        printf("\nLa base de connaissance est vide");
    }else{
        BC curseur = b; 
        printf("\n************Base de connaisannce************");
        while(curseur != NULL){
            afficher_regle(regle_tete(curseur));
            curseur = curseur->suiv;
        }
        printf("\n********************************************");

    }
}