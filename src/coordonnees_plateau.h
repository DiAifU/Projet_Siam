
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
 * Les fonctions associees aux coordonnees du plateau permettent
 *  de gerer deux entiers (x,y) comme etant des coordonnees sur le
 *  plateau de jeu.
 * Un plateau de jeu est compose de NBR_CASES x NBR_CASES (5x5).
 * D'une maniere generale, on preferera utiliser la variable (preprocesseur)
 *  NBR_CASES plutot que 5 (permet par exemple d'envisager le changement
 *  de dimension du tableau).
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de ce fichier permettent de definir si des coordonnees
 *  sont dans le plateau ou non, ou sur le bord de celui-ci. Ces fonctions
 *  permettent de verifier dans d'autres niveaux d'abstractions si
 *  un piece peut se deplacer dans le plateau (coordonnees devant rester
 *  a l'interieur du plateau), ou si il est possible d'introduire
 *  une nouvelle piece (coordonnees aux bords du plateau).
 * Enfin, ces fonctions prennent egalement en charge le calcul des
 *  nouvelles coordonnees a partir d'une direction donnee.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Ce niveau d'abstraction sert a masquer toute la gestion des
 *  coordonnees du plateau a l'exterieur. Il n'y a pas de notion
 *  de type de piece ou de regle du jeu.
 *
 */


#ifndef COORDONNEES_PLATEAU_H
#define COORDONNEES_PLATEAU_H

#include "orientation_deplacement.h"

/**
 * La plateau est compose de 5x5 cases
 */
#define NBR_CASES 5

/**
 * Fonction coordonnees_etre_dans_plateau:
 * *************************
 *    Verifie que deux coordonnees (x,y) sont a l'interieur du plateau.
 *
 *    Necessite:
 *      - Deux coordonnees entieres
 *    Garantie:
 *      - Un retour valant 1 les coordonnees sont dans [0,NBR_CASES]x[0,NBR_CASES]
 *      - Un retour valant 0 sinon.
 */
int coordonnees_etre_dans_plateau(int x,int y);

/**
 * Fonction coordonnees_etre_bordure_plateau:
 * *************************
 *    Verifie que deux coordonnees (x,y) sont sur le bord du plateau.
 *    Permet par exemple de verifier qu'une piece peut etre introduite
 *     a ces coordonnees.
 *    Les coordonnees sont sur le bord du plateau si x, ou y, valent
 *     soit 0, soit NBR_CASES-1 et que celles-ci sont a l'interieur
 *     du plateau.
 *
 *    Necessite:
 *      - Deux coordonnees entieres
 *    Garantie:
 *      - Un retour valant 1 si les coordonnees definissent le bord
 *        du plateau.
 *      - Un retour valant 0 sinon.
 */
int coordonnees_etre_bordure_plateau(int x,int y);

/**
 * documentation a ecrire
 */
void coordonnees_appliquer_deplacement(int* x,int* y,orientation_deplacement orientation);




#endif
