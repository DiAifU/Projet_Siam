

#include "mode_interactif.h"
#include "api_siam.h"
#include "parseur_mode_interactif.h"
#include "entree_sortie.h"


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void mode_interactif_lancer()
{

    puts("\n***********************");
    puts("Jeu SIAM mode interactif:");
    puts("***********************");
    puts("Commandes:");
    puts("> #                 : Commentaires, tout ce qui suit # n'est pas analyse.");
    puts("> i                 : [I]nitialisation du jeu.");
    puts("> n x0 y0 dir       : [N]ouvelle piece introduite en (x0,y0) avec direction indiquee.");
    puts("> d x0 y0 dir0 dir1 : [D]eplacement piece de (x0,y0) dans le sens dir0 indique");
    puts("                         et ayant la direction dir1 a l'arrive.");
    puts("> o x0 y0 dir       : [O]rientation nouvelle de la piece en (x0,y0).");
    puts("> lit [NOM_FICHIER] : Lire un fichier externe.");
    puts("");
    puts("directions possibles: gauche <, droite >, haut ^, bas v.");
    printf("***********************\n\n");
    fflush(stdout);



    int victoire=0;
    jeu_siam jeu;
    jeu_initialiser(&jeu);

    action_a_realiser action;
    action_initialiser(&action);

    mode_interactif_sauvegarder_jeu_fichier(&jeu);

    char buffer_ligne_commande[MAX_NOM_FICHIER_TAILLE];

    do
    {
        puts("");fflush(stdout);
        jeu_afficher(&jeu);

        printf("> ");
        fflush(stdout);

        fgets(buffer_ligne_commande,MAX_LIGNE_COMMANDE,stdin);
        ligne_de_commande_parser(buffer_ligne_commande,&action);
        switch(action.type_action)
        {
        case deplacement:
            mode_interactif_deplacer_piece(&jeu,action.x_depart,action.y_depart,action.deplacement,action.orientation,&victoire);
            break;
        case introduction:
            mode_interactif_introduire_nouvelle_piece(&jeu,action.x_depart,action.y_depart,action.orientation,&victoire);
            break;
        case changement_orientation:
            mode_interactif_changer_orientation(&jeu,action.x_depart,action.y_depart,action.orientation);
            break;
        case lecture_fichier:
            mode_interactif_lire_fichier(&jeu,action.filename);
            break;
        case initialisation:
            printf("Initialisation du jeu\n");fflush(stdout);
            jeu_initialiser(&jeu);
            mode_interactif_sauvegarder_jeu_fichier(&jeu);
            break;
        case fin:
            printf("Fin de la partie\n");fflush(stdout);
            break;
        default:
            puts("\nLigne non valide, action non realisee\n");fflush(stdout);
            break;
        }

    } while(action.type_action!=fin && victoire==0);
}



int mode_interactif_parametres_etre_valides(const jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));

    if(coordonnees_etre_dans_plateau(x,y)==0)
    {
        puts("Coordonnees invalides");
        return 0;
    }

    if(orientation_etre_integre_deplacement(orientation)==0)
    {
        puts("Orientation invalide");
        return 0;
    }

    return 1;
}



void mode_interactif_introduire_nouvelle_piece(jeu_siam* jeu,int x,int y,orientation_deplacement orientation,int* victoire)
{
    assert(jeu!=NULL);
    assert(victoire!=NULL);

    if(mode_interactif_parametres_etre_valides(jeu,x,y,orientation))
    {
        coup_jeu coup=api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu,x,y,orientation);
        if(coup_etre_valide(&coup))
        {
            printf("  n %d %d %s\n",x,y,orientation_nommer_nom_cours(orientation));

            mode_interactif_sauvegarder_jeu_fichier(jeu);
            if(coup_etre_victorieux(&coup))
            {
                coup_afficher_victoire(&coup);
                *victoire=1;
            }
        }
        else
            puts("Echec introduction piece impossible");
    }
    else
        printf("Introduction piece impossible aux coordonnees %d %d\n",x,y);


}

void mode_interactif_deplacer_piece(jeu_siam* jeu,int x,int y,orientation_deplacement deplacement,orientation_deplacement orientation,int* victoire)
{
    assert(jeu!=NULL);
    assert(victoire!=NULL);

    if(mode_interactif_parametres_etre_valides(jeu,x,y,orientation))
    {
        coup_jeu coup=api_siam_tenter_deplacer_piece_si_possible(jeu,x,y,deplacement,orientation);
        if(coup_etre_valide(&coup))
        {
            printf("  d %d %d %s %s\n",x,y,orientation_nommer_nom_cours(deplacement),orientation_nommer_nom_cours(orientation));
            mode_interactif_sauvegarder_jeu_fichier(jeu);
            if(coup_etre_victorieux(&coup))
            {
                coup_afficher_victoire(&coup);
                *victoire=1;
            }
        }
        else
            puts("Echec deplacement piece impossible");
    }
    else
        printf("Deplacement piece (%d,%d) impossible \n",x,y);

}

void mode_interactif_changer_orientation(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
    assert(jeu!=NULL);

    if(mode_interactif_parametres_etre_valides(jeu,x,y,orientation))
    {
        coup_jeu coup=api_siam_tenter_changer_orientation_piece_si_possible(jeu,x,y,orientation);
        if(coup_etre_valide(&coup))
        {
            printf("  o %d %d %s\n",x,y,orientation_nommer_nom_cours(orientation));
            mode_interactif_sauvegarder_jeu_fichier(jeu);
        }
        else
            puts("Echec changement orientation piece impossible");
    }
    else
        printf("Changement orientation piece (%d,%d) impossible \n",x,y);

}

void mode_interactif_sauvegarder_jeu_fichier(const jeu_siam* jeu)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));
    entree_sortie_ecrire_jeu_fichier("etat_courant.txt",jeu);
}

void mode_interactif_lire_fichier(jeu_siam* jeu,const char* filename)
{
    assert(jeu!=NULL);
    assert(filename!=NULL);

    if(!entree_sortie_fichier_etre_accessible(filename) || !entree_sortie_fichier_exister(filename))
        printf("Fichier %s non accessible en lecture\n",filename);
    else
    {
        entree_sortie_lire_jeu_fichier(filename,jeu);
        mode_interactif_sauvegarder_jeu_fichier(jeu);

        printf(" lit %s\n",filename);
    }

    assert(jeu_etre_integre(jeu));
}

