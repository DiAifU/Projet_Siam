
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
 * Un type_piece designe un type de case du jeu de siam.
 * Il peut etre du type elephant, rhinoceros, rocher, ou bien d'une case vide.
 * On separe les types qualifies d'animaux: elephant et rhinoceros des deux autres.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de ces fichiers ne s'occupent ici que de la manipulation des types,
 *   tels que leur affichages ou la verification qu'il s'agit bien d'un animal.
 * Un animal sera designe par une enumeration dans le programme. Lors du dialogue
 *   avec l'utilisateur, un animal sera cependant designe par un caractere ou
 *   une chaine de caractere reduite:
 *    - " e " pour un elephant 
 *    - " r " pour un rhinoceros
 *    - "RRR" pour un rocher,
 *    - "***" pour une case vide.
 * Les fonctions de conversions entre enumeration et caracteres sont egalement
 *   proposees dans ces fichiers.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Il s'agit d'un niveau d'abstraction bas du jeu.
 * Dans le reste du programme, on utilisera les fonctions proposees ici
 *   pour manipuler les types de pieces. Il ne devra pas y avoir de manipulation
 *   directe (ex. type==elephant || type==rhinoceros) dans le reste du programme.
 *
 */


#ifndef TYPE_PIECE_H
#define TYPE_PIECE_H


/** Le type de piece est defini suivant sa valeur d'enumeration.
 *  Chaque type represente une case possible du jeu de siam.
 *
 */
typedef enum
{
    elephant,   //un elephant est un type d'animal (jouable par le joueur 0).
    rhinoceros, //un rhinoceros est un type d'animal (jouable par le joueur 1).
    rocher,     //un rocher est un type de case que l'on ne peut modifier qu'en poussant avec un animal.
    case_vide   //une case vide represente toute case qui n'est pas un animal ni un rocher.
} type_piece;


/**
 * Fonction type_etre_integre:
 * *************************
 *    Verifie qu'un type de piece correspond a une enumeration possible.
 *    C'est a dire que la valeur du type doit etre soit elephant, rhinoceros,
 *    rocher ou case vide.
 *
 *    Necessite:
 *      - Une enumeration de type type_piece
 *    Garantie:
 *      - Un retour valant 1 si le type_piece correspond aux types prevus.
 *      - Un retour valant 0 sinon.
 */
int type_etre_integre(type_piece type);


/**
 * Fonction type_etre_animal:
 * *************************
 *    Verifie qu'un type de piece correspond a un animal (elephant ou rhinoceros).
 *
 *    Necessite:
 *      - Une enumeration de type type_piece
 *    Garantie:
 *      - Un retour valant 1 si le type_piece correspond a un elephant
 *          ou rhinoceros.
 *      - Un retour valant 0 sinon.
 */
int type_etre_animal(type_piece type);



/**
 * Fonction type_nommer:
 * *************************
 *    Renvoie une chaine de caractere correspondante a l'enumeration du type_piece.
 *    Cette fonction peut etre utilisee pour un affichage du type de piece
 *     ex. printf("%s\n",elephant); // affiche elephant sur la console.
 *
 *    Necessite:
 *      - Une enumeration de type type_piece
 *    Garantie:
 *      - Une chaine de caractere correspondante au type si celui-ci est integre.
 *      - Un affichage d'erreur et une sortie de programme si le type n'est pas
 *         integre.
 */
const char* type_nommer(type_piece type);

/**
 * Fonction type_nommer_nom_cours:
 * *************************
 *    Renvoie une chaine de caractere courte correspondante a l'enumeration du type_piece.
 *
 *    Necessite:
 *      - Une enumeration de type type_piece
 *    Garantie:
 *      - Une chaine de caractere courte correspondante au type si celui-ci est integre.
 *      - Un affichage d'erreur et une sortie de programme si le type n'est pas
 *         integre.
 */
const char* type_nommer_nom_cours(type_piece type);



/**
 * Fonction type_caractere_animal_etre_integre:
 * *************************
 *    Verifie si un caractere designe un animal (elephant
 *      ou rhinoceros) du jeu.
 *
 *    Necessite:
 *      - Un caractere.
 *    Garantie:
 *      - Un retour valant 1 si le caractere est 'e' ou 'r'.
 *      - Un retour valant 0 sinon.
 */
int type_caractere_animal_etre_integre(char type);

/**
 * Fonction type_correspondre_caractere_animal:
 * *************************
 *    Convertit un caractere designant un animal vers l'enumeration
 *      correspondante.
 *
 *    Necessite:
 *      - Un caractere designant un animal
 *        (c-a-d verifie par type_caractere_animal_etre_integre).
 *    Garantie:
 *      - L'enumeration de l'elephant si le caractere vaut 'e'.
 *      - L'enumeration du rhinoceros si le caractere vaut 'r'.
 */
type_piece type_correspondre_caractere_animal(char type);

#endif
