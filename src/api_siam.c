#include "api_siam.h"
#include "plateau_modification.h"
#include "joueur.h"
#include <assert.h>
#include <stdio.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{
    assert(jeu != NULL);
    assert(jeu_etre_integre(jeu));
    
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    
    if (!coordonnees_etre_dans_plateau(x, y)) {
      // Dans le cas ou les coord ne sont pas de le
      // plateau, coup non valide.
      puts("Erreur : Coordonnees hors du plateau");
      coup.valide = 0;
    }
    else if (!coordonnees_etre_bordure_plateau(x, y)) {
      // Dans le cas ou la pièce n'est pas introduite sur le bord
      // du plateau, le coup n'est pas valide.
      puts("Erreur : Coordonnees hors du bord du plateau");
      coup.valide = 0;
    }
    else if (!orientation_etre_integre_deplacement(orientation)) {
      // L'orientation n'est pas integre, ou est aucune_orientation
      // Le coup n'est donc pas valide.
      coup.valide = 0;
    }
    else {
      type_piece type_joueur_courant = jeu_obtenir_type_animal_courant(jeu);
      if (plateau_denombrer_type(&jeu->plateau, type_joueur_courant) >= NBR_ANIMAUX) {
	// Déjà trop d'animaux sur le plateau pour le joueur courant
	puts("Erreur : nombre maxmum d'animaux atteins");
	coup.valide = 0;
      }
      else if (plateau_modification_introduire_piece_etre_possible(&jeu->plateau, x, y, type_joueur_courant, orientation)) {
	// Le coup est valide !!!!! YOUPIIIII
	plateau_modification_introduire_piece(&jeu->plateau, x, y, type_joueur_courant, orientation);
	coup.valide = 1;
      }
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
    assert(jeu != NULL);
    assert(jeu_etre_integre(jeu));
    
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    
    if (!coordonnees_etre_dans_plateau(x, y)) {
      // Dans le cas ou les coord ne sont pas de le
      // plateau, coup non valide.
      coup.valide = 0;
    }
    else if (!orientation_etre_integre_deplacement(deplacement)) {
      // L'orientation de déplacement n'est pas integre, ou est aucune_orientation
      // Le coup n'est donc pas valide.
      coup.valide = 0;
    }
    else if (!orientation_etre_integre_deplacement(orientation)) {
      // L'orientation finale n'est pas integre, ou est aucune_orientation
      // Le coup n'est donc pas valide.
      coup.valide = 0;
    }
    else if (!jeu_verifier_type_piece_a_modifier(jeu, x, y)) {
      // La piece en question est celle de l'autre joueur
      // Le coup n'est pas valide.
      coup.valide = 0;
    }
    else {
      if (plateau_modification_deplacer_piece_etre_possible(&jeu->plateau, x, y, deplacement, orientation)) {
	plateau_modification_deplacer_piece(&jeu->plateau, x, y, deplacement, orientation);
	coup.valide = 1;
      }
    }
    
    if (coup.valide)
      jeu_changer_joueur(jeu);
    
    
    assert(plateau_etre_integre(&jeu->plateau));
    
    return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
  assert(jeu!=NULL);
  assert(jeu_etre_integre(jeu));
  coup_jeu coup;
  coup_jeu_initialiser(&coup);
  if(orientation_etre_integre(orientation)==0){
    coup.valide=0;
    return coup;
  }
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
  assert(piece!=NULL);
  assert(piece_etre_integre(piece));//on regarde si on a pas corrompu la piece
  jeu_changer_joueur(jeu);
  coup.valide=1;
  assert(coup_etre_integre(&coup));//on verifie qu'on renvoie un coup integre
  return coup;
}
