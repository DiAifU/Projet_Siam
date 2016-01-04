
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
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Le mode interactif permet d'interfacer le jeu de siam avec
 *  la commande d'utilisateur en ligne de commande.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions proposee dans le mode interactifs permettent de
 *  demarer le controle du jeu en ligne de commande.
 * Les fonctions du mode interactif ont pour but de dialoguer avec
 *  un utilisateur (potentiellement non programmeur). Elles
 *  affichent donc les messages de dialogue avec l'utilisateur.
 * Le mode interactif vient egalement realiser la synchronisation
 *  des fonctions de gestion du jeu (demande d'action, realisation
 *  d'actions, affichage informatif, enregistrement et lecture
 *  a partir de fichiers et affichage du vainqueur).
 * Comme les fonctions traitent de demandent utilisateurs elles
 *  ne peuvent pas presuposer de contraintes de type "assertions"
 *  sur les variables completees interactivement.
 *
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Ce niveau d'abstraction a pour role de realiser l'interface entre
 *  une entree sous forme de demande utilisateur vers l'API du programme.
 * Le mode interactif ne vient utiliser que des fonctions de hauts
 *  niveaux du jeu qu'il utilise comme une librairie externe.
 */





#ifndef MODE_INTERACTIF_H
#define MODE_INTERACTIF_H

#include "jeu_siam.h"

/**
 * Fonction mode_interactif_lancer:
 * *************************
 *    Execute l'affichage du premier plateau initialise
 */
void mode_interactif_lancer();
/**
 * Fonction mode_interactif_parametres_etre_valides:
 * *************************
 *    S'assure de la validite des coordonnees passees en parametre (qu'elles
 *    soient dans le plateau) ainsi que l'orientation soit un déplacement valide.
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une orientation integre.
 *    Garantie:
 *   	- Retourne 1 si les parametres sont valides et 0 sinon (avec affichage de l'erreur)
 */
 int mode_interactif_parametres_etre_valides(const jeu_siam* jeu,int x,int y,orientation_deplacement orientation);
/**
 * Fonction mode_interactif_introduire_nouvelle_piece:
 * *************************
 *    Introduit une piece grace a l'API, enregistre l'introduction
 *    dans le fichier texte etat_courant si celle-ci est valide
 *    et verifie si le coup est victorieux ou non.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une orientation pour la piece introduite.
 * 	- Un entier modifiable victoire.
 *    Garantie:
 *      - Si l'introduction est possible, le jeu est mis a jour.
 *      - Affiche une erreur sinon.
 * 	- Modifie l'entier victoire donnant la victoire ou non du coup au joueur.
 *         
 */
void mode_interactif_introduire_nouvelle_piece(jeu_siam* jeu,int x,int y,orientation_deplacement orientation,int* victoire);
/**
 * Fonction mode_interactif_deplacer_piece:
 * *************************
 *    Introduit une piece grace a l'API apres avoir verifie
 *    qu'elle correspond au bon joueur, enregistre l'introduction
 *    dans le fichier texte etat_courant si celle-ci est valide
 *    et verifie si le coup est victorieux ou non.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une orientation pour le deplacement de la piece.
 *      - Une orientation pour la piece apres deplacement.
 *    Garantie:
 *      - Si l'introduction est possible, le jeu est mis a jour.
 *      - Affiche une erreur sinon.
 *         
 */
void mode_interactif_deplacer_piece(jeu_siam* jeu,int x,int y,orientation_deplacement deplacement,orientation_deplacement orientation,int* victoire);
/**
 * Fonction mode_interactif_changer_orientation:
 * *************************
 *    Change l'orientation d'une piece grace a l'API apres avoir verifie
 *    qu'elle correspond au bon joueur, enregistre l'introduction
 *    dans le fichier texte etat_courant si celle-ci est valide.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *      - Deux coordonnees entieres (x,y).
 *      - Une orientation de piece apres changement.
 *    Garantie:
 *      - Si le changement d'orientation est possible, le jeu est mis a jour.
 *      - Affiche une erreur sinon.
 */
void mode_interactif_changer_orientation(jeu_siam* jeu,int x,int y,orientation_deplacement orientation);
/**
 * Fonction mode_interactif_sauvegarder_jeu_fichier:
 * *************************
 *    Sauvegarde l'etat du jeu dans le fichier "etat_courant.txt"
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *    Garantie:
 *      - Un fichier etat_courant.txt mis a jour.
 */
void mode_interactif_sauvegarder_jeu_fichier(const jeu_siam* jeu);
/**
 * Fonction mode_interactif_lire_fichier:
 * *************************
 *    Lit un fichier de sauvegarde donne en parametre.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers un jeu integre modifiable.
 *      - Un nom de fichier valide et lisible
 *    Garantie:
 *      - Met a jour le jeu avec le contenu du fichier si valide
 * 	- Affiche une erreur sinon
 */
void mode_interactif_lire_fichier(jeu_siam* jeu,const char* filename);

#endif
