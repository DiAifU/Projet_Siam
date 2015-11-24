
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
 * Un coup_jeu est utilise pour faire transiter l'information de la
 *  validite d'un coup pour l'API. Il s'agit d'une structure stockant
 *  si le coup est valide, et si un joueur est victorieux.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de ce fichier permettent d'acceder aisement a la
 *  validite d'un coup et a l'existance d'une victoire.
 * Les fonctions font appelles en interne aux fonctions de
 *  condition_victoire_partie.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Il s'agit d'un niveau d'abstraction ayant uniquement la connaissance
 *  d'un joueur vainqueur et de la validite d'un coup.
 *
 */

#ifndef COUP_JEU_H
#define COUP_JEU_H

#include "condition_victoire_partie.h"


/**
 *  La structure utilisee par l'API pour indiquer si un coup est
 *   valide, et si un joueur est victorieux.
 */
typedef struct
{
    int valide;  // vaut 1 si le coup est valide, 0 sinon.
    condition_victoire_partie condition_victoire; // indique le joueur
                                                  //  potentiellement
                                                  //  victorieux.
} coup_jeu;


/**
 * Fonction coup_etre_integre:
 * *************************
 *    Verifie qu'un coup_jeu est dans un etat integre
 *     (c-a-d valide vaut 0 ou 1, et condition_victoire est integre).
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un coup_jeu non modifiable.
 *    Garantie:
 *      - Un retour valant 1 si le coup verifie les conditions
 *        d'integrites.
 *      - Un retour valant 0 sinon.
 */
int coup_etre_integre(const coup_jeu* coup);

/**
 * Fonction coup_jeu_initialiser:
 * *************************
 *    Initialise un coup_jeu dans une configation par defaut tel que
 *       - le coup n'est pas valide
 *       - le condition de victoire est initialisee dans sa configuration
 *            par defaut.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un coup_jeu modifiable.
 *    Garantie:
 *      - Le coup_jeu est integre.
 */
void coup_jeu_initialiser(coup_jeu* coup);


/**
 * Fonction coup_etre_valide:
 * *************************
 *    Indique si le coup est valide ou non.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un coup_jeu non modifiable.
 *    Garantie:
 *      - Renvoie 1 si le coup est valide.
 *      - Renvoie 0 sinon.
 */
int coup_etre_valide(const coup_jeu* coup);

/**
 * Fonction coup_etre_victorieux:
 * *************************
 *    Indique si le coup donne lieu a une victoire d'un joueur ou non.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un coup_jeu non modifiable.
 *    Garantie:
 *      - Renvoie 1 si un joueur est victorieux.
 *      - Renvoie 0 sinon.
 */
int coup_etre_victorieux(const coup_jeu* coup);

/**
 * Fonction coup_afficher_victoire:
 * *************************
 *    Affiche en ligne de commande le joueur victorieux.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un coup_jeu non
 *         modifiable.
 *    Garantie:
 *      - Si un joueur est victorieux, celui-ci est affiche sur la
 *        ligne de commande.
 *      - Aucun affichage sinon.
 *
 */
void coup_afficher_victoire(const coup_jeu* coup);



#endif
