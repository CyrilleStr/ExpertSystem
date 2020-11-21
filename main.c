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
    scanf("%s",input);
    if(!ajout_conclusion(r,input)){
        printf("\nEchec de l'ajout de la conclusion");
    }

    afficher_regle(r);

    Regle tmp;
    while(!est_vide(r)){
        tmp = r->suiv;
        free(r);
        r = tmp;
    }
    printf("\nEspace libere");
    return 0;
}