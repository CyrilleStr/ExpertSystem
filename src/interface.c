#include "interface.h"

void pause(){
    char enter = 0;
    printf("\nAppuiez sur Entrer pour continer");
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    effacer_terminal();
}

void afficher_bc(BC bc){
    if(bc_est_vide(bc)){
        printf("\nLa base de connaissance est vide");
    }else{
        BC curseur = bc; 
        printf("\n************Base de connaisannce************");
        while(!bc_est_vide(curseur)){
            afficher_regle(regle_tete_bc(curseur));
            curseur = curseur->suiv;
        }
        printf("\n********************************************");
    }
}

void afficher_regle(Regle r){
    if(regle_est_vide(r)){
        printf("\n\n\tLa regle est vide");
    }else{
        printf("\n\n\t***Regle***");
        Regle curseur = r;
        int i = 1;
        printf("\n\tPremisse :");
        while(!regle_est_vide(curseur->suiv)){
            printf("\n\t\t%d : %s",i,contenu(curseur));
            if(curseur->valeur){
                printf(" (vrai)");
            }else{
                printf(" (faux)");
            }
            curseur = curseur->suiv;
            i++;
        }
        printf("\n\tConclusion :");
        printf("\n\t\t%s",contenu(curseur));
    }
}

void afficher_bf(Regle bf){
    printf("\n************Base de faits*******************");
    if(regle_est_vide(bf)){
        printf("\nLa base de fait est vide");
    }else{
        Regle curseur = bf;
        while(!regle_est_vide(curseur)){
            printf("\n\t%s",curseur->contenu);
            curseur = curseur->suiv;
        }
    }
    printf("\n********************************************");

}