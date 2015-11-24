#include "condition_victoire_partie.h"
#include "joueur.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>




int condition_victoire_etre_integre(const condition_victoire_partie* condition)
{
    assert(condition!=NULL);
    if(condition->victoire!=0 && condition->victoire!=1)
        return 0;
    if(condition->joueur!=0 && condition->joueur!=1)
        return 0;

    return 1;
}

void condition_victoire_initialiser(condition_victoire_partie* condition)
{
    assert(condition!=NULL);

    condition->victoire=0;
    condition->joueur=0;
}

int condition_victoire_etre_victorieux(const condition_victoire_partie* condition)
{
    assert(condition!=NULL);
    assert(condition_victoire_etre_integre(condition));

    return condition->victoire;
}

void condition_victoire_afficher(const condition_victoire_partie* condition)
{
    assert(condition!=NULL);
    assert(condition_victoire_etre_integre(condition));

    //a changer gestion joueur
    if(condition->victoire==1)
    {
        int joueur=condition->joueur;
        type_piece animal=joueur_obtenir_animal(joueur);
        printf("Joueur %d (%s) a gagne\n",joueur,type_nommer(animal));
    }
}
