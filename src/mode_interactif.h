
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

void mode_interactif_lancer();
void mode_interactif_introduire_nouvelle_piece(jeu_siam* jeu,int x,int y,orientation_deplacement orientation,int* victoire);
void mode_interactif_deplacer_piece(jeu_siam* jeu,int x,int y,orientation_deplacement deplacement,orientation_deplacement orientation,int* victoire);
void mode_interactif_changer_orientation(jeu_siam* jeu,int x,int y,orientation_deplacement orientation);
void mode_interactif_sauvegarder_jeu_fichier(const jeu_siam* jeu);
void mode_interactif_lire_fichier(jeu_siam* jeu,const char* filename);
int mode_interactif_parametres_etre_valides(const jeu_siam* jeu,int x,int y,orientation_deplacement orientation);


#endif
