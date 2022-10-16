#include <stdio.h>
#include "Pile.h"
#include <stdlib.h>
#include "File.h"
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
void affiche(Pile p){
    if(p.nb_elem==0){
        printf("vide\n");
        return;
    }
    for (int i = 0; i < p.nb_elem-1; ++i) {
        printf("%d<-",p.tab[i]);
    }
    printf("%d\n",p.tab[p.nb_elem-1]);
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
    while(p->suivant!=NULL){
        printf("%d->",p->donnee);
        p=p->suivant;
    }
    printf("%d",p->donnee);
    puts("");
}

// une liste avec l'adresse de la tete et de la queue
Pile_Liste*initPile_Liste(){
    Pile_Liste*pileListe = malloc(sizeof(*pileListe));
    if(pileListe==NULL){
        printf("creer avec un echec");
        exit(EXIT_FAILURE);
    }
    pileListe->cnt=0;
    pileListe->premier=NULL;
    pileListe->dernier=NULL;
    return pileListe;
}
int estVide_pile_Liste(Pile_Liste pileListe){
    return pileListe.cnt==0;
}
TypeDonnee sommetPile_liste(Pile_Liste pileListe){
    if(estVide_pile_Liste(pileListe)){
        printf("vide");
        exit(0);
    }
    return pileListe.premier->donnee;
}
void empile_Liste(Pile_Liste*pileListe,TypeDonnee donnee){
     Element* element = malloc(sizeof(*element));
     if(element==NULL) exit(0);
     element->donnee = donnee;
     if(estVide_pile_Liste(*pileListe)){
         pileListe->premier=pileListe->dernier=element;
     }else{
         pileListe->dernier->suivant = element;
         pileListe->dernier=element;
     }
     pileListe->cnt++;
}
void depile_Liste(Pile_Liste*pileListe,TypeDonnee*donnee){
    if(!estVide_pile_Liste(*pileListe)){
        Element *p = pileListe->dernier;
        Element *q = pileListe->premier;
        *donnee=p->donnee;
        if(pileListe->cnt==1){
            pileListe->cnt=0;
            pileListe->dernier=pileListe->dernier=NULL;
            free(pileListe);
            return;
        }
        while(q->suivant!=pileListe->dernier){
            q=q->suivant;
        }
        pileListe->cnt--;
        pileListe->dernier=q;
        q->suivant=NULL;
        free(p);

    }
}
void Affiche(Pile_Liste pileListe){
    Element* e = pileListe.premier;
    while(e!=pileListe.dernier){
        printf("%d<-",e->donnee);
        e=e->suivant;
    }
    printf("%d\n",e->donnee);
}
// Une liste circulaire caractérise avec l'adresse de la queue
Pile_circulaire*initPile_c(){
    Pile_circulaire*pileCirculaire=malloc(sizeof(*pileCirculaire));
    if(pileCirculaire==NULL) {
            printf("creer avec un echec");
            exit(EXIT_FAILURE);
        }
    pileCirculaire->premier=NULL;
    pileCirculaire->cnt=0;
    return pileCirculaire;
}
int estVide_pile_c(Pile_circulaire pileCirculaire){
    return pileCirculaire.cnt==0;
}
void empile_circulaire(Pile_circulaire*pileCirculaire,TypeDonnee donnee){
    Elt*element = malloc(sizeof(*element));
    if(element==NULL){
        printf("creer avec un echec");
        exit(EXIT_FAILURE);
    }
    element->typeDonnee=donnee;
    if(estVide_pile_c(*pileCirculaire)){
        pileCirculaire->premier=element;
        element->suivant=element;
    }else{
        element->suivant=pileCirculaire->premier;
        Elt *inteval = pileCirculaire->premier;
        while(inteval->suivant!=pileCirculaire->premier){
            inteval=inteval->suivant;
        }
        pileCirculaire->premier=element;
        inteval->suivant=pileCirculaire->premier;
    }
    pileCirculaire->cnt++;
}
void depile_circulaire(Pile_circulaire*pileCirculaire,TypeDonnee*donnee){
    if(!estVide_pile_c(*pileCirculaire)) {
        Elt *e = pileCirculaire->premier;
        Elt *e2 = pileCirculaire->premier;
        *donnee=e->typeDonnee;
        if(e->suivant==pileCirculaire->premier){
            free(e);
            pileCirculaire->premier=NULL;
            pileCirculaire->cnt=0;
            return;
        }
        while(e2->suivant!=pileCirculaire->premier){
            e2=e2->suivant;
        }
        e2->suivant=e->suivant;
        pileCirculaire->premier=e->suivant;
        free(e);
        pileCirculaire->cnt--;
    }
}
void affiche_c(Pile_circulaire pileCirculaire){
    Elt* e = pileCirculaire.premier;
    do{
        printf("%d->",e->typeDonnee);
        e=e->suivant;
    }while(e->suivant!=pileCirculaire.premier);
    printf("%d\n",e->typeDonnee);
}


