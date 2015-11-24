
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
 * Le jeu du siam est un conteneur definissant un plateau de jeu
 *  et le joueur courant. Ce conteneur permet de definir entierement
 *  l'etat du jeu a un moment donne.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de jeu_siam permettent de verifier l'integrite
 *   de l'etat d'un jeu et de verifier si une piece designee
 *   correspond bien au joueur actuel.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Le niveau d'abstraction associee au jeu_siam concerne la gestion
 *   a plus haut niveau d'un jeu (pas de manipulation directe de
 *   tableau ou d'enumerations) vis a vis des pieces qu'il est
 *   possible de manipuler en fonction du joueur.
 * Ce niveau d'abstraction concerne la gestion du conteneur du jeu
 *   mais pas la gestion des deplacements.
 *
 */


#ifndef JEU_SIAM_H
#define JEU_SIAM_H

#include "plateau_siam.h"

/**
 *  La structure jeu_siam contient un joueur et un plateau.
 */
typedef struct
{
    int joueur;           //le joueur courant
    plateau_siam plateau; //le plateau de jeu

}jeu_siam;


/**
 * Fonction jeu_etre_integre:
 * *************************
 *    Verifie qu'un jeu est dans un etat integre. C'est a dire que
 *      le joueur est integre, et que le plateau est integre.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu_siam non modifiable.
 *    Garantie:
 *      - Un retour valant 1 si le jeu verifie les conditions
 *        d'integrites.
 *      - Un retour valant 0 sinon.
 */
int jeu_etre_integre(const jeu_siam* jeu);


/**
 * Fonction jeu_initialiser:
 * *************************
 *    Initialise un jeu dans un etat par defaut integre.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu_siam modifiable.
 *    Garantie:
 *      - Un jeu initialise integre.
 */
void jeu_initialiser(jeu_siam* jeu);


/**
 * Fonction jeu_changer_joueur:
 * *************************
 *    Change le joueur courant du jeu.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu_siam integre modifiable.
 *    Garantie:
 *      - Le joueur du jeu est change.
 *      - Le jeu est integre.
 */
void jeu_changer_joueur(jeu_siam* jeu);


/**
 * Fonction jeu_afficher_debug:
 * *************************
 *    Affiche sur la ligne de commande l'etat du jeu.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu_siam non modifiable.
 *    Garantie:
 *      - Le joueur courant et l'etat du plateau sont affiches sur
 *         la ligne de commande.
 */
void jeu_afficher(const jeu_siam* jeu);

/**
 * Fonction jeu_verifier_type_piece_a_modifier:
 * *************************
 *    Verifie si la piece designee par ses coordonnees correspond
 *     a un animal modifiable par le joueur courant.
 *    Ainsi la fonction retourne 1 si:
 *     - la piece est un elephant et le joueur est 0.
 *     - la piece est un rhinoceros et le joueur est 1.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu_siam integre non modifiable.
 *      - Deux coordonnees (x,y) a l'interieur du plateau.
 *    Garantie:
 *      - Un retour valant 1 si la piece designee est modifiable par
 *         le joueur courant.
 *      - Un retour valant 0 sinon.
 */
int jeu_verifier_type_piece_a_modifier(const jeu_siam* jeu,int x,int y);


/**
 * Fonction jeu_obtenir_type_animal_courant:
 * *************************
 *    Recupere le type d'animal designe par le joueur courant du jeu.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu_siam integre non modifiable.
 *    Garantie:
 *      - Le type d'animal correspondant au joueur courant.
 */
type_piece jeu_obtenir_type_animal_courant(const jeu_siam* jeu);



#endif
