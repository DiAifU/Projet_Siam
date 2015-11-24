#ifndef PIECE_CARACTERISTIQUES_H
#define PIECE_CARACTERISTIQUES_H

typedef enum {elephant,rhinoceros,rocher,case_vide} type_piece;
typedef enum {haut,bas,gauche,droite,aucune_orientation} orientation_deplacement;




int type_etre_animal(type_piece type);

const char* type_nommer(type_piece type);
const char* orientation_nommer(orientation_deplacement orientation);

const char* type_nommer_nom_cours(type_piece type);
const char* orientation_nommer_nom_cours(orientation_deplacement orientation);

int type_etre_valide(type_piece type);
int orientation_etre_valide(orientation_deplacement orientation);
int orientation_etre_valide_deplacement(orientation_deplacement direction_deplacement);

orientation_deplacement orientation_inverser(orientation_deplacement orientation);
orientation_deplacement orientation_correspondre_caractere(char orientation);
int orientation_caractere_etre_valide(char orientation);

int type_caractere_animal_etre_valide(char type);
type_piece type_correspondre_caractere_animal(char type);

#endif
