#include "api_siam.h"
#include "plateau_modification.h"
<<<<<<< HEAD
=======
#include "joueur.h"
>>>>>>> 5ffcdd3595911d40d8774434d75b7b97139ea2b7
#include <assert.h>
#include <stdio.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{
    assert(jeu != NULL);
    
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    
    if (!coordonnees_etre_dans_plateau(x, y)) {
      // Dans le cas ou les coord ne sont pas de le
      // plateau, coup non valide.
      coup.valide = 0;
    }
    else if (!coordonnees_etre_bordure_plateau(x, y)) {
      // Dans le cas ou la pièce n'est pas introduite sur le bord
      // du plateau, le coup n'est pas valide.
      coup.valide = 0;
    }
    else if (!orientation_etre_integre_deplacement(orientation)) {
      // L'orientation n'est pas integre, ou est aucune_orientation
      // Le coup n'est donc pas valide.
      coup.valide = 0;
    }
    else if (!piece_etre_case_vide(plateau_obtenir_piece_info(&jeu->plateau, x, y))) /******* TODO ******** POUR L'INSTANT, ON NE GERE PAS LA POUSSEE */
      coup.valide = 0;
    else {
      // Le coup est valide !!!!! YOUPIIIII
      piece_siam* piece = plateau_obtenir_piece(&jeu->plateau,x,y);
      piece->type = joueur_obtenir_animal(jeu->joueur);
      piece->orientation = orientation;
      coup.valide = piece_etre_integre(piece);
    }

    /* ********* TODO ***********
    ** Ajouter condition victoire
    */

    if (coup.valide)
      jeu_changer_joueur(jeu);

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
