#include "regle.h"

Regle creer_regle(){
    Regle nouvR;
    nouvR.prem = NULL;
    nouvR.ccl = NULL;

    return nouvR;
}

bool est_vide(Regle r){
    if(r.prem == NULL && r.ccl == NULL){
        return true;
    }else{
        return false;
    }
}

char* contenu(Regle r){
    if(est_vide(r)){
        return NULL;
    }else{
      return r.prem->contenu;
    }
}

char* conclusion(Regle r){
    if(est_vide(r)){
        return NULL;
    }else{
        return r.ccl;
    }
}

Regle ajout_proposition(Regle r, char* prop){
    if(est_vide(r)){ // Première proposition de la règle
        r.prem = (Premisse) malloc(sizeof(Propostition));
        r.prem->contenu  = malloc(strlen(prop));
        strcpy(r.prem->contenu,prop);
        r.prem->suiv = NULL;

    }else if(!contient(r.prem, prop)){ // La règle n'est pas vide
        Premisse tmp = r.prem;
        while(tmp->suiv!=NULL){
            tmp = tmp->suiv;
        }
        Premisse nouvProp = (Premisse) malloc(sizeof(Propostition));
        nouvProp->contenu = malloc(strlen(prop));
        strcpy(nouvProp->contenu,prop);
        nouvProp->suiv = NULL;
        tmp->suiv = nouvProp;
    } else {
        printf("\nErreur: La proposition existe deja dans cette regle.");
    }

    return r;
}

Regle ajout_conclusion(Regle r, char* ccl){
    r.ccl = malloc(strlen(ccl));
    strcpy(r.ccl, ccl);

    return r;
}

bool contient(Premisse p, char* prop){
    if(p == NULL){
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
    if(p == NULL){
        return NULL;
    } else {
        // Première proposition
        Premisse pointeur = p->suiv;
        if(strcmp(p->contenu, prop) == 0){ // Les deux chaînes sont identiques
            
            free(p);
            return pointeur;
        } else {
            // Propositions suivantes
            if(pointeur == NULL){
                return NULL; // La prémisse contient une seule proposition et la première proposition ne correspondait pas.
            } else {
                if(strcmp(p->suiv->contenu, prop) == 0){ // Le suivant est à supprimer
                    
                    pointeur = p->suiv->suiv;
                    free(p->suiv);
                    p->suiv = pointeur;
                    return ptrOriginal;
                }else{
                    return suppr_prop(p->suiv, ptrOriginal, prop);
                }
            }
        }
    }
}

void libere_regle(Regle r){
    if(r.prem == NULL && r.ccl ==NULL){
        printf("\nPas d'espace à liberer, la regle est deja vide");
    }else{
        if(r.ccl != NULL){
            free(r.ccl);
        }
        Premisse curseur = NULL;
        Premisse tmp = NULL;
        curseur = r.prem;
        while(curseur != NULL){
            tmp = curseur->suiv;
            free(curseur->contenu);
            free(curseur);
            curseur = tmp;
        }
        printf("\nRegle libere correctement");
    }
}

void afficher_regle(Regle r){
    if(est_vide(r)){
        printf("\n\n\tLa regle est vide");
    }else{
        printf("\n\n\t***Regle***");
        // Prémisse
        if(r.prem->contenu == NULL){
            printf("\n\tLa premisse est vide.");
        } else {
            Premisse cursor = r.prem;
            int i = 1;
            printf("\n\tPremisse :");
            while(cursor != NULL){
                printf("\n\t\t%d : %s",i,cursor->contenu);
                cursor = cursor->suiv;
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

