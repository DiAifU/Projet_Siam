#!/bin/bash

CFLAGS="-g -Wall -Wextra -Wno-unused-parameter"

rm -f ../bin/*.o ../bin/jeu_siam

gcc -c api_siam.c $CFLAGS
gcc -c condition_victoire_partie.c $CFLAGS
gcc -c coordonnees_plateau.c $CFLAGS
gcc -c coup_jeu.c $CFLAGS
gcc -c entree_sortie.c $CFLAGS
gcc -c jeu_siam.c $CFLAGS
gcc -c joueur.c $CFLAGS
gcc -c main.c $CFLAGS
gcc -c mode_interactif.c $CFLAGS
gcc -c orientation_deplacement.c $CFLAGS
gcc -c parseur_mode_interactif.c $CFLAGS
gcc -c piece_siam.c $CFLAGS
gcc -c plateau_modification.c $CFLAGS
gcc -c plateau_siam.c $CFLAGS
gcc -c type_piece.c $CFLAGS

gcc api_siam.o condition_victoire_partie.o coordonnees_plateau.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o main.o mode_interactif.o orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o type_piece.o -o ../bin/jeu_siam

