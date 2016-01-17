#include "jeu_siam.h"
#include "joueur.h"

#include "entree_sortie.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


int jeu_etre_integre(const jeu_siam* jeu)
{
    assert(jeu!=NULL);

    //verification du joueur integre
    const int joueur=jeu->joueur;
    if(joueur_etre_integre(joueur)==0)
        return 0;

    //verification du plateau integre
    const plateau_siam* plateau=&jeu->plateau;
    if(plateau_etre_integre(plateau)==0)
        return 0;

    return 1;
}


void jeu_initialiser(jeu_siam* jeu)
{

    assert(jeu!=NULL);

    //initialise le plateau
    //initialise le joueur

    plateau_initialiser(&jeu->plateau);
    jeu->joueur=0;
}





void jeu_changer_joueur(jeu_siam* jeu)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));

    joueur_changer(&jeu->joueur);

    assert(jeu_etre_integre(jeu));

}


int jeu_verifier_type_piece_a_modifier(const jeu_siam* jeu,int x,int y)
{
  assert(jeu!=NULL);
  assert(coordonnees_etre_dans_plateau(x,y));
  //on recupere la piece
  const piece_siam* piece= plateau_obtenir_piece_info(&jeu->plateau,x,y);
  assert(piece!=NULL);
  // on verifie si la piece est un animal
  if(piece_etre_animal(piece)==0)
    return 0;
  // on regarde si la piece est un elephant mais que le joueur est 1
  if(piece->type==elephant){
    if(jeu->joueur==1)
      return 0;
  }
  //on regarde si la piece est un rhinoceros mais que le joueur est 0
  else{
    if(jeu->joueur==0)
      return 0;
  }
  //si ce n'etait pas les cas precedents alors on est ok
  return 1;
}

void jeu_afficher(const jeu_siam* jeu)
{
    assert(jeu!=NULL);

    //utilisation d'une fonction generique avec affichage sur
    //  la ligne de commande.
    entree_sortie_ecrire_jeu_pointeur_fichier(stdout,jeu);
}



type_piece jeu_obtenir_type_animal_courant(const jeu_siam* jeu)
{
  assert(jeu!=NULL);
  assert(jeu_etre_integre(jeu));
  type_piece piece=elephant;// on initialise la piece a renvoyer
  // si le joueur est 0 on renvoie son animal l'elephant
  if(jeu->joueur==0)
    return piece;
  // si le joueur est 1 on renvoie sa piece le rhinoceros
  if(jeu->joueur==1){
    piece=rhinoceros;
    return piece;
  }
  //si on est encore dans cette fonction alors ca a foire
  puts("erreur de la fonction jeu_obtenir_type_animal_courant");
  exit(EXIT_FAILURE);
  return piece;// on doit toujours faire un return a la fin d'une fonction non void
}

