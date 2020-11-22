#include "./../lib/regle.h"

/**
 * creer_regle : créer un pointeur (de valeur nulle) sur une liste de proposition
 * @param
 * @return Regle
 */

Regle creer_regle(){
    Regle nouvR = NULL;
    return nouvR;
}

/**
 * est_vide : test si la prémisse d'une Règle est vide
 * @param Regle r
 * @return Boolean (TRUE si vide et FALSE si non vide)
 */

Boolean est_vide(Regle r){
    if(r==NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

/**
 * contenu : accède à la proposition se trouvant en tête d'une prémisse
 * @param Regle r
 * @return string
 */

char* contenu(Regle r){
    if(r==NULL){
        return NULL;
    }else{
      return r->contenu;
    }
}

/**
 * conclusion : accède à la conclusion d'une règle
 * @param Regle r
 * @return string
 */

char* conclusion(Regle r){
    if(est_vide(r)){
        return NULL;
    }else{
        Regle tmp = r;
        while(!est_vide(tmp->suiv)){
            tmp = tmp->suiv;
        }
        return tmp->contenu;
    }
}

/**
 * ajout_proposition : ajoute une proposition à une règle (liste chaînées de proposition)
 * @param Regle r, string prop
 * @return Regle
 */ 

Regle ajout_proposition(Regle r, char* prop){
    if(est_vide(r)){ // Première proposition de la règle
        r = (Regle) malloc(sizeof(Propostition));
        r->contenu  = malloc(strlen(prop));
        strcpy(r->contenu,prop);
        r->suiv = NULL;
    }else{ // La règle n'est pas vide
        Regle tmp = r;
        while(!est_vide(tmp->suiv)){
            tmp = tmp->suiv;
        }
        Regle nouvProp = (Regle) malloc(sizeof(Propostition));
        nouvProp->contenu = malloc(strlen(prop));
        strcpy(nouvProp->contenu,prop);
        nouvProp->suiv = NULL;
        tmp->suiv = nouvProp;
    }
    return r;
}

/**
 * ajout_conclusion : ajoute une conlusion à la fin d'une regle (liste chaînées de proposition)
 * @param Regle r, string ccl
 * @return Boolean (TRUE si l'ajout a été fait et FALSE si l'ajout a échoué)
 */ 

Boolean ajout_conclusion(Regle r, char* ccl){
    if(est_vide(r)){ // On ne pas ajouter une conclusion a une règle sans prémisse
        return FALSE;
    }else{
        Regle tmp = r;
        while(!est_vide(tmp->suiv)){
            tmp = tmp->suiv;
        }
        Regle nouvProp = (Regle) malloc(sizeof(Propostition));
        strcpy(nouvProp->contenu,ccl);
        nouvProp->suiv = NULL;
        tmp->suiv = nouvProp;
        return TRUE;
    }
}

/**
 * contient : test si une proposition appartient à la prémisse d'une règle (algorithme récursif)
 * @param Regle r, string prop
 * @return Boolean (TRUE si la proposition est contenu dans la règle et FALSE si non)
 */

Boolean contient(Regle r, char* prop){
    if(est_vide(r)){
        return FALSE;
    }else{
        if(strcmp(r->contenu,prop)==0){
            return TRUE;
        }else{
            return contient(r->suiv,prop);
        }
    }
}

/**
 * suppr_prop : supprime une proposition de la prémisse d'une règle
 * @param Regle r, Regle p(permet de traverser une règle en gardant r intacte), string prop
 * @return Regle (La règle si la proposition est contenu dans la règle et a bien été supprimé et NULL si non)
 */

Regle suppr_prop(Regle r, Regle p, char* prop){
    if(est_vide(r) || est_vide(p)){
        return NULL;
    }else{
        if(strcmp(r->contenu,prop)==0){
            Regle tmp = r->suiv;
            free(r);
            return tmp;
        }else{
            if(est_vide(p->suiv)){
                return NULL;
            }else{
                if(strcmp(p->suiv->contenu,prop)==0){
                    Regle tmp = NULL;
                    if(!est_vide(p->suiv->suiv)){
                        tmp = p->suiv->suiv;
                    }
                    free(p->suiv);
                    p->suiv = tmp;
                    return r;
                }else{
                    return suppr_prop(r,p->suiv,prop);
                }
            }
        }
    }
} // Pb: cet algo peut supprimer la ccl

void afficher_regle(Regle r){
    if(r==NULL){
        printf("\n\nLa regle est vide");
    }else{
        printf("\n\n***Regle***");
        Regle tmp = r;
        if(est_vide(tmp->suiv)){
            printf("\nCette regle ne contient pas de conclusion");
            printf("\nProposition 1: %s",tmp->contenu);
        }else{
            printf("\nPremisse :");
            int i = 1;
            while(!est_vide(tmp->suiv->suiv)){
                printf("\n\t%d : %s",i,tmp->contenu);
                i++;
                tmp = tmp->suiv;
            }
            printf("\n\t%d : %s",i,tmp->contenu);
            printf("\nConclusion : \n\t%s",tmp->suiv->contenu);
        }
        printf("\n***********");
    }
}


