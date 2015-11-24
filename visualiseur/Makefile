all: visualiseur

CC=g++
CXXFLAGS=-Wall -Wextra -g -Wno-unused-variable
LDFLAGS=-lm -lGL -lGLU -lglut -pthread

visualiseur: api.o entree_sortie.o jeu_siam.o piece_caracteristiques.o piece_siam.o plateau_coordonnees.o plateau_coordonnees.o plateau_siam.o visualiseur.o
	$(CC) $^ -o visualiseur $(LDFLAGS)

api.o: api.cpp api.h plateau_siam.h entree_sortie.h
entree_sortie.o: entree_sortie.cpp entree_sortie.h
jeu_siam.o: jeu_siam.cpp jeu_siam.h
piece_caracteristiques.o: piece_caracteristiques.cpp piece_caracteristiques.h
piece_siam.o: piece_siam.cpp piece_siam.h
plateau_coordonnees.o: plateau_coordonnees.cpp plateau_coordonnees.h
plateau_siam.o: plateau_siam.cpp plateau_siam.h
visualiseur.o: visualiseur.cpp jeu_siam.h entree_sortie.h api.h

clean:
	rm -f *.o visualiseur *~
