#ifndef PLATEAU_SIAM_H
#define PLATEAU_SIAM_H

#include "piece_siam.h"
#include "plateau_coordonnees.h"

#define NBR_ROCHERS 3
#define NBR_ANIMAUX 5



typedef struct
{
    piece_siam piece[NBR_CASES][NBR_CASES];

} plateau_siam;

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y);
const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y);


int plateau_exister_piece(const plateau_siam* plateau,int x,int y);
void plateau_initialiser(plateau_siam* plateau);

int plateau_denomber_type(const plateau_siam* plateau,type_piece type);

void plateau_afficher_debug(const plateau_siam* plateau);


#endif
