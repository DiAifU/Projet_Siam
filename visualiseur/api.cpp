

#include "api.h"
#include "plateau_siam.h"
#include "entree_sortie.h"


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




void api_lire_fichier(jeu_siam* jeu,const char* filename)
{
    assert(jeu!=NULL);
    assert(filename!=NULL);

    if(!entree_sortie_fichier_etre_accessible(filename) || !entree_sortie_fichier_exister(filename))
        printf("Fichier %s non accessible en lecture\n",filename);
    else
        entree_sortie_lire_jeu_fichier(filename,jeu);
}
