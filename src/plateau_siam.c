#include "plateau_siam.h"
#include "entree_sortie.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



void plateau_initialiser(plateau_siam* plateau)
{
    // Initialise l'ensemble des cases du plateau a piece_vide
    // sauf les 3 cases du milieu avec un rocher (1,2), (2,2) et (3,2)
    //
    // L'etat de l'echiquier initial est le suivant:
    //
    // [4] *** | *** | *** | *** | *** |
    // [3] *** | *** | *** | *** | *** |
    // [2] *** | RRR | RRR | RRR | *** |
    // [1] *** | *** | *** | *** | *** |
    // [0] *** | *** | *** | *** | *** |
    //     [0]   [1]   [2]   [3]   [4]
    //


    int kx=0;
    for(kx=0 ; kx<NBR_CASES ; ++kx)
    {
        int ky=0;
        for(ky=0 ; ky<NBR_CASES ; ++ky)
        {
            piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
            assert(piece!=NULL);

            if(ky==2 && (kx>=1 && kx<=3) )
                piece_definir_rocher(piece);
            else
                piece_definir_case_vide(piece);
        }
    }

    assert(plateau_etre_integre);
}

int plateau_etre_integre(const plateau_siam* plateau)
{
    return 1; //coder cette fonction
}

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
    return &(plateau->piece[x][y]); //fonction a completer
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    return &(plateau->piece[x][y]);  //fonction a completer
}



int plateau_denombrer_type(const plateau_siam* plateau,type_piece type)
{
    //fonction a modifier avec l'enonce
    int i=0;
    int j=0;
    int x=0;
    for(i=0;i<5;++i)
    {
        for(j=0;j<5;++j)
        {
            if(plateau->piece[i][j].type==type)
                x++;
        }
    }
    return x;
}

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
    return 1; //coder cette fonction
}

void plateau_afficher(const plateau_siam* plateau)
{
    assert(plateau!=NULL);

    //utilisation d'une fonction generique d'affichage
    // le parametre stdout permet d'indiquer que l'affichage
    // est realise sur la ligne de commande par defaut.
    entree_sortie_ecrire_plateau_pointeur_fichier(stdout,plateau);

}
