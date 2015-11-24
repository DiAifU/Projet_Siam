

#ifndef ENTREE_SORTIE_H
#define ENTREE_SORTIE_H

#include "jeu_siam.h"

#include <stdio.h>
#include <string.h>

int entree_sortie_fichier_etre_accessible(const char* filename);
int entree_sortie_fichier_exister(const char* filename);
void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu);

#endif
