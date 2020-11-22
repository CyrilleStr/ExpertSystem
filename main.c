#include "regle.h"

int main(){

    printf("Creation regle vide");
    Regle r = creer_regle();
    char input[40]; //accepte pas les espaces

    printf("\nAjout proposition 1 :");
    gets(input);
    r = ajout_proposition(r,input);

    printf("\nAjout proposition 2 :");
    gets(input);
    r = ajout_proposition(r,input);

    printf("\nAjout proposition 3 :");
    gets(input);
    r = ajout_proposition(r,input);
    
    printf("\nAjout conclusion:");
    gets(input);
    if(!ajout_conclusion(r,input)){
        printf("\nEchec de l'ajout de la conclusion");
    }

    afficher_regle(r);

    printf("\nProposition a chercher dans la premisse :");
    gets(input);
    if(contient(r,input)){
        printf("\nCette proposition est bien dans la premisse de cette regle");
    }else{
        printf("\nCette proposition n'est pas dans la premisse de cette regle");
    }

    printf("\nProposition a supprimer :");
    gets(input);
    if(!(r = suppr_prop(r,r,input))){
        printf("\nCet proposition n'est pas contenu dans cette règle");
    }

    afficher_regle(r);

    Regle tmp=NULL;
    while(!est_vide(r->suiv)){
        tmp = r->suiv;
        free(r);
        r = tmp;
    }
    printf("\nEspace libere");
    return 0;
}