

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
 * Implementation des fonction de entree_sortie.
 *
 */



#include "entree_sortie.h"


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_MAX 512


int entree_sortie_fichier_etre_accessible(const char* filename)
{
    assert(filename!=NULL);

    //tente d'ouvir le fichier en ecriture/ajout
    // si le pointeur n'est pas nulle
    //  alors le fichier est accessible
    // sinon le fichier n'est pas accessible
    FILE *fid=NULL;
    fid=fopen(filename,"a+");

    if(fid==NULL)
        return 0;

    fclose(fid);
    return 1;
}

int entree_sortie_fichier_exister(const char* filename)
{

    assert(filename!=NULL);

    //tente d'ouvir le fichier en lecture seule
    // si le pointeur n'est pas nulle
    //  alors le fichier est accessible
    // sinon le fichier n'est pas accessible

    FILE *fid=NULL;
    fid=fopen(filename,"r");

    if(fid==NULL)
        return 0;

    fclose(fid);
    return 1;
}


void entree_sortie_ecrire_jeu_fichier(const char* filename,const jeu_siam* jeu)
{
    assert(filename!=NULL);
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));
    assert(entree_sortie_fichier_etre_accessible(filename)==1);

    // Ouvre fichier
    FILE *fid=NULL;
    fid=fopen(filename,"w");
    assert(fid!=NULL);
    if(fid==NULL) //double protection en mode release
    {
        printf("Erreur ouverture fichier %s\n",filename);
        abort();
    }

    entree_sortie_ecrire_jeu_pointeur_fichier(fid,jeu);

    // Ferme fichier
    int c=fclose(fid);
    if(c!=0) //double protection
    {
        printf("Erreur fermeture fichier %s\n",filename);
        abort();
    }
}



void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu)
{
    const char *lgn_joueur = "joueur %d"; 
    int joueur;
    const char *lgn_int = "[%d]";
    const char *lgn_str = "[%s]";
    char y_str[10];
    char buffer[100];
    
    FILE *identifiant = fopen(filename, "r");
    jeu_initialiser(jeu);
    if (identifiant == NULL) {
      printf("Erreur ouverture fichier %s\n", filename);
      exit(1);
    }
    int y, i;
    // 100 : valeur arbitraire, fgets() s'arrete au \n
    while (fgets(buffer, 100, identifiant) != 0) {
      if (sscanf(buffer, lgn_joueur, &joueur) == 1)
	jeu->joueur = joueur;
      else if (sscanf(buffer, lgn_int, &y) == 1) {
	sscanf(buffer, lgn_str, &y_str);
	if (y < 0 || y > NBR_CASES) {
	  puts("Erreur lecture numero de ligne");
	  exit(1);
	}
	for (i = 0; i < NBR_CASES; i++) {
	  char type_piece_nom_cours[4];
	  type_piece_nom_cours[0] = buffer[strlen(y_str) + 2 + i*6];
	  type_piece_nom_cours[1] = buffer[strlen(y_str) + 3 + i*6];
	  type_piece_nom_cours[2] = buffer[strlen(y_str) + 4 + i*6];
	  type_piece_nom_cours[3] = '\0';
	  jeu->plateau.piece[i][y] = piece_correspondre_nom_cours(type_piece_nom_cours);
	}
      }
    }
    if (!jeu_etre_integre(jeu)) {
      printf("Jeu invalide lecture fichier %s\n", filename);
      exit(1);
    }
}


void entree_sortie_ecrire_jeu_pointeur_fichier(FILE* identifiant,const jeu_siam* jeu)
{
    assert(identifiant!=NULL);
    assert(jeu!=NULL);


    const plateau_siam* plateau=&jeu->plateau;
    assert(plateau!=NULL);

    fprintf(identifiant,"joueur %d (%s)\n",jeu->joueur,type_nommer(jeu_obtenir_type_animal_courant(jeu)));

    entree_sortie_ecrire_plateau_pointeur_fichier(identifiant,plateau);
    

}



void entree_sortie_ecrire_plateau_pointeur_fichier(FILE* identifiant,const plateau_siam* plateau)
{
  int y, x;
  for (y = NBR_CASES-1; y >= 0; y--) {
    fprintf(identifiant, "[%d] ", y);
    for (x = 0; x < NBR_CASES; x++) {
      const piece_siam *piece = plateau_obtenir_piece_info(plateau, x, y);
      if (type_etre_animal(piece->type))
	fprintf(identifiant, "%s-%s | ", type_nommer_nom_cours(piece->type), orientation_nommer_nom_cours(piece->orientation));
      else
	fprintf(identifiant, "%s | ", type_nommer_nom_cours(piece->type));
    }
    fprintf(identifiant, "\n");
  }
  fprintf(identifiant, "    ");
  for (x = 0; x < NBR_CASES; x++) {
    fprintf(identifiant, "[%d]   ", x);
  }
  printf("\n");
}

