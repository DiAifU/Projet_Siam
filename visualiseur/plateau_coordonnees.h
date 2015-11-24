#ifndef PLATEAU_COORDONNEES_H
#define PLATEAU_COORDONNEES_H

#include "piece_caracteristiques.h"

#define NBR_CASES 5

typedef struct
{
    int x;
    int y;
}deplacement_coordonnees;


int coordonnees_etre_valide(int x,int y);
int coordonnees_etre_bordure_plateau(int x,int y);

orientation_deplacement coordonnees_introduction_convertir_orientation(int x,int y);
deplacement_coordonnees coordonnees_orientation_convertir_deplacement(orientation_deplacement orientation);


#endif