//File  avec simple Liste;
File initFile(){
    File filevide;
    filevide.tete=NULL;
    return filevide;
}
int estVideF(File F){
    return F.tete==NULL;
}
int estPleinF(File F){
    return 0;
}
TypeDonnee sommetFile(File F){
    if(estVideF(F)){
        printf("vide");
        exit(0);
    }
    return F.tete->donnee;
}
void emFiler(File *F,TypeDonnee typeDonnee){
   TypeCellule_F *typeCelluleF = malloc(sizeof(*typeCelluleF));
   if(F==NULL){
       exit(0);
   }
   typeCelluleF->donnee=typeDonnee;
   typeCelluleF->suivant=NULL;
   if(F->tete==NULL){
       F->tete=typeCelluleF;
   }else{
       TypeCellule_F *q = F->tete;
       while(q->suivant!=NULL){
           q=q->suivant;
       }
       q->suivant=typeCelluleF;
   }
}
void defiler(File *F,TypeDonnee* typeDonnee){
    if(!estVideF(*F)){
        TypeCellule_F *q = F->tete;
        *typeDonnee = q->donnee;
        F->tete=q->suivant;
        free(q);
    }
}
void afficheFile(File F){
    TypeCellule_F*typeCelluleF = F.tete;
    while(typeCelluleF->suivant!=NULL){
        printf("%d<-",typeCelluleF->donnee);
        typeCelluleF=typeCelluleF->suivant;
    }
    printf("%d\n",typeCelluleF->donnee);
    puts("");
}

//File avec tete et queue;
File2 initFile2(){
    File2 file2;
    file2.tete=NULL;
    file2.queue=NULL;
    return file2;
}
int estVideF2(File2 F){
    return F.tete==NULL;
}
void emFiler2(File2 *F,TypeDonnee typeDonnee){
    TypeCellule_F* typeCelluleF = malloc(sizeof(*typeCelluleF));
    if(F==NULL){
        exit(0);
    }
    typeCelluleF->donnee=typeDonnee;
    typeCelluleF->suivant=NULL;
    if(F->tete==NULL){
        F->tete=F->queue=typeCelluleF;
    }else{
        F->queue->suivant=typeCelluleF;
        F->queue=typeCelluleF;
    }
}
void defiler2(File2 *F,TypeDonnee* typeDonnee){
    if(!estVideF2(*F)){
        TypeCellule_F * typeCelluleF = F->tete;
        F->tete=F->tete->suivant;
        free(typeCelluleF);
    }
}
void afficheFile2(File2 F){
    TypeCellule_F*typeCelluleF = F.tete;
    while(typeCelluleF!=F.queue){
        printf("%d<-",typeCelluleF->donnee);
        typeCelluleF=typeCelluleF->suivant;
    }
    printf("%d\n",typeCelluleF->donnee);
    puts("");
}

