#include "piece_caracteristiques.h"


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


const char* type_nommer(type_piece type)
{
    switch(type)
    {
    case elephant:
        return "elephant";
    case rhinoceros:
        return "rhinoceros";
    case rocher:
        return "rocher";
    case case_vide:
        return "vide";
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}


const char* orientation_nommer(orientation_deplacement orientation)
{
    switch(orientation)
    {
    case haut:
        return "haut";
    case bas:
        return "bas";
    case gauche:
        return "gauche";
    case droite:
        return "droite";
    case aucune_orientation:
        return "aucune";
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

const char* type_nommer_nom_cours(type_piece type)
{
    switch(type)
    {
    case elephant:
        return "e";
    case rhinoceros:
        return "r";
    case rocher:
        return "RRR";
    case case_vide:
        return "***";
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

const char* orientation_nommer_nom_cours(orientation_deplacement orientation)
{
    switch(orientation)
    {
    case haut:
        return "^";
    case bas:
        return "!";
    case gauche:
        return "<";
    case droite:
        return ">";
    case aucune_orientation:
        return "????";
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}


int type_etre_valide(type_piece type)
{
    if(type<4)
        return 1;
    return 0;
}

int orientation_etre_valide(orientation_deplacement orientation)
{
    if(orientation<5)
        return 1;
    return 0;
}
int orientation_etre_valide_deplacement(orientation_deplacement direction_deplacement)
{
    if(direction_deplacement<4)
        return 1;
    return 0;
}

orientation_deplacement orientation_inverser(orientation_deplacement orientation)
{
    assert(orientation<4);

    switch(orientation)
    {
    case haut:
        return bas;
    case bas:
        return haut;
    case gauche:
        return droite;
    case droite:
        return gauche;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}




int type_etre_animal(type_piece type)
{
    if(type==elephant || type==rhinoceros)
        return 1;
    return 0;
}

int orientation_caractere_etre_valide(char orientation)
{
    if(orientation=='<' || orientation=='>' || orientation=='^' || orientation=='v')
        return 1;
    return 0;
}

orientation_deplacement orientation_correspondre_caractere(char orientation)
{
    assert(orientation_caractere_etre_valide(orientation));

    switch(orientation)
    {
    case '<':
        return gauche;
    case '>':
        return droite;
    case '^':
        return haut;
    case 'v':
        return bas;
    default:
        printf("Erreur, orientation piece %c non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

int type_caractere_animal_etre_valide(char type)
{
    if(type=='e' || type=='r')
        return 1;
    return 0;
}

type_piece type_correspondre_caractere_animal(char type)
{
    assert(type_caractere_animal_etre_valide(type));

    switch(type)
    {
    case 'e':
        return elephant;
    case 'r':
        return rhinoceros;
    default:
        printf("Erreur, piece animal %c non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

