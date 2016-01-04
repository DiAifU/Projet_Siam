#ifndef POUSSEE_H
#define POUSSEE_H
#include "plateau_siam.h"
#include "condition_victoire_partie.h"
#include <stdlib.h>

/***Fonction case_suivante_de_la_poussee
********************
*donne les coordonnees de la case qui suit celle donnée par les pointeurs ptx et pty
*dans la poussee. Les coordonnees son renvoyes dans ces pointeurs
*
*Necessite:
*-deux pointeurs de coordonnees entieres non nulles
*une orientation integre
*
*Garantie:
*-Deux pointeurs avec les nouvelles coordonnees
*
*Note:
*La fonction change les coordonnees en utilisant le plan vectoriel suivant:
*     ^
*     |
*     |
*      ------>
*A changer si ce n'est pas le bon
*/
void case_suivante_de_la_poussee(int* ptx,int* pty,orientation_deplacement orientation);

/***Fonction poussee_etre_valide:
**************************
*Verifie si il est possible de realiser une poussee qui debute
*aux coordonnees (x,y) dans l'orientation definie.
*Note: Les coordonnees (x,y) designent la premiere piece rencontree
*dans la poussee(et non pas les coordonnees de la piece a l'origine
*  de la poussee).
*
*Necessite:
*-Un pointeur non NULL vers un plateau integre non modifiable.
*- Deux coordonnees entieres (x,y) designant une piece non
*vide integre du plateau.
*-Une orientation de poussee designant une direction integre.
*Garantie:
*-Un retour valant 1 si la poussee est possible.
*-Un retour valant 0 sinon.
*
*/

int poussee_etre_valide(const plateau_siam* plateau,int x,int y,orientation_deplacement orientation);

/***Fonction poussee_realiser:
**************************
*Realise une poussee sur un plateau en supposant que celle-ci
*est realisable (et non pas les coordonnees de la piece a l'origine
*     de la poussee).
*
*Necessite:
*-Un pointeur non NULL vers un plateau integre modifiable.
*-Deux coordonnees entieres (x,y) designant une piece non
*vide integre du plateau.
*-Une orientation de poussee designant une direction integre.
*Garantie:
*-Un plateau integre mis a jour en ayant realise la poussee.
*
*/

void poussee_realiser(plateau_siam* plateau,int x,int y,orientation_deplacement orientation);

#endif
