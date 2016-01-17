
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
 * Les entrees / sorties permettent de faire le lien entre
 *  l'enregistrement en memoire et les fichiers.
 * Les fonctions prennent en charge la lecture et l'ecriture
 *  dans des fichiers ASCII.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions d'entree_sortie prennent en charge la gestion des
 *  fichiers et l'ecriture ou la lecture d'un jeu.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Ce niveau d'abstraction ne fait que traduire les variables dans
 *  la memoire vers une chaine de caractere ainsi que son ecriture
 *  sur le disque. Il n'y a pas de notion de suivie de regles du
 *  jeu a ce niveau.
 *
 */





#ifndef ENTREE_SORTIE_H
#define ENTREE_SORTIE_H

#include "jeu_siam.h"

#include <stdio.h>

/**
 * Fonction entree_sortie_fichier_etre_accessible:
 * ********************************
 *   Verifie qu'un fichier designee par son chemin est bien accessible
 *    en ecriture.
 *
 *
 *   Necessite:
 *     - Pointeur non NULL vers une chaine de caractere non modifiable.
 *       La chaine de caractere contient le nom (/chemin) du fichier
 *        sur le disque dur.
 *   Garantie:
 *     - Renvoie valeur 1 si le fichier designee est accessible (peut etre ecrit).
 *     - Renvoie valeur 0 si le fichier n'est pas accessible (ex. mauvais chemin).
 *
 */
int entree_sortie_fichier_etre_accessible(const char* filename);

/**
 * Fonction entree_sortie_fichier_exister:
 * ********************************
 *   Verifie qu'un fichier designee par son chemin existe
 *    (peut etre lue potentiellement).
 *
 *   Necessite:
 *     - Pointeur non NULL vers une chaine de caractere non modifiable.
 *       La chaine de caractere contient le nom (/chemin) du fichier
 *        sur le disque dur.
 *   Garantie:
 *     - Renvoie valeur 1 si le fichier designe existe.
 *     - Renvoie valeur 0 si le fichier n'existe pas ou n'est pas accessible.
 *
 */
int entree_sortie_fichier_exister(const char* filename);

/**
 * Fonction entree_sortie_ecrire_jeu_fichier:
 * ********************************
 *   Ecrit de maniere lisible l'etat du jeu dans un fichier.
 *
 *   Necessite:
 *     - Pointeur non NULL vers une chaine de caractere non modifiable.
 *       La chaine de caractere contient le nom (/chemin) du fichier
 *        sur le disque dur et designe un fichier accessible en ecriture.
 *     - Un pointeur non NULL vers un jeu_siam non modifiable.
 *   Garantie:
 *     - Le fichier designe contient l'etat du jeu ecrit en ASCII
 *
 */
void entree_sortie_ecrire_jeu_fichier(const char* filename,const jeu_siam* jeu);

/**
 * Fonction entree_sortie_lire_jeu_fichier:
 * ********************************
 *   Lit un jeu depuis un fichier et stocke celui-ci dans la
 *    variable passee en parametre.
 *
 *   Necessite:
 *     - Pointeur non NULL vers une chaine de caractere non modifiable.
 *       La chaine de caractere contient le nom (/chemin) du fichier
 *        sur le disque dur et designe un fichier decrivant un jeu integre.
 *     - Un pointeur non NULL vers un jeu_siam modifiable.
 *   Garantie:
 *     - Le jeu contient l'etat du jeu decrit dans le fichier
 *
 */
void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu);


/**
 * Fonction entree_sortie_ecrire_plateau_pointeur_fichier:
 * ********************************
 *   Ecrit l'etat du plateau dans un flux de sortie (pointeur de fichier).
 *   Le pointeur de fichier pouvant designer un fichier ou simplement
 *    l'affichage en ligne de commande (stdout).
 *
 *   Necessite:
 *     - Un pointeur de fichier non NULL. Le contenu du pointeur doit
 *        pouvoir etre modifiable.
 *     - Un pointeur non NULL vers un plateau_siam integre non modifiable.
 *   Garantie:
 *     - Le contenu du plateau est ecrit dans le "fichier" designee.
 *
 */
void entree_sortie_ecrire_plateau_pointeur_fichier(FILE* identifiant,const plateau_siam* plateau);

/**
 * Fonction entree_sortie_ecrire_jeu_pointeur_fichier:
 * ********************************
 *   Ecrit l'etat du jeu dans un flux de sortie (pointeur de fichier).
 *   Le pointeur de fichier pouvant designer un fichier ou simplement
 *    l'affichage en ligne de commande (stdout).
 *
 *   Necessite:
 *     - Un pointeur de fichier non NULL. Le contenu du pointeur doit
 *        pouvoir etre modifiable.
 *     - Un pointeur non NULL vers un jeu_siam integre non modifiable.
 *   Garantie:
 *     - Le contenu du jeu est ecrit dans le "fichier" designee.
 *
 */
void entree_sortie_ecrire_jeu_pointeur_fichier(FILE* identifiant,const jeu_siam* jeu);






#endif
