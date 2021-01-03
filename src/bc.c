#include <bc.h>

BC creer_bc(){
    BC nouvBase = NULL;
    return nouvBase;
}

bool bc_est_vide(BC b){
    return b == NULL;
}

BC ajout_regle_bc(BC b, Regle r){
    if(bc_est_vide(b)){
        b = creer_bc();
        b = (BC) malloc(sizeof(ElemRegle));
        b->rgl = r;
        b->suiv = NULL;
    }else{
        BC curseur = b;
        while(!bc_est_vide(curseur->suiv)){
            curseur = curseur->suiv;
        }
        curseur->suiv = (BC) malloc(sizeof(ElemRegle));
        curseur->suiv->rgl = r;
        curseur->suiv->suiv = NULL;
    }
    return b;
}

Regle regle_tete_bc(BC b){
    return b->rgl;
}

void suppr_bc(BC b){
    if(bc_est_vide(b)){
        printf("\nPas d'espace à liberer, la base de connaissance est deja vide");
    }else{
        BC tmp = NULL;
        BC curseur = b;
        while(!bc_est_vide(curseur)){
            tmp = curseur->suiv;
            suppr_regle(curseur->rgl);
            free(curseur);
            curseur = tmp;
        }
        printf("\nBase de connaissances supprimee correctement");
    }
}
