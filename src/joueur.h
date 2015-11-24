
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
 * Un joueur est caracterise par un entier valant 0 ou 1. Ce
 *   nombre designe le fait que c'est au tour des elephants ou 
 *   des rhinoceros de jouer.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de ce fichier permettent de manipuler un joueur
 *  et de faire le lien entre le numero du joueur et le type de
 *  piece.
 * Les fonctions permettent egalement de faire la conversion entre
 *  le caractere designant un animal ('e' ou 'r') et le numero du
 *  joueur courant.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Il s'agit d'un niveau d'abstraction bas. Seul la notion du joueur
 *  et de son lien avec le type de piece courante est admise ici.
 *
 */

#ifndef JOUEUR_H
#define JOUEUR_H


#include "type_piece.h"


/**
 * Fonction joueur_etre_integre:
 * *************************
 *    Verifie qu'un numero de joueur est integre.
 *     C-a-d que son numero vaut soit 0 (elephant), soit 1 (rhinoceros).
 *
 *    Necessite:
 *      - Un nombre entier designant le numero du joueur.
 *    Garantie:
 *      - Un retour valant 1 le joueur est 0 ou 1.
 *      - Un retour valant 0 sinon.
 */
int joueur_etre_integre(int joueur);

/**
 * Fonction joueur_changer:
 * *************************
 *    Mise a jour du joueur apres un coup.
 *    Le joueur 0 devient 1 et inversement.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un nombre entier modifiable.
 *      - La valeur du pointeur doit etre un joueur integre.
 *    Garantie:
 *      - Apres execution de la fonction, joueur vaut
 *         1 si il etait a 0.
 *         0 si il etait a 1.
 */
void joueur_changer(int* joueur);


/**
 * Fonction joueur_etre_type_animal:
 * *************************
 *    Verifie si le joueur courant designe le type d'animal passe
 *     en parametre.
 *    0 -> elephant
 *    1 -> rhinoceros
 *
 *    Necessite:
 *      - Un entier designant un joueur integre.
 *      - Un type de piece designant un animal integre.
 *    Garantie:
 *      - Un retour valant 1 si le joueur designe le type d'animal donne.
 *      - Un retour valant 0 sinon.
 */
int joueur_etre_type_animal(int joueur,type_piece type);

/**
 * Fonction joueur_obtenir_animal:
 * *************************
 *    Recupere le type d'animal associe au numero du joueur passe
 *     en parametre.
 *
 *    Necessite:
 *      - Un entier designant un joueur integre.
 *    Garantie:
 *      - Le type d'animal associe au numero du joueur.
 */
type_piece joueur_obtenir_animal(int joueur);

/**
 * Fonction joueur_obtenir_numero_a_partir_animal:
 * *************************
 *    Recupere le numero du joueur associe au type d'animal passe
 *      en parametre.
 *
 *    Necessite:
 *      - Un type d'animal integre.
 *    Garantie:
 *      - Le numero du joueur associe a ce type d'animal.
 */
int joueur_obtenir_numero_a_partir_animal(type_piece type_animal);

#endif
