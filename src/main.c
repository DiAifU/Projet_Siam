
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
    test_piece_etre_integre();
}



int main()
{

    mode_interactif_lancer();
    return 0;
    
}
