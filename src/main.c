
#include "piece_siam.h"
#include "plateau_siam.h"
#include "jeu_siam.h"
#include "api_siam.h"
#include "mode_interactif.h"
#include "type_piece.h"

#include <stdio.h>


void test_lancement()
{
    test_type_etre_animal();
}



int main()
{

  type_piece type = elephant;
  printf("%d", type);
  
  int est_ce_un_elephant = (type==elephant);
  int est_ce_un_rocher = (type == rocher);
  printf("%d %d", est_ce_un_elephant, est_ce_un_rocher);
  
  
    //decommentez la ligne suivante pour lancer les tests
    test_lancement();

    //lancement du mode interactif
    // mode_interactif_lancer();

    return 0;
    
}
