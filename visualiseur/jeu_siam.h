#ifndef JEU_SIAM_H
#define JEU_SIAM_H

#include "plateau_siam.h"

typedef struct
{
    int joueur;
    plateau_siam plateau;
}jeu_siam;


void jeu_initialiser(jeu_siam* jeu);


#endif
