#include "orientation_deplacement.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int orientation_etre_integre(orientation_deplacement orientation)
{
    // L'enumeration designe une orientation integre si elle est compris
    //  entre 0 et 5.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 5 pour designer un type valide.

    if(orientation<5)
        return 1;
    return 0;
}

int orientation_etre_integre_deplacement(orientation_deplacement direction_deplacement)
{
    return 1; //fonction a ecrire
}

const char* orientation_nommer(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere correspondante.

    switch(orientation)
    {
    case haut:
        return "haut"; break;
    case bas:
        return "bas"; break;
    case gauche:
        return "gauche"; break;
    case droite:
        return "droite"; break;
    case aucune_orientation:
        return "aucune"; break;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



const char* orientation_nommer_nom_cours(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere courte correspondante.

    switch(orientation)
    {
    case haut:
        return "^"; break;
    case bas:
        return "v"; break;
    case gauche:
        return "<"; break;
    case droite:
        return ">"; break;
    case aucune_orientation:
        return "????"; break;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

orientation_deplacement orientation_inverser(orientation_deplacement orientation)
{
    assert(orientation_etre_integre_deplacement(orientation));

    // "Look up table" (LUT) convertissant une orientation vers
    //    son oppose
    // haut   <-> bas
    // droite <-> gauche


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



int orientation_caractere_etre_integre(char orientation)
{
    return 1; // fonction a ecrire
}


orientation_deplacement orientation_correspondre_caractere(char orientation)
{
    return 1; //fonction a completer
}
