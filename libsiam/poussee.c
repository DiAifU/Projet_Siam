#include "poussee.h"
#include <assert.h>
#include <stdio.h>




int poussee_etre_valide(const plateau_siam* plateau,int x,int y,orientation_deplacement orientation)
{
  
  // On fait tous les assert du contrat
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau));
  assert(coordonnees_etre_dans_plateau(x,y));
  assert(plateau_exister_piece(plateau,x,y));
  assert(orientation_etre_integre(orientation));
  
  // On regarde quelle orientation est opposee au mouvement
  orientation_deplacement orientationOpposeePoussee=orientation_inverser(orientation);
  
  
  /* On définit la puissance comme le nb d'animaux dans l'orientation de la poussee
   * moins le nb dans le sens inverse de la poussee. Elle est initialisée à 1 pour
   * comptabiliser aussi la pièce à l'origine de la poussee */
  int animauxBonneDirection=1;
  int nbrRochers=0;
  while (coordonnees_etre_dans_plateau(x,y)) {
    // On recupere la piece indiquee par les coordonnees
    const piece_siam* piece = plateau_obtenir_piece_info(plateau,x,y);
    assert(piece!=NULL);
    
    if(piece_etre_animal(piece)) {
      orientation_deplacement orientationPiece = piece_recuperer_orientation_animal(piece);
      
      // Si la piece est un animal oppose au mouvement alors il n'est pas possible
      if(orientationPiece == orientationOpposeePoussee) {
	animauxBonneDirection--;
      }
      else if (orientationPiece == orientation) {
	animauxBonneDirection++;
      }
    }
    else if (piece_etre_rocher(piece)){
      nbrRochers++;
    }
    
    /* Si on tombe sur une case vide alors on sort du while car il n'y a plus de pieces 
     * impliquees dans la poussee */
     else if (piece_etre_case_vide(piece)) {
      x=NBR_CASES+1;
      y=NBR_CASES+1;
    }
    coordonnees_appliquer_deplacement(&x,&y,orientation);
    
   /* Si il y a autant ou moins d'animaux dans le sens opposé que dans les autres sens
   * il n'est pas possible de pousser */
    if (animauxBonneDirection <= 0)
      return 0; 
    
    // Si il y a strictement moins de puissance que de rochers, pas possible non plus
    if (animauxBonneDirection < nbrRochers) 
      return 0;
  }

  
  return 1;
}

void poussee_realiser(plateau_siam* plateau,int x,int y,orientation_deplacement orientation)
{
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau));
  assert(coordonnees_etre_dans_plateau(x,y));
  assert(plateau_exister_piece(plateau,x,y));
  assert(orientation_etre_integre(orientation));
  if(poussee_etre_valide(plateau,x,y,orientation)==1){
    /*si la poussee est possible alors on cree un buffer ou on place la piece qui est
      deplacee et on met une case vide a sa place*/
    piece_siam bufferPiece1;
    piece_siam* pieceAModifier=plateau_obtenir_piece(plateau,x,y);
    bufferPiece1=*pieceAModifier;
    piece_definir_case_vide(pieceAModifier);
    /*puis on continue le deplacement des pieces jusqu'a ce qu'on atteigne une case
      vide ou la fin du plateau*/
    coordonnees_appliquer_deplacement(&x,&y,orientation);
    piece_siam bufferPiece2;
    while(coordonnees_etre_dans_plateau(x,y)){
      pieceAModifier=plateau_obtenir_piece(plateau,x,y);
      /*si on tombe sur une case vide alors on met la piece du buffer sur cette
	case et on change les valeurs de x et y pour sortir du while*/
      if(piece_etre_case_vide(pieceAModifier)==1)
	{
	  *pieceAModifier=bufferPiece1;
	  x=NBR_CASES+1;
	  y=NBR_CASES+1;
	}
      /*sinon on met la piece de la case dans un second buffer, puis on met la piece
	du premier buffer sur la case et a la fin on met la piece du second buffer
	dans le premier afin qu'on puisse refaire le while*/
      else
      {
	bufferPiece2=*pieceAModifier;
	*pieceAModifier=bufferPiece1;
	bufferPiece1=bufferPiece2;
	coordonnees_appliquer_deplacement(&x,&y,orientation);
      }
    }
  }
}
