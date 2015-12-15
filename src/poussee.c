#include "poussee.h"
#include <assert.h>
#include <stdio.h>

void case_suivante_de_la_poussee(int* ptx,int* pty,orientation_deplacement orientation)
{
  assert(ptx!=NULL);
  assert(pty!=NULL);
  assert(orientation_etre_integre(orientation));
  int x=*ptx;
  int y=*pty;
  switch(orientation){
  case haut:
    y++;
  break;
  case bas:
    y--;
  break;
  case gauche:
    x--;
  break;
  case droite:
    x++;
  break;
  default:
    puts("erreur de case_suivante_de_la_poussee");
    exit(EXIT_FAILURE);
  }
  *pty=y;
  *ptx=x;
}


int poussee_etre_valide(const plateau_siam* plateau,int x,int y,orientation_deplacement orientation)
{
   //on fait tous les assert du contrat
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau));
  assert(coordonnees_etre_dans_plateau(x,y));
  assert(plateau_exister_piece(plateau,x,y));
  assert(orientation_etre_integre(orientation));
  //on regarde quel orientation est opposee au mouvement
  orientation_deplacement orientationOpposeePoussee=orientation_inverser(orientation);
  /*on initialise une variable qui nous permettera de voir le nombre d'animaux qui poussent
    un ou plusieurs rochers*/
   int nbrAnimauxMoinsRochers=1;
  while(coordonnees_etre_dans_plateau(x,y)){
    // on recupere la piece indiquee par les coordonnees
    const piece_siam* piece=plateau_obtenir_piece_info(plateau,x,y);
    assert(piece!=NULL);
    if(piece_etre_animal(piece)){
      orientation_deplacement orientationPiece=piece_recuperer_orientation_animal(piece);
      //si la piece est un animal oppose au mouvement alors il n'est pas possible
      if(orientationPiece==orientationOpposeePoussee)
	return 0;
      // sinon on regarde si son orientation s'ajoute a la poussee
      else if(orientationPiece==orientation)
	nbrAnimauxMoinsRochers++;
    }
    /*si on a un rocher alors on diminue nbrAnimauxMoinsRochers, et si il s'avere qu'il devient
      negatif alors ca signifie qu'il y a plus de rochers que d'animaux qui poussent.
      La poussee n'est donc pas possible*/
   else if(piece_etre_rocher(piece)==1){
      nbrAnimauxMoinsRochers--;
      if(nbrAnimauxMoinsRochers<0)
	return 0;
    }
    /*si on tombe sur une case vide alors on sort du while car il n'y a plus de pieces 
      impliquees dans la poussee*/
     else if(piece_etre_case_vide(piece)){
      x=NBR_CASES+1;
      y=NBR_CASES+1;
    }
    case_suivante_de_la_poussee(&x,&y,orientation);
  }
  /*si on a atteint le return 1, cela signifie qu'on a pas rencontre d'animal oppose au mouvement
    et que le nombre d'animaux qui poussent les rochers sont adequat. La poussee est donc possible*/
  return 1;
}

void poussee_realiser(plateau_siam* plateau,int x,int y,orientation_deplacement orientation,
		      condition_victoire_partie conditionVictoire)
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
    case_suivante_de_la_poussee(&x,&y,orientation);
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
	case_suivante_de_la_poussee(&x,&y,orientation);
      }
    }
  }
}
