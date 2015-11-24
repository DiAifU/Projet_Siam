#include "joueur.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int joueur_etre_integre(int joueur)
{
    return (joueur==0 || joueur==1);
}

void joueur_changer(int* joueur)
{
    assert(joueur!=NULL);
    assert(joueur_etre_integre(*joueur));

    switch(*joueur)
    {
    case 0:
        *joueur=1;
        break;
    case 1:
        *joueur=0;
        break;
    default:
        printf("Erreur joueur invalide dans fonction %s\n",__FUNCTION__);
        abort();
    }

}

int joueur_etre_type_animal(int joueur,type_piece type)
{
    assert(joueur_etre_integre(joueur));
    assert(type_etre_integre(type));
    assert(type_etre_animal(type));

    if(joueur==0 && type==elephant)
        return 1;
    if(joueur==1 && type==rhinoceros)
        return 1;

    return 0;

}

type_piece joueur_obtenir_animal(int joueur)
{
    assert(joueur_etre_integre(joueur));

    switch(joueur)
    {
    case 0:
        return elephant;
    case 1:
        return rhinoceros;
    default:
        printf("Erreur fonction %s\n",__FUNCTION__);
        abort();
    }

    puts("Ne devrait jamais arriver sur cette ligne");
    abort();

}

int joueur_obtenir_numero_a_partir_animal(type_piece type_animal)
{
    assert(type_etre_integre(type_animal));

    switch(type_animal)
    {
    case elephant:
        return 0;
    case rhinoceros:
        return 1;
    default:
        printf("Erreur fonction %s\n",__FUNCTION__);
        abort();
    }

    puts("Ne devrait jamais arriver sur cette ligne");
    abort();
}


