#include "regle.h"

Regle creer_regle(){
    Regle nouvR;
    nouvR.prem = NULL;
    nouvR.ccl = NULL;

    return nouvR;
}

bool regle_est_vide(Regle r){
    return r.prem == NULL && r.ccl == NULL;
}

bool prem_est_vide(Premisse p){
    return p == NULL ;
}

char* contenu(Regle r){
    if(regle_est_vide(r)){
        return NULL;
    }else if(prem_est_vide(r.prem)){
        return NULL;
    }else{
        return r.prem->contenu;
    }
}

char* conclusion(Regle r){
    if(regle_est_vide(r)){
        return NULL;
    }else if(r.ccl != NULL){
        return r.ccl;
    }else{
        return NULL;
    }
}

Regle ajout_proposition(Regle r, char* contenu){
    if(regle_est_vide(r)){ // Première proposition de la règle
        r.prem = (Premisse) malloc(sizeof(Proposition));
        r.prem->contenu  = malloc(strlen(contenu));
        strcpy(r.prem->contenu,contenu);
        r.prem->suiv = NULL;

    }else if(!contient(r.prem, contenu)){ // La règle n'est pas vide et ne contient pas déjà la proposition
        Premisse cruseur = r.prem;
        while(!prem_est_vide(cruseur->suiv)){
            cruseur = cruseur->suiv;
        }
        Premisse nouvProp = (Premisse) malloc(sizeof(Proposition));
        nouvProp->contenu = malloc(strlen(contenu));
        strcpy(nouvProp->contenu,contenu);
        nouvProp->suiv = NULL;
        cruseur->suiv = nouvProp;
    } else {  // la règle contien déjà la proposition
        printf("\nErreur: La proposition existe deja dans cette regle.");
    }

    return r;
}

Regle ajout_conclusion(Regle r, char* contenu){
    r.ccl = (char*) malloc(strlen(contenu));
    strcpy(r.ccl, contenu);

    return r;
}

bool contient(Premisse p, char* prop){
    if(prem_est_vide(p)){
        return false;
    }else{
        if(strcmp(p->contenu,prop) == 0){
            return true;
        }else{
            return contient(p->suiv,prop);
        }
    }
}

Premisse suppr_prop(Premisse p, Premisse ptrOriginal, char* prop){
    if(prem_est_vide(p)){
        return NULL;
    } else {
        // Première proposition
        if(strcmp(p->contenu, prop) == 0){ // La proposition à supprimer est la première
            if(prem_est_vide(p->suiv)){ // il n'y a qu'une seule proposition
                return NULL;
            }else{
                Premisse tmp = p->suiv;
                //free(p->contenu);
                //free(p);
                return tmp;
            }
            
        } else {
            // Propositions suivantes
            if(prem_est_vide(p->suiv)){ // La prémisse contient une seule proposition et la première proposition ne correspondait pas
                return ptrOriginal;
            } else {
                if(strcmp(p->suiv->contenu, prop) == 0){ // Le suivant est à supprimer
                    Premisse tmp = p->suiv->suiv;
                    //free(p->suiv->contenu);
                    //free(p->suiv);
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
    if(prem_est_vide(r.prem) && r.ccl == NULL){
        printf("\nPas d'espace à liberer, la regle est deja vide");
    }else{
        if(r.ccl != NULL){
            //free(r.ccl);
        }
        Premisse curseur = r.prem;
        Premisse tmp = NULL;
        while(!prem_est_vide(curseur)){
            tmp = curseur->suiv;
            //free(curseur->contenu);
            //free(curseur);
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
        if(prem_est_vide(r.prem)){
            printf("\n\tLa premisse est vide.");
        } else {
            Premisse curseur = r.prem;
            int i = 1;
            printf("\n\tPremisse :");
            while(!prem_est_vide(curseur)){
                printf("\n\t\t%d : %s",i,curseur->contenu);
                curseur = curseur->suiv;
                i++;
            }
        }
        // Conclusion
        if(r.ccl == NULL){
            printf("\n\tCette regle ne contient pas de conclusion.");
        } else {
            printf("\n\tConclusion : \n\t\t%s",r.ccl);
        }
        printf("\n\t***********");
    }
}


