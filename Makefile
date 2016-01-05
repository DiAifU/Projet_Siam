CFLAGS=-g -Wall -Wextra -Wno-unused-parameter

OBJDIR=src
_OBJ = api_siam.o condition_victoire_partie.o coordonnees_plateau.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o main.o mode_interactif.o orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o type_piece.o poussee.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

jeu_siam : $(OBJ)
	mkdir bin
	gcc -o ./bin/$@ $^ $(CFLAGS)

all : jeu_siam compress verif

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)
	
clean :
	rm -rf ./bin/* ./src/*.o

compress : clean
	tar --exclude-vcs -czf ../kuhlburger_montvernay_projet_siam.tar.gz ../kuhlburger_montvernay_projet_siam/

verif :
	mkdir ./verif/
	cp ../kuhlburger_montvernay_projet_siam.tar.gz ./verif/
	cp -R ../Verification/* ./verif/
	cd ./verif && python ./verification.py
	rm -rf ./kuhlburger_montvernay_projet_siam.tar.gz ./verif
