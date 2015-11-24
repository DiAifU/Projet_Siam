

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
 * L'API du jeu de siam contient les fonctions d'appels permettant
 *  de jouer au jeu. Ce sont ces fonctions qui seront visibles et
 *  doivent etre utilisees pour manipuler le jeu depuis "l'exterieur".
 * Par exemple, programmer une interface utilisateur reviendra a
 *  realiser les appels adequates aux fonctions de l'API.
 *
 * Les fonctions de l'API doivent etre generiques et aisement
 *  utilisables depuis un programme s'interfacant sur la librairie
 *  du jeu. Elles sont l'interface depuis tout programme utilisant
 *  le jeu de siam.
 * Ces fonctions necessitent un minimum de prerequis et doivent
 *  proposer des parametres et retours simples a mettre en place.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Il existe trois fonctions de bases permettant de manipuler le jeu.
 *  - L'introduction d'une nouvelle piece.
 *  - Le deplacement d'une piece existante.
 *  - Le changement d'orientation sans deplacement.
 *
 * Chacune de ces fonctions tentent de realiser l'action designee
 *  sur le jeu courant si celle-ci est possible.
 * Dans chaque cas, les fonctions retournent une structure
 *  coup jeu qui definie si le coup est valide et si un joueur
 *  est vainqueur.
 * Note qu'un vainqueur ne peut pas avoir lieu dans le cas ou seul
 *  l'orientation de la piece change. La structure complete de
 *  coup_jeu etant tout de meme utilisee afin de garder obtenir
 *  une interface homogene.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Le niveau d'abstraction associee a l'API est un haut niveau
 *  d'abstraction. Ces fonctions implemente la gestion des regles
 *  du jeu en s'interfacant sur les fonctions gerant le jeu a plus
 *  bas niveau.
 * L'API possede la "connaissance" de l'ensemble des regles du jeu.
 *
 */


#ifndef API_SIAM_H
#define API_SIAM_H

/**
 *  L'API necessite la connaissance de l'abstraction d'un jeu_siam,
 *   ainsi que de la structure d'information de type coup_jeu.
 */
#include "jeu_siam.h"
#include "coup_jeu.h"

/**
 * Fonction api_siam_tenter_introduire_nouvelle_piece_si_possible:
 * *************************
 *    Tente d'introduire une nouvelle piece du jeu sur le plateau.
 *    L'introduction est possible si:
 *     - les coordonnees designent une piece modifiable par le joueur courant.
 *     - l'introduction de la piece designee dans la direction donnee est
 *        permise par les regles du jeu (poussee comprise).
 *
 *    Dans le cas ou l'introduction de la piece est possible, le jeu est
 *     mis a jour et la structure coup_jeu indique que le mouvement est
 *     valide.
 *    Si le coup aboutit a la victoire d'un joueur, coup_jeu est egalement
 *     mis a jour.
 *    Enfin, une fois le coup joue, le joueur courant du jeu est modifie.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une orientation que doit prendre la piece introduite.
 *    Garantie:
 *      - Si l'introduction est possible suivant les regle du jeu, alors
 *         le jeu est mise a jour et la structure coup_jeu indique la validite
 *         du coup.
 *      - Si le coup n'est pas possible, le jeu n'est pas mis a jour et
 *         coup_jeu indique que le coup n'est pas valide.
 */
coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation);

/**
 * Fonction api_siam_tenter_deplacer_piece_si_possible:
 * *************************
 *    Tente de deplacement une nouvelle piece du jeu sur le plateau avec un
 *     changement d'orientation possible.
 *
 *    Le deplacement est possible si:
 *     - les coordonnees designent une piece modifiable par le joueur courant.
 *     - le deplacement dans la direction indiquee est possible (poussee
 *       comprise)
 *     - la piece peut prendre l'orientation finale designee.
 *
 *    Dans le cas ou le deplacement de la piece est possible, le jeu est
 *     mis a jour et la structure coup_jeu indique que le mouvement est
 *     valide.
 *    Si le coup aboutit a la victoire d'un joueur, coup_jeu est egalement
 *     mis a jour.
 *    Enfin, une fois le coup joue, le joueur courant du jeu est modifie.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une direction de deplacement.
 *      - Une orientation de piece apres deplacement.
 *    Garantie:
 *      - Si le deplacement est possible suivant les regle du jeu, alors
 *         le jeu est mise a jour et la structure coup_jeu indique la validite
 *         du coup.
 *      - Si le coup n'est pas possible, le jeu n'est pas mis a jour et
 *         coup_jeu indique que le coup n'est pas valide.
 */
coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement deplacement,orientation_deplacement orientation);


/**
 * Fonction api_siam_tenter_changer_orientation_piece_si_possible:
 * *************************
 *    Tente de changer l'orientation d'une piece du jeu.
 *
 *    Le changement d'orientation est possible si:
 *     - les coordonnees designent une piece modifiable par le joueur courant.
 *     - la piece peut prendre l'orientation finale designee.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une orientation de piece apres changement.
 *    Garantie:
 *      - Si il est possible de deplacer la piece designee par le
 *        joueur courant dans la direction indiquee et ayant l'orientation
 *        souhaitee apres deplacement, alors le jeu est modifie en deplacant
 *        cette piece, et la structure de retour coup_jeu indique que
 *        le coup est valide et si il existe un vainqueur.
 *        Le jeu passe le tour au joueur suivant.
 *      - Si le deplacement de la piece n'est pas possible dans les
 *        conditions indiquees, alors le jeu n'est pas modifie et la structure
 *        coup_jeu indique que le deplacement n'est pas possible.
 */
coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation);

#endif
