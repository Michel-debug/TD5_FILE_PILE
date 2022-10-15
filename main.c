#include <stdio.h>
#include "Pile.h"
#include <stdlib.h>
//Contigue pour pile
Pile initialiser(int nb_max){
    Pile pile;
    pile.nb_elem = 0;
    pile.nb_elem_max = nb_max;
    pile.tab = (TypeDonnee *) malloc( nb_max* sizeof(TypeDonnee));
    return pile;
}
int EstVide(Pile p){
    return p.nb_elem==0;
}
int EstPlein(Pile p){
    return p.nb_elem>=p.nb_elem_max;
}
TypeDonnee AccederSommet(Pile p){
    if(EstVide(p)){
        printf("Pile est vide !");
        exit(0);
    }
    return p.tab[p.nb_elem-1];
}
void Empiler(Pile *p,TypeDonnee donnee){
    if(!EstPlein(*p)){
        (*p).tab[(*p).nb_elem++]=donnee;
    }else{
        printf("Echec de l'insertion");
    }
}
void DePiler(Pile *p,TypeDonnee* donnee){
    if(EstVide(*p)){
        printf("rien dans cette pile");
    }else{
        *donnee=p->tab[p->nb_elem-1];
        p->nb_elem--;
    }
}
void Vider(Pile *p){
    p->nb_elem=0;
}
void Detruire(Pile *p){
    if(p->nb_elem_max!=0){
        free(p->tab);
        p->nb_elem=0;
        p->nb_elem_max=0;
    }
}
//Liste simple avec l'adresse de la tete
Pile_LC initPile(){
    return NULL;
}

int estVide_LC(Pile_LC pileLc){
    return pileLc==NULL;
}
int estPlein_LC(Pile_LC pileLc){
    return 0; // jamais plein
}
TypeDonnee sommetPile(Pile_LC pileLc){
    if(!estVide_LC(pileLc)) {
        return pileLc->donnee;
    } else{
        printf("vide");
        exit(0);
    }
}
void empiler_LC(Pile_LC *pileLc,TypeDonnee donnee){
    Pile_LC q;
    q = (TypeCellule*)malloc(sizeof(TypeCellule));
    q->donnee = donnee;
    q->suivant = *pileLc;
    *pileLc = q; // mise a jour de la tete de liste;
}
void depiler_LC(Pile_LC *pileLc, TypeDonnee * donnee){
     if(!estVide_LC((*pileLc))){
         Pile_LC p;
         *donnee=(*pileLc)->donnee;
         p=*pileLc;
         *pileLc=(*pileLc)->suivant;
         free(p);
     }
}
void Affichierpile(Pile_LC p){
    while(p!=NULL){
        printf("%f\t",p->donnee);
        p=p->suivant;
    }
    puts("");
}
int main() {
    printf("Hello, World!\n");
    return 0;
}
