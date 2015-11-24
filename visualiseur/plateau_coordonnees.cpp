#include "plateau_coordonnees.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int coordonnees_etre_valide(int x,int y)
{
    if((x>=0 && x<NBR_CASES) && (y>=0 && y<NBR_CASES))
        return 1;
    return 0;
}

int coordonnees_etre_bordure_plateau(int x,int y)
{
    if(coordonnees_etre_valide(x,y)==0)
        return 0;

    if(x==0 || x==NBR_CASES-1 || y==0 || y==NBR_CASES-1)
        return 1;
    return 0;
}

orientation_deplacement coordonnees_introduction_convertir_orientation(int x,int y)
{
    assert(coordonnees_etre_bordure_plateau(x,y));

    if(x==0)
        return droite;
    if(x==NBR_CASES)
        return gauche;
    if(y==0)
        return haut;
    if(y==NBR_CASES)
        return bas;

    printf("Erreur programme fonction %s\n",__FUNCTION__);
    abort();
}

deplacement_coordonnees coordonnees_orientation_convertir_deplacement(orientation_deplacement orientation)
{
    assert(orientation<4);

    deplacement_coordonnees d;
    switch(orientation)
    {
    case gauche:
        d.x=-1;
        d.y= 0;
        break;
    case droite:
        d.x=1;
        d.y=0;
        break;
    case haut:
        d.x=0;
        d.y=1;
        break;
    case bas:
        d.x=0;
        d.y=-1;
        break;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }


    return d;
}
