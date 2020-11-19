#include "regle.h"

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
    return r->contenu;
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
        while(!est_vide(tmp)){
            tmp = tmp->suiv;
        }
        return tmp->contenu;
    }
}

/**
 * ajout_proposition : ajoute une proposition à une règle (liste chaînées de proposition)
 * @param Regle r, string prop
 * @return void
 */ 

void ajout_proposition(Regle r, char* prop){
    if(est_vide(r)){ // Première proposition de la règle
        r = (Regle) malloc(sizeof(Propostition));
        r->contenu = prop;
        r->suiv = NULL;
    }else{ // La règle n'est pas vide
        Regle tmp = r;
        while(!est_vide(tmp)){
            tmp = tmp->suiv;
        }
        Regle nouvProp = (Regle) malloc(sizeof(Propostition));
        nouvProp->contenu = prop;
        nouvProp->suiv = NULL;
        tmp->suiv = nouvProp;   
    }
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
        while(!est_vide(tmp)){
            tmp = tmp->suiv;
        }
        Regle nouvProp = (Regle) malloc(sizeof(Propostition));
        nouvProp->contenu = ccl;
        nouvProp->suiv = NULL;
        tmp->suiv = nouvProp;   
    }
}

/**
 * contient : test si une proposition appartient à la prémisse d'une règle
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
 * @param Regle r, string prop
 * @return Boolean (TRUE si la proposition est contenu dans la règle et a bien été supprimé et FALSE si non)
 */

Boolean suppr_prop(Regle r, char* prop){
    if(est_vide(r)){
        return FALSE;
    }else{
        if(strcmp(r->contenu,prop)==0){
            // pas fini
            r->suiv;
            free(r);
            return TRUE;
        }else{
            return suppr_prop(r->suiv,prop);
        }
    }
}
