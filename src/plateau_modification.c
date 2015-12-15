#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "poussee.h"
#include "condition_victoire_partie.h"


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau,
                                                        int x,int y,
                                                        type_piece type,
                                                        orientation_deplacement orientation)
{
  assert(plateau != NULL);
  assert(plateau_etre_integre(plateau));
  assert(type_etre_integre(type));
  assert(orientation_etre_integre(orientation));
  
  
  if (!coordonnees_etre_bordure_plateau(x,y))
    return 0;
  
  if (!type_etre_animal(type))
    return 0;
  
  if (!orientation_etre_integre_deplacement(orientation))
    return 0;
  
  if (plateau_exister_piece(plateau, x, y)) {
    if (!poussee_etre_valide(plateau, x, y, orientation))
      return 0;
    // Dans le cas d'une poussee, seule les orientations à l'interieur
    // du plateau sont valides.
    // Ex : x==0 => orientation bas impossible
    
    if (x==0) {
      if (orientation == gauche)
	  return 0;
    }
    else if (x==NBR_CASES) {
      if (orientation == droite)
	  return 0;
    }
    
    if (y==0) {
      if (orientation == bas)
	return 0;
    }
    else if (y==NBR_CASES) {
      if (orientation == haut)
	  return 0;
    }
    return 2;
  }
  return 1;
}


void plateau_modification_introduire_piece(plateau_siam* plateau,
                                           int x,int y,
                                           type_piece type,
                                           orientation_deplacement orientation)
{
  assert(plateau != NULL);
  assert(plateau_etre_integre(plateau));
  assert(type_etre_integre(type));
  assert(orientation_etre_integre_deplacement(orientation));
  assert(plateau_modification_introduire_piece_etre_possible(plateau, x, y, type, orientation));
      
  piece_siam* piece = plateau_obtenir_piece(plateau,x,y);
  if (!piece_etre_case_vide(piece)) {
    assert(poussee_etre_valide(plateau, x, y, orientation));
    
    condition_victoire_partie condition;
    condition_victoire_initialiser(&condition);
    poussee_realiser(plateau, x, y, orientation, condition);
    
  }
  
  piece->type = type;
  piece->orientation = orientation;
  
  assert(piece_etre_integre(piece));
  assert(plateau_etre_integre(plateau));
}


int plateau_modification_changer_orientation_piece_etre_possible(const plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
  assert(plateau!=NULL);
  assert(orientation_etre_integre(orientation));
  
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
    assert(plateau!=NULL);
    assert(plateau_etre_integre(plateau));
    assert(orientation_etre_integre(direction_deplacement));
    assert(orientation_etre_integre(orientation));

    if (!coordonnees_etre_dans_plateau(x0,y0))
      return 0;
    if (!plateau_exister_piece(plateau,x0,y0))
      return 0;
    if (!orientation_etre_integre_deplacement(direction_deplacement))
      return 0;
    if (!orientation_etre_integre_deplacement(orientation))
      return 0;
    
    coordonnees_appliquer_deplacement(&x0, &y0, direction_deplacement);
    if (plateau_exister_piece(plateau,x0,y0)) {
      if (direction_deplacement != orientation || direction_deplacement != plateau_obtenir_piece_info(plateau, x0, y0)->orientation) // Obligatoire si il y a poussée
	return 0;
      if (!poussee_etre_valide(plateau, x0, y0, direction_deplacement))
	return 0;
    }
    
    return 1;
}


void plateau_modification_deplacer_piece(plateau_siam* plateau,
                                         int x0,int y0,
                                         orientation_deplacement direction_deplacement,
                                         orientation_deplacement orientation_final)
{
    assert(plateau != NULL);
    assert(plateau_etre_integre(plateau));
    piece_siam *piece = plateau_obtenir_piece(plateau, x0, y0);
    assert(piece_etre_animal(piece));
    assert(orientation_etre_integre_deplacement(direction_deplacement));
    assert(orientation_etre_integre_deplacement(orientation_final));
    assert(plateau_modification_deplacer_piece_etre_possible(plateau, x0, y0,direction_deplacement, orientation_final));
    
    int x=x0, y=y0;
    coordonnees_appliquer_deplacement(&x, &y, direction_deplacement);
    
    if (plateau_exister_piece(plateau, x, y)) {
      assert(poussee_etre_valide(plateau, x, y, direction_deplacement));
      condition_victoire_partie condition;
      condition_victoire_initialiser(&condition);
      poussee_realiser(plateau, x, y, direction_deplacement, condition);
    }
    
    
    plateau->piece[x][y].type = plateau->piece[x0][y0].type;
    plateau->piece[x][y].orientation = orientation_final;
    
    plateau->piece[x0][y0].type = case_vide;
    plateau->piece[x0][y0].orientation = aucune_orientation;
    
    assert(plateau_etre_integre(plateau));
    
}


