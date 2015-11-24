#include "type_piece.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int type_etre_integre(type_piece type)
{
    // L'enumeration designe un type integre si elle est comprise
    //  entre 0 et 4.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 4 pour designer un type valide.
    if(type<4)
        return 1;
    return 0;
}


int type_etre_animal(type_piece type)
{
    
    // type 2 et 3 ne sont pas des animaux, mais type 0 et 1 le sont.
    // Il faut donc que type soit < 2 pour que type soit un animal.
    if(type<2)
        return 1;
    return 0;
}


const char* type_nommer(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere correspondante.

    switch(type)
    {
    case elephant:
        return "elephant"; break;
    case rhinoceros:
        return "rhinoceros"; break;
    case rocher:
        return "rocher"; break;
    case case_vide:
        return "vide"; break;
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}


const char* type_nommer_nom_cours(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere courte correspondante.

    switch(type)
    {
    case elephant:
        return "e"; break;
    case rhinoceros:
        return "r"; break;
    case rocher:
        return "RRR"; break;
    case case_vide:
        return "***"; break;
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

int type_caractere_animal_etre_integre(char type)
{
    // Verifie que le caractere correspond a elephant (e) ou rhinoceros (r).
    if(type=='e' || type=='r')
        return 1;
    return 0;
}

type_piece type_correspondre_caractere_animal(char type)
{
    return elephant;//a completer avec l'enone
}
