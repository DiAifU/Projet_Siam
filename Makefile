CFLAGS=-g -Wall -Wextra -Wno-unused-parameter

OBJDIR=src
_OBJ = api_siam.o condition_victoire_partie.o coordonnees_plateau.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o main.o mode_interactif.o orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o type_piece.o poussee.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

all : jeu_siam

jeu_siam : $(OBJ)
	gcc -o ./bin/$@ $^ $(CFLAGS)


%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)
	
clean :
	rm -rf ./bin/* ./src/*.o