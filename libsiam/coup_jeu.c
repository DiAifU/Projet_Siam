#include "coup_jeu.h"

#include <assert.h>
#include <stdlib.h>




int coup_etre_integre(const coup_jeu* coup)
{
    assert(coup!=NULL);

    if(condition_victoire_etre_integre(&coup->condition_victoire)==0)
        return 0;

    if(coup->valide!=0 && coup->valide!=1)
        return 0;

    return 1;

}

void coup_jeu_initialiser(coup_jeu* coup)
{
    assert(coup!=NULL);

    coup->valide=0;
    condition_victoire_initialiser(&coup->condition_victoire);

    assert(coup_etre_integre(coup));
}

int coup_etre_valide(const coup_jeu* coup)
{
    assert(coup!=NULL);

    return coup->valide;
}

int coup_etre_victorieux(const coup_jeu* coup)
{
    assert(coup!=NULL);

    return condition_victoire_etre_victorieux(&coup->condition_victoire);
}

void coup_afficher_victoire(const coup_jeu* coup)
{
    assert(coup!=NULL);

    condition_victoire_afficher(&coup->condition_victoire);
}
