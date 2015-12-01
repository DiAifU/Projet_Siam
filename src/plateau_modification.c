#include "plateau_modification.h"
#include "coordonnees_plateau.h"


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau,
                                                        int x,int y,
                                                        type_piece type,
                                                        orientation_deplacement orientation)
{
    return 1; //coder cette fonction
}


void plateau_modification_introduire_piece(plateau_siam* plateau,
                                           int x,int y,
                                           type_piece type,
                                           orientation_deplacement orientation)
{
    //coder cette fonction
}


int plateau_modification_changer_orientation_piece_etre_possible(const plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
  assert(plateau!=NULL);
  if(coordonnees_etre_dans_plateau(x0,y0)==0)// on vérifie si on est dans le plateau
    return 0;
  //on récupere les infos de la piece qu'on souhaite modifier
  const piece_siam* piece=plateau_obtenir_piece_info(plateau,x0,y0);
  assert(piece!=NULL);
  /* si c'est un rocher ou une case vide on ne peur pas modifier son orientation
     puisqu'ils peuvent seulement avoir aucune aurientation*/
  if(piece_etre_rocher(piece)==1||piece_etre_case_vide(piece)==1)
    return 0;
  //on vérifie qu'on travaille bien avec une piece de type animal
  if(piece_etre_animal(piece)==0)
    return 0;
  //on recupere alors son orientation
  orientation_deplacement orientationInitiale=piece_recuperer_orientation_animal(piece);
  assert(orientation_etre_integre(orientationInitiale));
  //on verifie qu'elle est differente de la nouvelle orientation souhaitee
  if(orientationInitiale==orientation)
    return 0;
  //si toutes les conditions ont etes verifiees alors le changement d'orientation est possible
  return 1;
}



void plateau_modification_changer_orientation_piece(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
    assert(plateau!=NULL);
    assert(plateau_etre_integre(plateau));
    const piece_siam *p = plateau_obtenir_piece_info(plateau, x0, y0);
    assert(piece_etre_animal(p));
    assert(orientation_etre_integre_deplacement(orientation));
    assert(plateau_modification_changer_orientation_piece_etre_possible(plateau, x0, y0, orientation));

    plateau->piece[x0][y0].orientation = orientation;

    assert(plateau_etre_integre(plateau));

}


int plateau_modification_deplacer_piece_etre_possible(const plateau_siam* plateau,
                                                      int x0,int y0,
                                                      orientation_deplacement direction_deplacement,
                                                      orientation_deplacement orientation)
{
    return 1;
}


void plateau_modification_deplacer_piece(plateau_siam* plateau,
                                         int x0,int y0,
                                         orientation_deplacement direction_deplacement,
                                         orientation_deplacement orientation_final)
{
    //coder cette fonction
}


