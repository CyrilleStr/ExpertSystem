#include "regle.h"

int main(){

    printf("Creation regle vide");
    Regle r = creer_regle();
    char input[40];

    printf("\nAjout proposition 1 : ");
    gets(input);
    r = ajout_proposition(r,input);


    printf("\nAjout proposition 2 : ");
    gets(input);
    r = ajout_proposition(r,input);

    
    printf("\nAjout proposition 3 : ");
    gets(input);
    r = ajout_proposition(r,input);
    
    printf("\nAjout conclusion: ");
    gets(input);
    r = ajout_conclusion(r, input);
    
    afficher_regle(r);
    
    printf("\nProposition a chercher dans la premisse : ");
    gets(input);
    if(contient(r.prem,input)){
        printf("\nCette proposition est bien dans la premisse de cette regle");
    }else{
        printf("\nCette proposition n'est pas dans la premisse de cette regle");
    }

    printf("\nProposition a supprimer :");
    gets(input);
    Premisse tmp = suppr_prop(r.prem,r.prem,input);
    if(tmp == NULL){
        printf("\nCet proposition n'est pas contenu dans cette règle");
    }else{
        r.prem = tmp;
    }

    afficher_regle(r);

    tmp = NULL;
    while(r.prem->suiv == NULL){
        tmp = r.prem->suiv;
        free(r.prem);
        r.prem = tmp;
    }
    printf("\nEspace libere");
    return 0;
}