
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
 * Le parseur permet d'analyser une chaine de caractere et
 *  de traduire celle-ci en action a effectuer.
 * Ici, le parseur traduit la chaine de caractere recuperee
 *  de la ligne de commande pour determiner quelle action
 *  a realiser pour le jeu de siam.
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
 * Ce niveau d'abstraction a pour role de traiter des chaines de
 *  caractere et d'indiquer une action a realiser.
 * Les fonctions ne verifie que la syntaxe des chaines de caracteres
 *  mais n'ont pas pour vocation de verifier les actions du jeu.
 *
 */


#ifndef PARSEUR_MODE_INTERACTIF_H
#define PARSEUR_MODE_INTERACTIF_H


#include "orientation_deplacement.h"

typedef enum
{
    aucune_action,
    deplacement,
    introduction,
    changement_orientation,
    fin,
    initialisation,
    lecture_fichier
}
action_type;


#define MAX_LIGNE_COMMANDE 4096
#define MAX_NOM_FICHIER_TAILLE 256


typedef struct
{
    action_type type_action;

    char filename[MAX_NOM_FICHIER_TAILLE];

    int x_depart;
    int y_depart;

    orientation_deplacement deplacement;
    orientation_deplacement orientation;

}action_a_realiser;


void action_initialiser(action_a_realiser* action_a_initialiser);
void ligne_de_commande_parser(const char* ligne_commande,action_a_realiser* action_demandee);


#endif
