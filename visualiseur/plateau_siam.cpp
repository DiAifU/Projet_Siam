#include "plateau_siam.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_valide(x,y));

    piece_siam* piece=&plateau->piece[x][y];

    assert(piece!=NULL);
    return piece;
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(x>=0 && x<NBR_CASES);
    assert(y>=0 && y<NBR_CASES);

    const piece_siam* piece=&plateau->piece[x][y];

    return piece;
}

void plateau_initialiser(plateau_siam* plateau)
{
    for(int kx=0;kx<NBR_CASES;++kx)
    {
        for(int ky=0;ky<NBR_CASES;++ky)
        {
            piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
            assert(piece!=NULL);

            if(ky==2 && (kx>=1 && kx<=3) )
                piece_definir_rocher(piece);
            else
                piece_definir_case_vide(piece);
        }
    }


}



int plateau_denomber_type(const plateau_siam* plateau,type_piece type)
{
    assert(plateau!=NULL);
    assert(type_etre_valide(type));

    int compteur=0;
    for(int kx=0;kx<NBR_CASES;++kx)
    {
        for(int ky=0;ky<NBR_CASES;++ky)
        {
            const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
            assert(piece!=NULL);
            if(piece->type==type)
                compteur++;
        }
    }

    return compteur;
}

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_valide(x,y));

    const piece_siam* piece=plateau_obtenir_piece_info(plateau,x,y);
    assert(piece!=NULL);

    if(piece->type!=case_vide)
        return 1;
    return 0;
}

void plateau_afficher_debug(const plateau_siam* plateau)
{
    assert(plateau!=NULL);

    for(int ky=NBR_CASES-1;ky>=0;--ky)
    {
        printf("[%d] ",ky);
        for(int kx=0;kx<NBR_CASES;++kx)
        {
            const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
            assert(piece!=NULL);

            piece_afficher_nom_cours_debug(piece);
            printf(" | ");
        }
        puts("");
    }
    printf("    ");
    for(int kx=0;kx<NBR_CASES;++kx)
    {
        printf("[%d]   ",kx);
    }
    puts("\n");
}
