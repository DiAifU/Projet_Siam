


#include "parseur_mode_interactif.h"


#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void action_initialiser(action_a_realiser* action)
{

    assert(action!=NULL);

    action->type_action=aucune_action;
    strcpy(action->filename,"\0");
    action->x_depart=-1;
    action->y_depart=-1;
    action->orientation=aucune_orientation;
}

void ligne_de_commande_parser(const char* ligne_commande,action_a_realiser* action)
{
    assert(action!=NULL);

    action_initialiser(action);

    if(ligne_commande==NULL)
        return ;

    if(strlen(ligne_commande)>=1 && ligne_commande[0]=='#')
        return ;



    else if(strlen(ligne_commande)>=3 &&
            (strncmp(ligne_commande,"FIN",3)==0 ||
             strncmp(ligne_commande,"fin",3)==0 ||
             strncmp(ligne_commande,"Fin",3)==0) )
    {
        action->type_action=fin;
        return ;
    }


    else if(strlen(ligne_commande)>=2 && ligne_commande[0]=='n' && ligne_commande[1]==' ')
    {
        int x=0;int y=0;char dir='\0';
        if(sscanf(ligne_commande,"n %d %d %c",&x,&y,&dir)==3)
        {
            if(orientation_caractere_etre_integre(dir))
            {
                action->type_action=introduction;
                action->x_depart=x;
                action->y_depart=y;
                action->orientation=orientation_correspondre_caractere(dir);

                return ;
            }
        }
    }


    else if(strlen(ligne_commande)>=2 && ligne_commande[0]=='d' && ligne_commande[1]==' ')
    {
        int x=0;int y=0;char dir='\0';char ori='\0';
        if(sscanf(ligne_commande,"d %d %d %c %c",&x,&y,&dir,&ori)==4)
        {
            if(orientation_caractere_etre_integre(dir))
            {
                action->type_action=deplacement;
                action->x_depart=x;
                action->y_depart=y;
                action->deplacement=orientation_correspondre_caractere(dir);
                action->orientation=orientation_correspondre_caractere(ori);

                return ;
            }
        }
    }



    else if(strlen(ligne_commande)>=2 && ligne_commande[0]=='o' && ligne_commande[1]==' ')
    {
        int x=0;int y=0;char dir=0;
        if(sscanf(ligne_commande,"o %d %d %c",&x,&y,&dir)==3)
        {
            if(orientation_caractere_etre_integre(dir))
            {
                action->type_action=changement_orientation;
                action->x_depart=x;
                action->y_depart=y;
                action->orientation=orientation_correspondre_caractere(dir);

                return ;
            }
        }
    }


    else if(strlen(ligne_commande)>=1 && ligne_commande[0]=='i')
    {
        action->type_action=initialisation;
        return;
    }


    else if(strlen(ligne_commande)>=4 && strncmp(ligne_commande,"lit ",4)==0)
    {
        char buffer_filename[MAX_NOM_FICHIER_TAILLE];
        if(sscanf(ligne_commande,"lit %s",buffer_filename)==1)
        {
            action->type_action=lecture_fichier;
            strncpy(action->filename,buffer_filename,128);
            return ;
        }
    }



}



