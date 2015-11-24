
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
 * Condition victoire partie est un conteneur stockant un vainqueur
 *  possible.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de ce fichier permettent de verifier si un joueur
 *  est vainqueur.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Il s'agit d'un niveau d'abstraction ayant uniquement la connaissance
 *  de l'existance d'un vainqueur et du numero du joueur associe.
 *
 */


#ifndef CONDITION_VICTOIRE_PARTIE_H
#define CONDITION_VICTOIRE_PARTIE_H

/**
 *  Structure definissant si il existe un vainqueur et son numero
 *   associe.
 */
typedef struct
{
    int victoire;     // vaut 0 lorsqu'il n'y a pas de vainqueur.
                      // vaut 1 lorsqu'il y a un vainqueur
    int joueur;       // numero du joueur si vainqueur.

}condition_victoire_partie;


/**
 * Fonction condition_victoire_etre_integre:
 * *************************
 *    Verifie qu'une condition_victoire_partie est integre.
 *     c-a-d que victoire vaut 0 ou 1, et joueur vaut 0 ou 1.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une condition_victoire_partie non
 *         modifiable.
 *    Garantie:
 *      - Un retour valant 1 si la structure est integre.
 *      - Un retour valant 0 sinon.
 */
int condition_victoire_etre_integre(const condition_victoire_partie* condition);

/**
 * Fonction condition_victoire_initialiser:
 * *************************
 *    Initialise la structure de condition de victoire a un etat
 *     integre par defaut sans vainqueur.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une condition_victoire_partie non
 *         modifiable.
 *    Garantie:
 *      - Un retour valant 1 si la structure est integre.
 *      - Un retour valant 0 sinon.
 */
void condition_victoire_initialiser(condition_victoire_partie* condition);


/**
 * Fonction condition_victoire_etre_victorieux:
 * *************************
 *    Verifie si un joueur est victorieux.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une condition_victoire_partie non
 *         modifiable.
 *    Garantie:
 *      - Un retour valant 1 si un joueur est victorieux.
 *      - Un retour valant 0 sinon.
 */
int condition_victoire_etre_victorieux(const condition_victoire_partie* condition);


/**
 * Fonction condition_victoire_afficher:
 * *************************
 *    Affiche en ligne de commande le joueur victorieux.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une condition_victoire_partie non
 *         modifiable.
 *    Garantie:
 *      - Si un joueur est victorieux, celui-ci est affiche sur la
 *        ligne de commande.
 *      - Aucun affichage sinon.
 *
 */
void condition_victoire_afficher(const condition_victoire_partie* condition);

#endif

