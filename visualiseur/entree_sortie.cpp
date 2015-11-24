
#include "entree_sortie.h"


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_MAX 512


int entree_sortie_fichier_etre_accessible(const char* filename)
{
    assert(filename!=NULL);

    //tente d'ouvir le fichier en ecriture/ajout
    // si le pointeur n'est pas nulle
    //  alors le fichier est accessible
    // sinon le fichier n'est pas accessible
    FILE *fid=NULL;
    fid=fopen(filename,"a+");

    if(fid==NULL)
        return 0;

    fclose(fid);
    return 1;
}

int entree_sortie_fichier_exister(const char* filename)
{

    assert(filename!=NULL);

    //tente d'ouvir le fichier en lecture seule
    // si le pointeur n'est pas nulle
    //  alors le fichier est accessible
    // sinon le fichier n'est pas accessible

    FILE *fid=NULL;
    fid=fopen(filename,"r");

    if(fid==NULL)
        return 0;

    fclose(fid);
    return 1;
}





void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu)
{
    const char* _0x10="Joueur 0 (elephant)",*_0x01="Joueur 1 (rhinoceros)";
    const char* ___="[%d] %s | %s | %s | %s | %s |",*_0x00=filename;
    jeu_siam* __=jeu,_;int *_00x0=&_.joueur;
    piece_siam (*_0_)(const char*)=piece_correspondre_nom_cours;
    size_t (*_0x50)(const char*)=strlen;piece_siam* _00x02=*_.plateau.piece,*_0x02,_0x03;
    int _00x00_,_10x01_=0x00;char _0x100[0x100],_01x10_[0x05][0x100];
    const char* _for="Erreur ouverture fichier %s\n",*_jeu="Erreur lecture numero de ligne",*_while="Jeu invalide lecture fichier %s\n";
    jeu_initialiser(&_);FILE *_0x100_=fopen(_0x00,"r");assert(_0x100_!=0x00);if(_0x100_==0x00)
    {printf(_for,_0x00);exit(1);}while(fgets(_0x100,0x100,_0x100_)!=0){_00x00_=0x00;
    if(_0x50(_0x100)>=011&&strncmp(_0x100,_0x10,0x13)==0x00){*_00x0=0x00;
    }else if(_0x50(_0x100)>=011&&strncmp(_0x100,_0x01,0x13)
    ==0x00){*_00x0=0x01;}else if(sscanf(_0x100,___,&_00x00_,
    0x00[_01x10_],0x01 [_01x10_],0x02[_01x10_],0x03[_01x10_],0x04[_01x10_])
    ==0x06&&0x08>0x02){if(_00x00_<0x00||_00x00_>0x04){puts(_jeu);abort();}for(_10x01_=0x00;
    _10x01_<0x05;_10x01_+=0x01){_0x02=&(0x05*_10x01_+_00x00_)[_00x02];_0x03=_0_(_10x01_[_01x10_]);
    *_0x02=_0x03;}}}*__=_;
}



