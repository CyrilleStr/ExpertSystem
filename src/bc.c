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

void liberer_base(BC b){
    if(b==NULL){
        printf("\nPas d'espace à liberer, la base de connaissance est deja vide");
    }else{
        BC tmp = NULL;
        BC curseur = b;
        while(curseur != NULL){
            tmp = curseur->suiv;
            libere_regle(curseur->rgl);
            free(curseur);
            curseur = tmp;
        }
        printf("\nBase de connaissance liberee correctement");
    }
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