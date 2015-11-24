#ifndef PIECE_SIAM_H
#define PIECE_SIAM_H

#include "piece_caracteristiques.h"

typedef struct
{
    type_piece type;
    orientation_deplacement orientation;
}piece_siam;


void piece_definir_rocher(piece_siam* piece);
void piece_definir_case_vide(piece_siam* piece);

int piece_etre_valide(const piece_siam* piece);
int piece_etre_animal(const piece_siam* piece);
int piece_etre_rocher(const piece_siam* piece);
int piece_etre_case_vide(const piece_siam* piece);

void piece_afficher_nom_cours_debug(const piece_siam* piece);
piece_siam piece_correspondre_nom_cours(const char* nom_cours);


#endif
