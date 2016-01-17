
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
 * Le plateau du jeu du siam est un conteneur de pieces du jeu.
 * Ici, un plateau est represente par un tableau de
 *   NBR_CASES x NBR_CASES pieces, ou chaque piece est definie par
 *   la structure des fichiers piece.h et piece.c.
 * L'implementation du plateau est donnee par un tableau C a deux
 *   entrees. Ce tableau est encapsule dans une structure de type
 *   plateau_siam qui permet de passer simplement cette donnee
 *   en parametre.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions associees au plateau ont pour but d'initialiser
 *   la structure du tableau, de verifier que le tableau est
 *   compatible avec un jeu possible, et de denombrer les pieces
 *   presentes sur celui-ci.
 * Elles permettent egalement de recuperer les pieces du tableau
 *   d'apres leurs coordonnees.
 * Le but de ces fonctions est de masquer a l'exterieur l'encodage
 *   sous forme de tableau. Cette structure doit etre entierement
 *   manipulable depuis d'autres fichiers a partir des fonctions
 *   de type "obtenir_piece".
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * A ce niveau d'abstraction, seule la connaissance du type de piece
 *   et du tableau est necessaire. Il n'y a pas de notion de regle
 *   du jeu. Il s'agit simplement d'un conteneur de pieces.
 *
 */


#ifndef PLATEAU_SIAM_H
#define PLATEAU_SIAM_H


/**
 *  Le plateau necessite la connaissance de l'abstraction
 *   "piece_siam" et du nombre de cases du plateau.
 */
#include "piece_siam.h"
#include "coordonnees_plateau.h"


/**
 *  Le jeu du siam contient 3 rochers
 */
#define NBR_ROCHERS 3


/**
 *  Le jeu du siam contient 5 animaux de chaque type.
 *  (5 elephants, et 5 rhinoceros).
 */
#define NBR_ANIMAUX 5



/**
 *  Un plateau_siam est un conteneur permettant de stocker les pieces
 *   du jeu.
 *  Ici, on considere une implementation sous la forme d'un tableau
 *   a 2 entrees.
 *
 *  Une piece d'un 'tableau' aux coordonnees (x,y) pourra etre
 *    recuperee par la syntaxe :
 *    tableau.piece[x][y].
 *
 *  Note: Cette syntaxe sera utilisee uniquement dans ce niveau
 *    d'abstraction et on utilisera depuis les autres fichiers
 *    les fonctions prevues pour cela.
 */
typedef struct
{
    piece_siam piece[NBR_CASES][NBR_CASES];

} plateau_siam;



/**
 * Fonction plateau_initialiser:
 * *************************
 *    Initialise un plateau a une configuration de depart
 *     par defaut (3 rochers sur le milieu du plateau
 *     et aucun animal sur le plateau).
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau_siam modifiable.
 *    Garantie:
 *      - L'initialisation du plateau a une configuration integre.
 *
 */
void plateau_initialiser(plateau_siam* plateau);

/**
 * Fonction plateau_etre_integre:
 * *************************
 *    Verifie l'integrite d'un plateau de jeu.
 *    Un plateau est integre si il verifie les conditions suivantes:
 *      - Chaque piece du plateau est integre.
 *      - Il existe au plus 3 rochers sur le plateau.
 *      - Il existe entre 0 et 5 elephants sur le plateau.
 *      - Il existe entre 0 et 5 rhinoceros sur le plateau.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau_siam non modifiable.
 *    Garantie:
 *      - Un retour valant 1 si le plateau verifie les conditions
 *         d'integrite.
 *      - Un retour valant 0 sinon.
 *
 */
int plateau_etre_integre(const plateau_siam* plateau);


/**
 * Fonction plateau_denombrer_type:
 * *************************
 *    Compte le nombre de pieces du jeu possedant un type
 *     donnee.
 *    Permet par exemple de comptabiliser le nombre d'elephants
 *     ou de rhinoceros.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau_siam non modifiable.
 *      - Un type de piece integre.
 *    Garantie:
 *      - Un retour entier donnant le nombre de piece du jeu
 *         valant le type donne en parametre.
 *
 */
int plateau_denombrer_type(const plateau_siam* plateau,type_piece type);



/**
 * Fonction plateau_exister_piece:
 * *************************
 *    Verifie si il existe une piece (case non vide) sur le plateau
 *      aux coordonnees indiquees.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau_siam non modifiable.
 *      - Deux entiers designant des coordonnees a l'interieur du
 *         plateau.
 *    Garantie:
 *      - Un retour valant 1 si la piece designee est une case
 *         non vide.
 *      - Un retour valant 0 sinon.
 *
 */
int plateau_exister_piece(const plateau_siam* plateau,int x,int y);


/**
 * Fonction plateau_obtenir_piece:
 * *************************
 *    Renvoie la piece (sous forme de pointeur) du plateau
 *     designee par les coordonnees passees en parametres.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau_siam modifiable.
 *      - Deux entiers designant des coordonnees a l'interieur du
 *         plateau.
 *    Garantie:
 *      - Un pointeur sur la piece designee par les coordonnees.
 *        La piece est modifiable.
 *
 */
piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y);

/**
 * Fonction plateau_obtenir_piece_info:
 * *************************
 *    Renvoie la piece (sous forme de pointeur non modifiable)
 *     du plateau designee par les coordonnees passees en
 *     parametres.
 *    Note: Contrairement a la fonction plateau_obtenir_piece,
 *     le pointeur retourne dans ce cas ne permet pas de modifier
 *     la piece du plateau. Cette fonction est utilisee dans le
 *     cas ou l'on ne souhaite que connaitre des informations sur
 *     la piece designee sans la modifier.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau_siam non modifiable.
 *      - Deux entiers designant des coordonnees a l'interieur du
 *         plateau.
 *    Garantie:
 *      - Un pointeur sur la piece designee par les coordonnees.
 *        La piece est non modifiable.
 *
 */
const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y);


/**
 * Fonction plateau_afficher_debug:
 * *************************
 *    Affiche en ligne de commande la vue du plateau.
 *    Utile pour la visualisation de l'etat du plateau.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un plateau_siam non modifiable.
 *    Garantie:
 *      - L'affichage en ligne de commande de l'etat du plateau.
 *
 */
void plateau_afficher(const plateau_siam* plateau);


#endif
