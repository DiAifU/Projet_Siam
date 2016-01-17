CFLAGS=-g -Wall -Wextra -Wno-unused-parameter

_OBJ = main.o mode_interactif.o parseur_mode_interactif.o
OBJ = $(patsubst %,src/%,$(_OBJ))

_OBJ_LIB = api_siam.lo condition_victoire_partie.lo coordonnees_plateau.lo coup_jeu.lo entree_sortie.lo jeu_siam.lo joueur.lo orientation_deplacement.lo piece_siam.lo plateau_modification.lo plateau_siam.lo type_piece.lo poussee.lo victoire_siam.lo
OBJ_LIB = $(patsubst %,libsiam/%,$(_OBJ_LIB))


all : libsiam jeu_siam



jeu_siam : $(OBJ)
	gcc -o ./bin/_$@ $^ $(CFLAGS) -L./bin/ -lsiam
	echo "export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH\n./_jeu_siam">./bin/jeu_siam
	chmod +x ./bin/jeu_siam

libsiam : $(OBJ_LIB)
	gcc -shared $(CFLAGS) -o ./bin/libsiam.so $^

%.o: %.c
	gcc -c $< -o  $@ $(CFLAGS) 
	
%.lo: %.c
	gcc -c $< $(CFLAGS) -fPIC -o  $@
	
clean :
	rm -rf ./bin/* ./src/*.o ./libsiam/*.lo

compress :
	tar --exclude-vcs -czf ../kuhlburger_montvernay_projet_siam.tar.gz ../kuhlburger_montvernay_projet_siam/

verif :
	mkdir ./verif/
	cp ../kuhlburger_montvernay_projet_siam.tar.gz ./verif/
	cp -R ../Verification/* ./verif/
	cd ./verif && python ./verification.py
	rm -rf ./kuhlburger_montvernay_projet_siam.tar.gz ./verif
