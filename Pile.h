//
// Created by MICHEL on 2022/10/15.
//

#ifndef ALGO_TD5_PILE_H
#define ALGO_TD5_PILE_H
typedef float TypeDonnee;
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

// une liste avec l'adresse de la tete
typedef struct Cell TypeCellule;
typedef struct Cell{
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
#endif //ALGO_TD5_PILE_H
