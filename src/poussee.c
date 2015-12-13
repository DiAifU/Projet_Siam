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
  // on recupere la piece
  const piece_siam* piece=plateau_obtenir_piece_info(plateau,x,y);
  assert(piece!=NULL);
  if(piece_etre_animal(piece)){
    orientation_deplacement orientationPiece=piece_recuperer_orientation_animal(piece);
    //si la piece est un animal oppose au mouvement alors il n'est pas possible
    if(orientationPiece==orientationOpposeePoussee)
      return 0;
  }
  //sinon on a une case non vide non opposée au mouvement mais peut-etre que la case suivante l'est
  else
  {
    //on regarde quel est la case suivante
    case_suivante_de_la_poussee(&x,&y,orientation);
    //si on est plus dans la plateau alors la poussee est possible
    if(coordonnees_etre_dans_plateau(x,y)==0)
      return 1;
    //si la case est vide alors la poussee est possible
    if(plateau_exister_piece(plateau,x,y)==0)
      return 1;
    //si on est pas dans les cas precedents alors on reapplique la fonction sur la case suivante
    return poussee_etre_valide(plateau,x,y,orientation);
  }
  puts("erreur de poussee_etre_valide");
  exit(EXIT_FAILURE);
}

void poussee_realiser(plateau_siam* plateau,int x,int y,type_piece type,orientation_deplacement orientation,
		      condition_victoire_partie conditionVictoire)
{
}
