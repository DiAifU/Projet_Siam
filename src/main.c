
#include "piece_siam.h"
#include "plateau_siam.h"
#include "jeu_siam.h"
#include "api_siam.h"
#include "mode_interactif.h"

#include <stdio.h>

void test_type_etre_animal()
{
    puts("Test type_etre_animal");

    if(type_etre_animal(elephant)!=1)
        puts("elephant KO");

    if(type_etre_animal(rhinoceros)!=1)
        puts("rhinoceros KO");

    if(type_etre_animal(rocher)!=0)
        puts("rocher KO");
    if(type_etre_animal(case_vide)!=0)
        puts("case vide KO");

    int k=0;
    for(k=4;k<20;++k)
        if(type_etre_animal(k)!=0)
            printf("valeur %d KO\n",k);

}

void test_lancement()
{
    test_type_etre_animal();
    // puis tous les autres tests a ajouter
    //  de maniere iterative ...
}



int main()
{

  type_piece type = elephant;
  printf("%d", type);
  
  int est_ce_un_elephant = (type==elephant);
  int est_ce_un_rocher = (type == rocher);
  printf("%d %d", est_ce_un_elephant, est_ce_un_rocher);
  
  return 0;
  
  /*
    //decommentez la ligne suivante pour lancer les tests
    test_lancement();

    //lancement du mode interactif
    mode_interactif_lancer();

    return 0;
    
    */
}
