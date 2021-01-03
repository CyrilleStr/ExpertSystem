#include <regle.h>

Regle creer_regle(){
    Regle nouvR = NULL;
    return nouvR;
}

bool regle_est_vide(Regle r){
    return r == NULL;
}

char* contenu(Regle r){
    if(regle_est_vide(r)){
        return NULL;
    }else{
        return r->contenu;
    }
}

char* valeur(Regle r){
    if(r->valeur){
        return "vrai";
    }else{
        return "faux";
    }
}

char* conclusion(Regle r){
    if(regle_est_vide(r)){
        return NULL;
    }else{
        Regle curseur = r;
        while(!regle_est_vide(curseur->suiv)){
            curseur = curseur->suiv;
        }
        return curseur->contenu;
    }
}

Regle ajout_proposition(Regle r, char* contenu, bool valeur){
    if(regle_est_vide(r)){ // Première proposition de la règle
        r = (Proposition*) malloc(sizeof(Proposition));
        r->contenu  = malloc(strlen(contenu)+1);
        strcpy(r->contenu,contenu);
        r->valeur = valeur;
        r->suiv = NULL;

    }else if(!contient(r, contenu)){ // La règle n'est pas vide et ne contient pas déjà la proposition
        Regle curseur = r;
        while(!regle_est_vide(curseur->suiv)){
            curseur = curseur->suiv;
        }
        Proposition* nouvProp = (Proposition*) malloc(sizeof(Proposition));
        nouvProp->contenu = malloc(strlen(contenu)+1);
        strcpy(nouvProp->contenu,contenu);
        nouvProp->valeur = valeur;
        nouvProp->suiv = NULL;
        curseur->suiv = nouvProp;
    } else {  // la règle contient déjà la proposition
        printf("\nErreur: La proposition existe deja dans cette regle.");
    }

    return r;
}

Regle ajout_conclusion(Regle r, char* contenu){
    return ajout_proposition(r,contenu,true);
}

bool contient(Regle r, char* prop){
    if(regle_est_vide(r)){
        return false;
    }else{
        if(strcmp(r->contenu,prop) == 0){
            return true;
        }else{
            return contient(r->suiv,prop);
        }
    }
}

Regle suppr_prop(Regle p, Regle ptrOriginal, char* prop){
    if(regle_est_vide(p)){
        return NULL;
    } else {
        // Première proposition
        if(strcmp(p->contenu, prop) == 0){ // La proposition à supprimer est la première
            if(regle_est_vide(p->suiv)){ // il n'y a qu'une seule proposition
                return NULL;
            }else{
                Regle tmp = p->suiv;
                free(p->contenu);
                free(p);
                return tmp;
            }
            
        } else {
            // Propositions suivantes
            if(regle_est_vide(p->suiv)){ // La prémisse contient une seule proposition et la première proposition ne correspondait pas
                return ptrOriginal;
            } else {
                if(strcmp(p->suiv->contenu, prop) == 0){ // Le suivant est à supprimer
                    Regle tmp = p->suiv->suiv;
                    free(p->suiv->contenu);
                    free(p->suiv);
                    p->suiv = tmp;
                    return ptrOriginal;
                }else{
                    return suppr_prop(p->suiv, ptrOriginal, prop);
                }
            }
        }
    }
}

void suppr_regle(Regle r){
    if(regle_est_vide(r)){
        printf("\nPas d'espace à liberer, la regle est deja vide");
    }else{
        Regle curseur = r;
        Regle tmp = NULL;
        while(!regle_est_vide(curseur)){
            tmp = curseur->suiv;
            free(curseur->contenu);
            free(curseur);
            curseur = tmp;
        }
    }
}

void afficher_regle(Regle r){
    if(regle_est_vide(r)){
        printf("\n\n\tLa regle est vide");
    }else{
        printf("\n\n\t***Regle***");
        // Prémisse
        if(regle_est_vide(r)){
            printf("\n\tLa premisse est vide.");
        } else {
            Regle curseur = r;
            int i = 1;
            printf("\n\tPremisse :");
            while(!regle_est_vide(curseur->suiv)){
                printf("\n\t\t%d : %s",i,curseur->contenu);
                if(curseur->valeur){
                    printf(" (vrai)");
                }else{
                    printf(" (faux)");
                }
                curseur = curseur->suiv;
                i++;
            }
            printf("\n\tConclusion :");
            printf("\n\t\t%s",curseur->contenu);
        }
    }
}


