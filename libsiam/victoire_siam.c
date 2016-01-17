
#include "victoire_siam.h"
#include "joueur.h"
#include <assert.h>
#include <stdio.h>

condition_victoire_partie victoire_determiner_gagnant(plateau_siam *plateau, int x, int y, orientation_deplacement orientation_poussee) {
  condition_victoire_partie cdt_vict;
  condition_victoire_initialiser(&cdt_vict);
  const piece_siam *piece_gagnante = NULL;
  
  while (coordonnees_etre_dans_plateau(x, y)) {
    const piece_siam *piece = plateau_obtenir_piece_info(plateau, x, y);
    
    // Aucune piece ne doit pas être vide sur le trajet
    assert(!piece_etre_case_vide(piece));
    
    if (piece_recuperer_orientation_animal(piece) == orientation_poussee)
      piece_gagnante = piece;
    
    coordonnees_appliquer_deplacement(&x, &y, orientation_poussee);
  }
  
  // On doit trouver une piece gagnante
  assert(piece_gagnante != NULL);
  
  cdt_vict.victoire = 1;
  cdt_vict.joueur = joueur_obtenir_numero_a_partir_animal(piece_gagnante->type);
  
  
  assert(condition_victoire_etre_integre(&cdt_vict));
  
  return cdt_vict;
}