
#include "condition_victoire_partie.h"
#include "orientation_deplacement.h"
#include "plateau_siam.h"

#ifndef VICTOIRE_SIAM_H
#define VICTOIRE_SIAM_H

condition_victoire_partie victoire_determiner_gagnant(plateau_siam *plateau, int x, int y, orientation_deplacement orientation_poussee);

#endif