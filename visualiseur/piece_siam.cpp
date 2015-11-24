#include "piece_siam.h"
#include "assert.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>




void piece_afficher(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s,%s",type_nommer(piece->type),orientation_nommer(piece->orientation));
}

void piece_definir(piece_siam* piece,type_piece type,orientation_deplacement orientation)
{
    assert(piece!=NULL);

    piece->type=type;
    piece->orientation=orientation;

    assert(piece_etre_valide(piece));
}

void piece_definir_rocher(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,rocher,aucune_orientation);
    assert(piece_etre_valide(piece));
}

void piece_definir_case_vide(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,case_vide,aucune_orientation);
    assert(piece_etre_valide(piece));
}

int piece_etre_valide(const piece_siam* piece)
{
    assert(piece!=NULL);

    type_piece type=piece->type;
    orientation_deplacement orientation=piece->orientation;

    if(type>3 || orientation>4)
        return 0;

    if( (type==rocher || type==case_vide) && orientation!=aucune_orientation)
        return 0;

    if( (type==elephant || type==rhinoceros) && orientation>3)
        return 0;

    return 1;
}

int piece_etre_animal(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_valide(piece));

    return piece->type==elephant || piece->type==rhinoceros;
}

int piece_etre_rocher(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_valide(piece));

    return piece->type==rocher;
}

int piece_etre_case_vide(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_valide(piece));

    return piece->type==case_vide;
}

orientation_deplacement piece_recuperer_orientation_animal(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_valide(piece));
    assert(piece_etre_animal(piece));

    return piece->orientation;
}

void piece_afficher_nom_cours_debug(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s",type_nommer_nom_cours(piece->type));
    if(piece_etre_animal(piece))
        printf("-%s",orientation_nommer_nom_cours(piece->orientation));
}

void piece_initialiser(piece_siam* piece)
{
    piece->orientation=aucune_orientation;
    piece->type=elephant;
}

piece_siam piece_correspondre_nom_cours(const char* nom_cours)
{
    assert(nom_cours!=NULL);
    assert(strlen(nom_cours)==3);

    piece_siam piece;
    piece_initialiser(&piece);

    if(strncmp(nom_cours,"***",3)==0)
    {
        piece_definir_case_vide(&piece);
    }
    else if(strncmp(nom_cours,"RRR",3)==0)
    {
        piece_definir_rocher(&piece);
    }
    else if((nom_cours[0]=='e' || nom_cours[0]=='r') && nom_cours[1]=='-')
    {
        const type_piece type=type_correspondre_caractere_animal(nom_cours[0]);
        const orientation_deplacement orientation=orientation_correspondre_caractere(nom_cours[2]);

        piece_definir(&piece,type,orientation);
    }

    return piece;

}
