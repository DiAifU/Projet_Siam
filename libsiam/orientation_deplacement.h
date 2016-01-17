
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
 * Le type orientation_deplacement designe l'orientation possible
 * associee a une piece du jeu de siam.
 * L'orientation est utilise dans deux cas differents pour les animaux:
 *  1- Pour designer l'orientation actuelle d'une piece
 *  2- Pour designer la direction de deplacement d'une piece
 *     (potentiellement differente de l'orientation de la piece)
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Il existe 4 orientations pour les pieces d'animaux 'gauche', 'droite',
 *   'haut' et 'bas'.
 * Les pieces de type rocher et cases vides n'ont pas d'orientations
 *   associees. Elles sont donc associees a 'aucune_orientation'.
 * Tout comme les types, l'utilisateur pourra designer de maniere
 *   concise une orientation a l'aide d'un seul caractere:
 *   '<': gauche, '>': droite, '^': haut, 'v': bas.
 *
 *  Les fonctions de ces fichiers gerent les operations associees
 *   a la manipulation d'orientation et leurs conversions en
 *   chaines de caracteres.
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Il s'agit d'un niveau d'abstraction bas du jeu. Il n'y a pas
 *   de notion de piece ni de jeu a ce niveau. La notion
 *   d'orientation est independante de toute autre consideration.
 *
 */



#ifndef ORIENTATION_DEPLACEMENT_H
#define ORIENTATION_DEPLACEMENT_H

/** L'orientation est definie suivant sa valeur d'enumeration.
 *
 */
typedef enum
{
    haut,    //associe au caractere '^'
    bas,     //associe au caractere 'v'
    gauche,  //associe au caractere '<'
    droite,  //associe au caractere '>'
    aucune_orientation //pour les pieces de type rocher et case vide
                       //il n'y a pas de caractere associe a cette valeur.

} orientation_deplacement;


/**
 * Fonction orientation_etre_integre:
 * *************************
 *    Verifie qu'une orientation de déplacement correspond a une enumeration possible.
 *    C'est a dire que la valeur de orientation_deplacement doit etre soit haut, bas,
 *    gauche, droite ou aucune_orientation.
 *
 *    Necessite:
 *      - Une enumeration de type orientation_deplacement
 *    Garantie:
 *      - Un retour valant 1 si orientation correspond aux types prevus.
 *      - Un retour valant 0 sinon.
 */
int orientation_etre_integre(orientation_deplacement orientation);

/**
 * Fonction orientation_etre_integre_deplacement:
 * *************************
 *    Verifie qu'une orientation correspond a une enumeration
 *      designant un deplacement possible.
 *    (c-a-d: gauche, droite, haut ou bas)
 *
 *    Necessite:
 *      - Une enumeration de type orientation_deplacement
 *    Garantie:
 *      - Un retour valant 1 si l'orientation correspond aux
 *          enumerations designants un deplacement.
 *      - Un retour valant 0 sinon.
 */
int orientation_etre_integre_deplacement(orientation_deplacement direction_deplacement);



/**
 * Fonction orientation_nommer:
 * *************************
 *    Renvoie une chaine de caractere correspondant a l'enumeration
 *      d'une orientation.
 *    Cette fonction peut etre utilisee pour un affichage du type
 *      d'orientation
 *     ex. printf("%s\n",droite); // affiche droite sur la console.
 *
 *    Necessite:
 *      - Une enumeration de type orientation_deplacement.
 *    Garantie:
 *      - Une chaine de caractere correspondant au deplcement si
 *         celui-ci est integre.
 *      - Un affichage d'erreur et une sortie de programme si
 *         le type n'est pas integre.
 *
 */
const char* orientation_nommer(orientation_deplacement orientation);


/**
 * Fonction orientation_nommer_nom_cours:
 * *************************
 *    Renvoie une chaine de caractere courte correspondante a l'enumeration
 *      d'une orientation.
 *
 *    Necessite:
 *      - Une enumeration de type orientation_deplacement.
 *    Garantie:
 *      - Une chaine de caractere courte correspondante au deplacement si
 *         celui-ci est integre.
 *      - Un affichage d'erreur et une sortie de programme si
 *         le type n'est pas integre.
 *
 */
const char* orientation_nommer_nom_cours(orientation_deplacement orientation);



/**
 * Fonction orientation_inverser:
 * *************************
 *    Renvoie l'orientation correspondante a l'oppose de la direction
 *      passee en parametre.
 *    Par exemple, orientation_inverser(droite)==gauche
 *                 orientation_inverser(haut)==bas
 *
 *    Necessite:
 *      - Une enumeration de type orientation_deplacement integre
 *         d'un deplacement.
 *    Garantie:
 *      - L'enumeration associee au deplacement oppose.
 *
 */
orientation_deplacement orientation_inverser(orientation_deplacement orientation);


/**
 * Fonction orientation_caractere_etre_integre:
 * *************************
 *    Verifie si un caractere designe une orientation de deplacement
 *       integre.
 *
 *    Necessite:
 *      - Un caractere.
 *    Garantie:
 *      - Un retour valant 1 si le caractere est '<','>','^', ou 'v'.
 *      - Un retour valant 0 sinon.
 */
int orientation_caractere_etre_integre(char orientation);




/**
 * Fonction orientation_correspondre_caractere:
 * *************************
 *    Convertit un caractere designant un deplacement vers l'enumeration
 *      correspondante.
 *
 *    Necessite:
 *      - Un caractere designant un deplacement
 *        (c-a-d verifie par orientation_caractere_etre_integre).
 *    Garantie:
 *      - L'enumeration correspondante au deplacement designe par
 *         le caractere.
 */
orientation_deplacement orientation_correspondre_caractere(char orientation);



#endif
