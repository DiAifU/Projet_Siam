#include "piece_siam.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int piece_etre_integre(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(type_etre_integre(piece->type));
    assert(orientation_etre_integre(piece->orientation));
    
    if (type_etre_animal(piece->type)) {
      if (orientation_etre_integre_deplacement(piece->orientation))
	return 1;
    }
    else if (piece->orientation == aucune_orientation)
      return 1;
  
    return 0;
}


void piece_initialiser(piece_siam* piece)
{
    assert(piece!=NULL);

    piece_definir(piece,case_vide,aucune_orientation);

    assert(piece_etre_integre(piece));
}


int piece_etre_animal(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_integre(piece));
    
    if (type_etre_animal(piece->type))
      return 1;
  
    return 0;
}


int piece_etre_rocher(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_integre(piece));
    
    if (piece->type == rocher)
      return 1;
  
    return 0;
}


int piece_etre_case_vide(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_integre(piece));
    
    if (piece->type == case_vide)
      return 1;
  
    return 0;
}





void piece_definir(piece_siam* piece,type_piece type,orientation_deplacement orientation)
{
    assert(piece!=NULL);
    assert(type_etre_integre(type));
    assert(orientation_etre_integre(orientation));
  
    piece->type=type;
    piece->orientation=orientation;
    
    assert(piece_etre_integre(piece));
}


void piece_definir_rocher(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,rocher,aucune_orientation);
    assert(piece_etre_integre(piece));
}

void piece_definir_case_vide(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,case_vide,aucune_orientation);
    assert(piece_etre_integre(piece));
}





orientation_deplacement piece_recuperer_orientation_animal(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_integre(piece));
    assert(piece_etre_animal(piece));

    return piece->orientation;
}


void piece_afficher(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s,%s",type_nommer(piece->type),orientation_nommer(piece->orientation));
}

void piece_afficher_nom_cours(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s",type_nommer_nom_cours(piece->type));
    if(piece_etre_animal(piece))
        printf("-%s",orientation_nommer_nom_cours(piece->orientation));
}


piece_siam piece_correspondre_nom_cours(const char* nom_cours)
{
    assert(nom_cours!=NULL);
    assert(strlen(nom_cours)==3);

    //Possibilites:
    //
    // - nom vaut "***" -> case vide
    // - nom vaut "RRR" -> rocher
    // - nom commence par "e-" ou "r-"
    //     Alors il s'agit d'un animal.
    //     -> Recuperer le 3eme caractere
    //     -> Le convertir dans l'orientation de l'animal.
    //  - Si aucun des cas precedent, alors affiche erreur.

    piece_siam piece;
    piece_initialiser(&piece);


    if(strncmp(nom_cours,"***",3)==0)
    {
        piece_definir_case_vide(&piece);
    }
    else if(strncmp(nom_cours,"RRR",3)==0)
    {
        piece_definir_rocher(&piece);
    }
    else if((nom_cours[0]=='e' || nom_cours[0]=='r') && nom_cours[1]=='-')
    {
        const type_piece type=type_correspondre_caractere_animal(nom_cours[0]);
        const orientation_deplacement orientation=orientation_correspondre_caractere(nom_cours[2]);

        piece_definir(&piece,type,orientation);
    }
    else
    {
        printf("Erreur fonction %s\n",__FUNCTION__);
        abort();
    }

    return piece;

}


void test_piece_etre_integre(void)
{
  puts("test de piece_etre_integre");
  piece_siam piece;
  piece_siam *ptpiece=&piece;
  const piece_siam *ptcstpiece=&piece;
  piece_definir_rocher(ptpiece);
  if(piece_etre_integre(ptcstpiece)==0)
  {
   puts("rocher KO");
  }
  piece_definir_case_vide(ptpiece);
  if(piece_etre_integre(ptcstpiece)==0)
  {
    puts("case vide KO");
  }
  int k=0,l=0;
  for(k=0;k<aucune_orientation;k++)
  {
   for(l=0;l<rocher;l++)
   {
     piece_definir(ptpiece,l,k);
     if(piece_etre_integre(ptcstpiece)==0)
     {
       piece_afficher(ptcstpiece);
       printf("KO\n");
     }
    }
   }
  for(k=10;k<100;k++)
  {
    for(l=10;l<100;l++)
    {
      piece_definir(ptpiece,k,l);
      if(piece_etre_integre(ptcstpiece)==1)
	printf("piece de valeur %d et orientation %d ko\n",k,l);
    }
  }
 }
  
  
