#include "jeu_siam.h"

#include "assert.h"
#include "stdlib.h"
#include "stdio.h"

void jeu_initialiser(jeu_siam* jeu)
{
    assert(jeu!=NULL);
    plateau_initialiser(&jeu->plateau);
    jeu->joueur=0;
}










