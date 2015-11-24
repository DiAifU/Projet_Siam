
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
 *
 * API du jeu d'echec
 * l'API lance une lecture d'actions a realiser en ligne de commande.
 * l'API fournie une interface de haut niveau afin de controler le comportement du jeu.
 * l'API n'a pas connaissance des regles internes du jeu, mais elle appelle les fonctions de controle permettant d'assurer un comportement valide.
 * Elle realiser l'interface entre l'utilisateur et les fonctions internes, les parametres d'entrees sont protegees contre les erreurs d'entrees
 *   sans faire quitter le programme.
 *
 */


//#Nom1: ZZZ
//#Prenom1: ZZZZ
//#Nom2: ZZZ
//#Prenom2: ZZZZ
//#Groupe: Z



#ifndef API_H
#define API_H

#include "jeu_siam.h"


void api_lire_fichier(jeu_siam* jeu,const char* filename);

#endif
