
/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Plateau modification a pour role de verifier les regles de
 *  deplacement de pieces du jeu sur le plateau ainsi que leur
 *  mise en place.
 * Ce sont ces fonctions qui permettent de manipuler le plateau
 *  a haut niveau en suivant les regles du jeu.
 *
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * On distingue 3 modifications possibles:
 *  - introduction d'une nouvelle piece du jeu.
 *  - deplacement d'une piece existante.
 *  - changement d'orientation d'une piece existante sans deplacement.
 *
 * Dans chacun des cas, on separe:
 *  - L'etude de la faisabilite de l'action sur un plateau.
 *  - La mise en place de l'action en la supposant valide.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Le niveau d'abstraction associee a plateau_modification comprend
 *  l'application des regles du jeu et leur mise en place sur un
 *  plateau du jeu. La notion de joueur n'est pas prise en compte
 *  a ce niveau, ainsi on supposera que tout animal est jouable.
 * Ce sera a niveau d'abstraction plus eleve de verifier qu'il
 *  s'agit de l'animal du joueur courant.
 *
 * Ce niveau d'abstraction delegue la mise en place technique
 *  de la poussee a un autre ensemble de fichier.
 *
 */



#ifndef PLATEAU_MODIFICATION_H
#define PLATEAU_MODIFICATION_H

/**
 *  Plateau_modification necessite la notion d'abstraction de plateau.
 */
#include "plateau_siam.h"



/**
 * Fonction plateau_modification_introduire_piece_etre_possible:
 * *************************
 *    Verifie si il est possible d'introduire une piece sur le
 *     plateau.
 *    L'introduction est possible si:
 *     - les coordonnees designent une case du bord du plateau.
 *     - l'introduction de la piece designee dans la direction donnee est
 *        permise par les regles du jeu (poussee comprise).
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau integre non modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une orientation que doit prendre la piece introduite.
 *    Garantie:
 *      - Un retour valant 1 si l'introduction est possible suivant
 *        les regle du jeu.
 *      - Un retour valant 0 sinon.
 *
 */
int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau,int x,int y,type_piece type,orientation_deplacement orientation);


/**
 * Fonction plateau_modification_introduire_piece:
 * *************************
 *    Realise l'introduction d'une nouvelle piece sur le plateau
 *     de jeu en supposant que cette introduction soit valide.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau integre modifiable.
 *      - Deux coordonnees entieres (x,y) designant une piece
 *         du bord du plateau.
 *      - Une orientation de deplacement integre d'une piece.
 *      - L'introduction de la piece doit etre valide
 *         (plateau_modification_introduire_piece_etre_possible
 *          doit renvoyer 1 avec ces arguments).
 *    Garantie:
 *      - Un plateau modifie integrant la nouvelle piece en ayant
 *         potentiellement realise une poussee.
 *      - La piece designees par les coordonnees est un animal
 *         integre, et le plateau est integre.
 */
void plateau_modification_introduire_piece(plateau_siam* plateau,int x,int y,type_piece type,orientation_deplacement orientation);


/**
 * Fonction plateau_modification_changer_orientation_piece_etre_possible:
 * *************************
 *    Verifie si il est possible de changer l'orientation d'une
 *     piece sur le plateau.
 *    Le changement d'orientation est possible si:
 *     - les coordonnees designent une piece modifiable
 *     - la nouvelle orientation est differente de l'orientation
 *       actuelle.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau integre non modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une orientation que doit prendre la piece.
 *    Garantie:
 *      - Un retour valant 1 si le changement d'orientation est
 *         possible.
 *      - Un retour valant 0 sinon.
 */
int plateau_modification_changer_orientation_piece_etre_possible(const plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation);


/**
 * Fonction plateau_modification_changer_orientation_piece:
 * *************************
 *    Realise la modification de l'orientation d'une piece du jeu
 *     en supposant que celle-ci soit possible.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau integre modifiable.
 *      - Deux coordonnees entieres (x,y) designant une piece
 *         de type animal du plateau.
 *      - Une orientation de deplacement integre d'une piece.
 *      - Le changement d'orientation de la piece doit etre valide
 *         (plateau_modification_changer_orientation_piece_etre_possible
 *          doit renvoyer 1 avec ces arguments).
 *    Garantie:
 *      - Un plateau modifie integrant le changement d'orientation.
 *      - La piece designee par les coordonnees est un animal
 *         integre, et le plateau est integre.
 */
void plateau_modification_changer_orientation_piece(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation);


/**
 * Fonction plateau_modification_deplacer_piece_etre_possible:
 * *************************
 *    Verifie si il est possible de deplacer une piece sur le plateau.
 *    Le deplacement est possible si:
 *     - les coordonnees designent une piece modifiable.
 *     - la direction de deplacement et la nouvelle orientation est
 *       compatible avec les regles du jeu.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau integre non modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une direction de deplacement de la piece.
 *      - Une orientation que doit prendre la piece apres deplacement.
 *    Garantie:
 *      - Un retour valant 1 si le deplacement est possible.
 *      - Un retour valant 0 sinon.
 */
int plateau_modification_deplacer_piece_etre_possible(const plateau_siam* plateau,int x0,int y0,orientation_deplacement direction_deplacement,orientation_deplacement orientation);


/**
 * Fonction plateau_modification_deplacer_piece:
 * *************************
 *    Realise le deplacement d'une piece sur le plateau
 *     de jeu en supposant que ce deplacement soit valide.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau integre modifiable.
 *      - Deux coordonnees entieres (x,y) designant une piece
 *         de type animal du plateau.
 *      - Une orientation de deplacement integre d'une piece.
 *      - Une orientation integre d'une piece (apres deplacement).
 *      - Le deplacement de la piece doit etre valide
 *         (plateau_modification_deplacer_piece_etre_possible
 *          doit renvoyer 1 avec ces arguments).
 *    Garantie:
 *      - Un plateau modifie integrant la nouvelle piece en ayant
 *         potentiellement realise une poussee.
 *      - Le plateau est integre.
 */
void plateau_modification_deplacer_piece(plateau_siam* plateau,int x0,int y0,orientation_deplacement deplacement,orientation_deplacement orientation_final);



#endif
