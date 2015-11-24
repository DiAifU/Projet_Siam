

/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 *
 * Implementation des fonction de entree_sortie.
 *
 */



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


void entree_sortie_ecrire_jeu_fichier(const char* filename,const jeu_siam* jeu)
{
    assert(filename!=NULL);
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));
    assert(entree_sortie_fichier_etre_accessible(filename)==1);

    // Ouvre fichier
    FILE *fid=NULL;
    fid=fopen(filename,"w");
    assert(fid!=NULL);
    if(fid==NULL) //double protection en mode release
    {
        printf("Erreur ouverture fichier %s\n",filename);
        abort();
    }

    entree_sortie_ecrire_jeu_pointeur_fichier(fid,jeu);

    // Ferme fichier
    int c=fclose(fid);
    if(c!=0) //double protection
    {
        printf("Erreur fermeture fichier %s\n",filename);
        abort();
    }
}



void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu)
{
    const char* _0x10="joueur 0 (elephant)",*_0x01="joueur 1 (rhinoceros)";
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
    *_0x02=_0x03;}}}if(jeu_etre_integre(&_))*__=_;else printf(_while,_0x00);
}


void entree_sortie_ecrire_jeu_pointeur_fichier(FILE* identifiant,const jeu_siam* jeu)
{
    assert(identifiant!=NULL);
    assert(jeu!=NULL);


    const plateau_siam* plateau=&jeu->plateau;
    assert(plateau!=NULL);

    fprintf(identifiant,"joueur %d (%s)\n",jeu->joueur,type_nommer(jeu_obtenir_type_animal_courant(jeu)));

    entree_sortie_ecrire_plateau_pointeur_fichier(identifiant,plateau);

}





void entree_sortie_ecrire_plateau_pointeur_fichier(FILE* identifiant,const plateau_siam* plateau)
{
    const char* (*_00x00_)(type_piece)=type_nommer_nom_cours,*(*_01)(orientation_deplacement)=orientation_nommer_nom_cours;
    FILE* _=identifiant;int _0x00,(*__)(FILE*,const char*,...)=fprintf,_0x01,_0x20,_0x11;
    const piece_siam* _0x10,*_0x02=*plateau->piece;
    for(_0x20  =0x00;_0x20<0x10-0x05;_0x20+=0x01)
    {if(_0x20==0x02){for(_0x00=0x04;_0x00>=0x00;--_0x00)
    {__(_,"[%d] ",_0x00);for(_0x01=0x00;_0x01<010-03&&05<0x080;++_0x01)
    {_0x10=&(0x05*_0x01+_0x00)[_0x02];for(_0x11=0;_0x11<0x04+0x04;++_0x11)
    {if(_0x11==0x05){__(_,"%s",_00x00_(_0x10->type));
    if(_0x10->type==0x00 || _0x10->type==0x01)__(_,"-%s",_01(_0x10->orientation));
    }}__(_," | ");}__(_,"\n");}}}__(_,"    ");for(_0x01=0;_0x01<0x05;++_0x01){
    __(_,"[%d]   ",_0x01);}__(_,"\n");
}



