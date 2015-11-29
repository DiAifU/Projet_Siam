#include "plateau_siam.h"
#include "entree_sortie.h"
#include "coordonnees_plateau.h"
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
  assert(plateau!=NULL);
  //on verifie que le nombre de rochers est ok
  int nbrRochers=  plateau_denombrer_type(plateau,rocher);
  if(nbrRochers>NBR_ROCHERS)
    return 0;
  //on verifie que le nombre d'elephants est ok
  int nbrElephants=plateau_denombrer_type(plateau,elephant);
  if (nbrElephants>NBR_ANIMAUX)
    return 0;
  //on verifie que le nombre de rhinoceros est ok
  int nbrRhinoceros=plateau_denombrer_type(plateau,rhinoceros);
  if(nbrRhinoceros>NBR_ANIMAUX)
    return 0;
  /*on vérifie que les pieces sont integres
  le code est celui de l'énoncé 2 pour denombrer type
  que j'ai adapte pour voir si chaque case du plateau
  est integre*/
  int kx=0;
  for (kx=0; kx < NBR_CASES; ++kx)
    {
      int ky=0;
      for (ky=0; ky < NBR_CASES; ++ky)
	{
	  const piece_siam* piece=
	    plateau_obtenir_piece_info(plateau,kx,ky);
	  assert(piece!=NULL);
	  if(piece_etre_integre(piece)==0)
	    return 0;// on renvoie 0 si on trouve qu'une piece n'est pas integre
	}
    }
  //si tout va bien on renvoie 1
  return 1;
}

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
  assert(coordonnees_etre_dans_plateau(x,y));
  assert(plateau!=NULL);
  return &(plateau->piece[x][y]);
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
  assert(coordonnees_etre_dans_plateau(x,y));
  assert(plateau!=NULL);
  return &(plateau->piece[x][y]);
}



int plateau_denombrer_type(const plateau_siam* plateau,type_piece type)
{
  assert(plateau!=NULL);
  int compteur=0;
  int kx=0;
  for (kx=0; kx < NBR_CASES; ++kx)
    {
      int ky=0;
      for (ky=0; ky < NBR_CASES; ++ky)
	{
	  const piece_siam* piece=
	    plateau_obtenir_piece_info(plateau,kx,ky);
	  assert(piece!=NULL);
	  if(piece->type==type)
	    compteur++;
	}
    }
  return compteur;
  
}

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
  //on vérifie que les variables donnees sont bonnes
  assert(plateau!=NULL);
  assert(coordonnees_etre_dans_plateau(x,y));
  const piece_siam* piece=
    plateau_obtenir_piece_info(plateau,x,y);// on recupere les infos de la piece
  assert(piece!=NULL);// on verifie que le pointeur est non nul et que la piece est integre
  assert(piece_etre_integre(piece));
  if(piece->type==case_vide)// on regade si la case est vide et on renvoie 0 si oui
    return 0;
  else
    return 1;// si elle ne l'est pas alors on renvoie 1
}

void plateau_afficher(const plateau_siam* plateau)
{
    assert(plateau!=NULL);

    //utilisation d'une fonction generique d'affichage
    // le parametre stdout permet d'indiquer que l'affichage
    // est realise sur la ligne de commande par defaut.
    entree_sortie_ecrire_plateau_pointeur_fichier(stdout,plateau);

}
