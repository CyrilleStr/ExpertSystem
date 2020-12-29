#include "bf.h"

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

void suppr_bf(BF b){
    if(bf_est_vide(b)){
        printf("\nPas d'espace à liberer, la base de faits est deja vide");
    }else{
        BF curseur = b;
        BF tmp = NULL;
        while(!bf_est_vide(curseur)){
            tmp = curseur->suiv;
            //free(curseur->contenu);
            //free(curseur);
            curseur = tmp;
        }
        printf("\nBase de faits supprimee correctement");
    }
}