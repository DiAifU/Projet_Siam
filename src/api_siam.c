#include "api_siam.h"
#include "plateau_modification.h"
#include <assert.h>
#include <stdio.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    return coup;
}



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
  assert(jeu!=NULL);
  coup_jeu coup;
  coup_jeu_initialiser(&coup);
  // on verifie si on peut changer l'orientation de la piece
  if(plateau_modification_changer_orientation_piece_etre_possible(&jeu->plateau,x,y,orientation)==0){
    coup.valide=0;
    return coup;
  }
  // on verifie si la piece qu'on veut modifier appartient au joueur courant
  if(jeu_verifier_type_piece_a_modifier(jeu,x,y)==0){
    coup.valide=0;
    return coup;
  }
  /* si les conditions sont verifies on change l'orientation de la piece,
     on change de joueur, on regarde s'il est victorieux et on renvoie le coup valide*/
  plateau_modification_changer_orientation_piece(&jeu->plateau,x,y,orientation);
  const piece_siam* piece=plateau_obtenir_piece_info(&jeu->plateau,x,y);
  assert(piece_etre_integre(piece));//on regarde si on a pas corrompu la piece
  jeu_changer_joueur(jeu);
  coup.valide=1;
  assert(coup_etre_integre(&coup));//on verifie qu'on renvoie un coup integre
  return coup;
}
