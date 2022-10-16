//
// Created by MICHEL on 2022/10/15.
//

#ifndef ALGO_TD5_PILE_H
#define ALGO_TD5_PILE_H
typedef int TypeDonnee;
// réprésentation contigue
typedef struct {
    int nb_elem;
    int nb_elem_max;
    TypeDonnee *tab;
}Pile;
Pile initialiser(int nb_max);
int EstVide(Pile p);
int EstPlein(Pile P);
TypeDonnee AccederSommet(Pile p);
void Empiler(Pile *p, TypeDonnee donnee);
void DePiler(Pile *p, TypeDonnee* donnee);
void Vider(Pile *p);
void Detruire(Pile*p);
void affiche(Pile p);
// une liste avec l'adresse de la tete
typedef struct Cell TypeCellule;
struct Cell{
    TypeDonnee donnee;
    TypeCellule*suivant;
};
typedef TypeCellule* Pile_LC; //le pointeur de l'adresse de la tete
Pile_LC initPile();
int estVide_LC(Pile_LC pileLc);
int estPlein_LC(Pile_LC pileLc);
TypeDonnee sommetPile(Pile_LC pileLc);
void empiler_LC(Pile_LC *pileLc,TypeDonnee donnee);
void depiler_LC(Pile_LC *pileLc,TypeDonnee* donnee);
void Affichierpile(Pile_LC p);

// une liste avec l'adresse de la tete et de la queue
typedef struct Element Element;
struct Element{
    TypeDonnee donnee;
    Element*suivant;
};
typedef struct {
    Element*premier;
    Element*dernier;
    int cnt;
}Pile_Liste;
Pile_Liste*initPile_Liste();
int estVide_pile_Liste(Pile_Liste pileListe);
TypeDonnee sommetPile_liste(Pile_Liste pileListe);
void empile_Liste(Pile_Liste*pileListe,TypeDonnee donnee);
void depile_Liste(Pile_Liste*pileListe,TypeDonnee*donnee);
void Affiche(Pile_Liste pileListe);
// Une liste circulaire caractérise avec l'adresse de la queue
typedef struct studio Elt;
struct studio{
    TypeDonnee typeDonnee;
    Elt* suivant;
};
typedef struct {
     Elt*premier;
     int cnt;
}Pile_circulaire;
Pile_circulaire*initPile_c();
int estVide_pile_c(Pile_circulaire pileCirculaire);
void empile_circulaire(Pile_circulaire*pileCirculaire,TypeDonnee donnee);
void depile_circulaire(Pile_circulaire*pileCirculaire,TypeDonnee*donnee);
void affiche_c(Pile_circulaire pileCirculaire);

#endif //ALGO_TD5_PILE_H
