//
// Created by MICHEL on 2022/10/16.
//
#ifndef ALGO_TD5_FILE_H
#define ALGO_TD5_FILE_H
typedef int TypeDonnee;
typedef struct Cell_F{
    TypeDonnee donnee;
    struct Cell_F*suivant;
}TypeCellule_F;
typedef struct{
    TypeCellule_F *tete;
}File;
typedef struct {
    TypeCellule_F *tete,*queue;
}File2;
File initFile();
int estVideF(File F);
int estPleinF(File F);
TypeDonnee sommetFile(File F);
void emFiler(File *F,TypeDonnee typeDonnee);
void defiler(File *F,TypeDonnee* typeDonnee);
void afficheFile(File F);
File2 initFile2();
int estVideF2(File2 F);
void emFiler2(File2 *F,TypeDonnee typeDonnee);
void defiler2(File2 *F,TypeDonnee* typeDonnee);
void afficheFile2(File2 F);

void emFiler_ciculaire(File*F,TypeDonnee typeDonnee);
void deFiler_ciculaire(File*F,TypeDonnee* typeDonnee);
void emFiler2_ciculaire(File2*F,TypeDonnee typeDonnee);
void deFiler2_ciculaire(File2*F,TypeDonnee* typeDonnee);
void affiche_cirule(File F);
void affiche_cirule2(File2 F);
#endif //ALGO_TD5_FILE_H
