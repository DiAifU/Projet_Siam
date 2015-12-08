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
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    return coup;
}