// File avec une liste  circulaire avec adresse de tete et adresse de queue;
void emFiler_ciculaire(File*F,TypeDonnee typeDonnee){
    TypeCellule_F *typeCelluleF = malloc(sizeof(*typeCelluleF));
    if(F==NULL){
        exit(0);
    }
    typeCelluleF->donnee=typeDonnee;
    if(F->tete==NULL){
        F->tete=typeCelluleF;
        typeCelluleF->suivant=F->tete;
    }else{
        TypeCellule_F *q = F->tete;
        while(q->suivant!=F->tete){
            q=q->suivant;
        }
        q->suivant=typeCelluleF;
        typeCelluleF->suivant=F->tete;
        F->tete=typeCelluleF;
    }
}
void deFiler_ciculaire(File*F,TypeDonnee*typeDonnee){
    if(!estVideF(*F)){
        TypeCellule_F *q = F->tete;
        TypeCellule_F *p =F->tete;
        if(p->suivant==F->tete){
            *typeDonnee = F->tete->donnee;
            free(q);
            F->tete=NULL;
            return;
        }
        while(p->suivant->suivant!=F->tete){
            p=p->suivant;
        }
        *typeDonnee = p->suivant->donnee;
        q = p->suivant;
        p->suivant=F->tete;
        free(q);
    }
}
void affiche_cirule(File F){
    TypeCellule_F*f1 = F.tete;
    while(f1->suivant!=F.tete){
        printf("%d->",f1->donnee);
        f1=f1->suivant;
    }
    printf("%d",f1->donnee);
}
void affiche_cirule2(File2 F);
void emFiler2_ciculaire(File2*F,TypeDonnee typeDonnee){

}
void deFiler2_ciculaire(File2*F, TypeDonnee*typeDonnee){

}

int main() {
    //Test 1 pour contigue
    Pile p = initialiser(10);
    Empiler(&p,12);Empiler(&p,18);Empiler(&p,17); Empiler(&p,16); Empiler(&p,13);
    affiche(p);
    TypeDonnee recus;
    DePiler(&p,&recus);
    affiche(p); printf("supprimer:%d\n",recus);
    Detruire(&p);
    affiche(p);
    //Test 2 pour simple List avec l'adresse de la tete
    Pile_LC pileLc = initPile();
    empiler_LC(&pileLc,20);
    empiler_LC(&pileLc,7);
    empiler_LC(&pileLc,12);
    empiler_LC(&pileLc,17);
    empiler_LC(&pileLc,21);
    Affichierpile(pileLc);
    depiler_LC(&pileLc,&recus);
    Affichierpile(pileLc);
    printf("supprimer:%d\n",recus);
    //Test 3 pour List avec l'adresse de la tete et la queue;
    Pile_Liste*pileListe=initPile_Liste();
    empile_Liste(pileListe,12);
    empile_Liste(pileListe,13);
    empile_Liste(pileListe,14);
    empile_Liste(pileListe,15);
    empile_Liste(pileListe,16);
    Affiche(*pileListe);
    depile_Liste(pileListe,&recus);
    printf("supprimer:%d\n",recus);
    Affiche(*pileListe);
    //Test 4 pour list circulaire realisant pile;
    puts("-------------------------");
    Pile_circulaire*pileCirculaire = initPile_c();
    empile_circulaire(pileCirculaire,12);
    empile_circulaire(pileCirculaire,17);
    empile_circulaire(pileCirculaire,19);
    empile_circulaire(pileCirculaire,20);
    affiche_c(*pileCirculaire);
    depile_circulaire(pileCirculaire,&recus);
    affiche_c(*pileCirculaire);
    printf("supprimer:%d\n",recus);
    puts("-----File------");
    File F = initFile();
    emFiler(&F,11); emFiler(&F,12); emFiler(&F,13);  emFiler(&F,14);  emFiler(&F,15);
    afficheFile(F);
    defiler(&F,&recus);
    printf("supprimer:%d\n",recus);
    afficheFile(F);
    File2 F2 = initFile2();
    emFiler2(&F2,11);
    emFiler2(&F2,21);
    emFiler2(&F2,31);
    emFiler2(&F2,41);
    emFiler2(&F2,51);
    afficheFile2(F2);
    defiler2(&F2,&recus);
    printf("supprimer:%d\n",recus);
    afficheFile2(F2);
    puts("--------------File circul------------");
    File F3 = initFile();
    emFiler_ciculaire(&F3,11); emFiler_ciculaire(&F3,12); emFiler_ciculaire(&F3,13);  emFiler_ciculaire(&F3,14);  emFiler_ciculaire(&F3,15);
    affiche_cirule(F3);
    deFiler_ciculaire(&F3,&recus);
    printf("\nsupprimer:%d\n",recus);
    affiche_cirule(F3);
    return 0;
}
