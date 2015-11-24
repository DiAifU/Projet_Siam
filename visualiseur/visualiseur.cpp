
/********************************************************/
/* Chargement fichier off                               */
/********************************************************/

#include "jeu_siam.h"
#include "entree_sortie.h"
#include "api.h"

/* inclusion des fichiers d'en-tete Glut */
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>


const char *fichier_a_lire="../bin/etat_courant.txt";



/* Notre structure point */
typedef struct
{
  float x[3];
} vec3;

typedef struct
{
  int index[3];
} index_triangle;
typedef struct
{
  std::vector <vec3> geometry;
  std::vector <vec3> normal;
  std::vector <index_triangle> connectivity;
} mesh;

void mesh_scale(mesh *m,double s);
void mesh_translate(mesh *m,float tx,float ty,float tz);

//void* analyse_texte(void *data);

jeu_siam jeu_a_visualiser;


mesh mesh_0,mesh_1,mesh_2,mesh_3,mesh_4;

mesh mesh_elephant;
mesh mesh_rhinoceros;
mesh mesh_rock;

char presse,presse_d=0;
int anglex=0,angley=45,translation_x=0,translation_y=0;
int camera_xold,camera_yold;
double zoom=-15.0;

/* Prototype des fonctions */
void affichage();
void clavier(unsigned char touche,int x,int y);
void reshape(int x,int y);
void idle(int );
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);
void draw_echiquier();
mesh load_off_file(const char* filename);

void draw_off(const mesh& mesh_to_draw);





void jeu_init(struct jeu* j);
void echiquier_lit(struct jeu *j1,struct jeu *j2,const char *fichier,int *joueur_a_jouer);
void echiquier_ecrit(const struct jeu *j1,const struct jeu *j2,const char *fichier);
int piece_est_valide(const struct piece *p);
void affiche_jeu();

time_t derniere_modification_fichier=0;
int joueur_a_jouer=1;
void affiche_coord();
float angle_for_orientation(orientation_deplacement orientation);



float angle_for_orientation(orientation_deplacement orientation)
{
    switch(orientation)
    {
    case haut:
        return 180;
    case bas:
        return 0;
    case gauche:
        return -90;
    case droite:
        return 90;
    default:
        puts("Probleme orientation");
        abort();
    }
}






int main(int argc,char **argv)
{

  if(argc>=2)
    {
      fichier_a_lire=argv[1];
    }
  printf("Visualiseur lit fichier %s\n",fichier_a_lire);


  jeu_initialiser(&jeu_a_visualiser);
  api_lire_fichier(&jeu_a_visualiser,fichier_a_lire);


  /* initialisation de glut et creation
     de la fenetre */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(550,550);
  glutCreateWindow("Test");

  /* Initialisation d'OpenGL */
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glPointSize(2.0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);

  /* enregistrement des fonctions de rappel */
  glutDisplayFunc(affichage);
  glutKeyboardFunc(clavier);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mousemotion);
  glutTimerFunc(100,idle,0);

  //light
  float light_ambient[4]={0.4,0.4,0.4,1.0};
  float light_diffuse[4]={0.4,0.4,0.4,1.0};
  float light_specular[4]={0.3,0.3,0.3,1.0};
  float light_position [4] = {2.0,100.0,100.0,1.0};

  float material_ambient [4] = {1.0,1.0,1.0,1.0};
  float material_diffuse [4] = {1.0,1.0,1.0,1.0};
  float material_specular [4] = {1.0,1.0,1.0,1.0};
  float material_exponent [1] = {60.0};


  glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);  
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);  
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material_exponent);
  glEnable(GL_DEPTH_TEST);



  mesh_rock=load_off_file("mesh/rock.off");
  mesh_scale(&mesh_rock,0.75);
  mesh_translate(&mesh_rock,0,-0.12,0);


  mesh_elephant=load_off_file("mesh/elephant.off");
  mesh_scale(&mesh_elephant,1);
  mesh_translate(&mesh_elephant,0,0,-0.215);

  mesh_rhinoceros=load_off_file("mesh/rhinoceros.off");
  mesh_scale(&mesh_rhinoceros,1);
  mesh_translate(&mesh_rhinoceros,0,0,-0.225);

  mesh_0=load_off_file("mesh/text/0.off"); mesh_scale(&mesh_0,0.4);
  mesh_1=load_off_file("mesh/text/1.off"); mesh_scale(&mesh_1,0.4);
  mesh_2=load_off_file("mesh/text/2.off"); mesh_scale(&mesh_2,0.4);
  mesh_3=load_off_file("mesh/text/3.off"); mesh_scale(&mesh_3,0.4);
  mesh_4=load_off_file("mesh/text/4.off"); mesh_scale(&mesh_4,0.4);



  /* Entree dans la boucle principale glut */
  glutMainLoop();
  return 0;
}

mesh load_off_file(const char* filename)
{

  mesh current_mesh;

#define SIZE_BUFFER 2048
  char buffer[SIZE_BUFFER]={'\0'};
  
  
  FILE *fid=NULL;
  fid=fopen(filename,"r");
  if(fid==NULL)
    {printf("ERROR loading %s in load_off_file\n",filename);exit(-1);}


  while(strcmp(buffer,"OFF")!=0)
    {
      if(fscanf(fid,"%s",buffer)==EOF)
	{printf("ERROR file %s is not off file\n",filename);exit(-1);}
      if(buffer[0]=='#')//comments
	fgets(buffer,sizeof(buffer),fid);
    }


  //pass comments
  fscanf(fid,"%s",buffer);
  while(buffer[0]=='#')//comments
    {
      fgets(buffer,sizeof(buffer),fid);
      fscanf(fid,"%s",buffer);
    }


  //read Number of vertices
  int N_vertex=0,N_polygon=0;
  int k_vertex=0;
  N_vertex=atoi(buffer);//N_vertex
  fscanf(fid,"%d",&N_polygon);//N_polygon
  fgets(buffer,sizeof(buffer),fid);//read line


  //read vertices
  float X[3];
  vec3 temp_sommet;
  while(k_vertex<N_vertex)
    {
      if(fscanf(fid,"%f %f %f",X,X+1,X+2)!=3)
	{
	  fscanf(fid,"%s",buffer);
	  if(buffer[0]!='#')
	    {printf("ERROR loading %s\n",filename);exit(-1);}
	  else//read line
	    fgets(buffer,sizeof(buffer),fid);
	}
      else
	{
	  for(int k=0;k<3;k++)
	    temp_sommet.x[k]=X[k];
	  current_mesh.geometry.push_back(temp_sommet);

	  k_vertex++;
	}
    }

  //read connectivity
  int size_poly=0;
  int k_polygon=0;
  int k_current_polygon=0;
  int temp=0;
  std::vector <int> v_poly;
  index_triangle temp_triangle;
  for(k_polygon=0;k_polygon<N_polygon;k_polygon++)
  {
      if(fscanf(fid,"%d",&size_poly)!=1)
      {
          fscanf(fid,"%s",buffer);
          if(buffer[0]!='#')
          {printf("ERROR loading triangles in load_off_file %s\n",filename);exit(-1);}
          else//read line
          {
              fgets(buffer,sizeof(buffer),fid);
              k_polygon--;
          }
      }
      else
      {
          v_poly.resize(0);
          for(k_current_polygon=0;k_current_polygon<size_poly;k_current_polygon++)
          {
              fscanf(fid,"%d",&temp);
              v_poly.push_back(temp);
          }

          for(unsigned int k=0;k<v_poly.size()-2;k++)
          {
              temp_triangle.index[0]=v_poly[0];
              temp_triangle.index[1]=v_poly[k+1];
              temp_triangle.index[2]=v_poly[k+2];
              current_mesh.connectivity.push_back(temp_triangle);
          }


      }
  }

  printf("[Chargement fichier %s OK]\n",filename);


  //compute normals
  {

      current_mesh.normal.resize(current_mesh.geometry.size());

      const int N=current_mesh.connectivity.size();
      float X0[3],X1[3],X2[3];
      for(int tri=0;tri<N;++tri)
      {
          for(int k=0;k<3;k++)
          {
              X0[k] = current_mesh.geometry[current_mesh.connectivity[tri].index[0]].x[k];
              X1[k] = current_mesh.geometry[current_mesh.connectivity[tri].index[1]].x[k];
              X2[k] = current_mesh.geometry[current_mesh.connectivity[tri].index[2]].x[k];
          }

          float u[3],v[3];
          for(int k=0;k<3;u[k]=X1[k]-X0[k],v[k]=X2[k]-X0[k],k++);

          float normal[3];
          normal[0]=u[1]*v[2]-u[2]*v[1];
          normal[1]=u[2]*v[0]-u[0]*v[2];
          normal[2]=u[0]*v[1]-u[1]*v[0];

          float n = powf(normal[0]*normal[0]+normal[1]*normal[1]+normal[2]*normal[2],0.5);
          if(n>=0.0001)
              for(int k=0;k<3;k++)
                  normal[k]/=n;

          for(int k_dim=0;k_dim<3;++k_dim)
          {
              current_mesh.normal[current_mesh.connectivity[tri].index[0]].x[k_dim]+=normal[k_dim];
              current_mesh.normal[current_mesh.connectivity[tri].index[1]].x[k_dim]+=normal[k_dim];
              current_mesh.normal[current_mesh.connectivity[tri].index[2]].x[k_dim]+=normal[k_dim];
          }

      }

      for(unsigned int k=0;k<current_mesh.normal.size();++k)
      {
          vec3 normal=current_mesh.normal[k];
          float n=sqrt(normal.x[0]*normal.x[0]+normal.x[1]*normal.x[1]+normal.x[2]*normal.x[2]);
          current_mesh.normal[k].x[0]/=n;
          current_mesh.normal[k].x[1]/=n;
          current_mesh.normal[k].x[2]/=n;
      }
  }

  return current_mesh;
}


void affichage()
{

  /* effacement de l'image avec la couleur de fond */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  //Projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective (45, 1.0, 0.05,1000.0);

  
  //Modelview
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0,0.0,zoom);
  glRotatef(-angley/6.0,1.0,0.0,0.0);
  glRotatef(-anglex/6.0,0.0,0.0,1.0);
  glTranslatef(-2.5,-2.5,0.0);



  float light_specular_echiquier[4]={0.1,0.1,0.1,1.0};
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular_echiquier);

  draw_echiquier();



  float light_specular_piece[4]={0.6,0.6,0.6,1.0};
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular_piece);


  affiche_jeu();


  float light_specular_text[4]={0.2,0.2,0.2,1.0};
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular_text);

  affiche_coord();


  
  /* On echange les buffers */
  glutSwapBuffers();
}

void clavier(unsigned char touche,int ,int )
{
  switch (touche)
    {
    case 'p': /* affichage normal */
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glutPostRedisplay();
      break;
    case 'f': /* affichage en mode fil de fer */
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glutPostRedisplay();
      break;
    case 's' : /* Affichage en mode sommets seuls */
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glutPostRedisplay();
      break;
    case 'q' : /*la touche 'q' permet de quitter le programme */
      exit(0);
      break;

    default:
      break;
    }
}

void reshape(int x,int y)
{
  if (x<y)
    glViewport(0,(y-x)/2,x,x);
  else 
    glViewport((x-y)/2,0,y,y);
}

void mouse(int button, int state,int x,int y)
{
  /* si on appuie sur le bouton gauche */
  if(state == GLUT_DOWN) 
  {
    camera_xold = x; /* on sauvegarde la position de la souris */
    camera_yold=y;
  }
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    presse=1;
  if(button == GLUT_LEFT_BUTTON && state==GLUT_UP)
    presse=0;

  if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    presse_d=1;
  if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
    presse_d=0;

}

void draw_echiquier()
{
  float e=0.2;
  glBegin(GL_QUADS);
  for(unsigned int kx=0;kx<5;++kx)
    {
      for(unsigned int ky=0;ky<5;++ky)
	{
	  if((kx+ky)%2==0)
        glColor3f(0.05,0.05,0.05);
	  else
	    glColor3d(0.8,0.8,0.8);

	  glNormal3f(0,0,1);
	  glVertex3f(kx,ky,0.0);
	  glVertex3f(kx+1,ky,0.0);
	  glVertex3f(kx+1,ky+1,0.0);
	  glVertex3f(kx,ky+1,0.0);

	  glNormal3f(0,0,-1);
	  glVertex3f(kx,ky,-e);
	  glVertex3f(kx+1,ky,-e);
	  glVertex3f(kx+1,ky+1,-e);
	  glVertex3f(kx,ky+1,-e);

	  glNormal3f(0,-1,0);
	  glVertex3f(kx,ky,0.0);
	  glVertex3f(kx+1,ky,0.0);
	  glVertex3f(kx+1,ky,-e);
	  glVertex3f(kx,ky,-e);

	  glNormal3f(-1,0,0);
	  glVertex3f(kx,ky,0.0);
	  glVertex3f(kx,ky+1,0.0);
	  glVertex3f(kx,ky+1,-e);
	  glVertex3f(kx,ky,-e);

	  glNormal3f(0,1,0);
	  glVertex3f(kx,ky+1,0.0);
	  glVertex3f(kx+1,ky+1,0.0);
	  glVertex3f(kx+1,ky+1,-e);
	  glVertex3f(kx,ky+1,-e);

	  glNormal3f(1,0,0);
	  glVertex3f(kx+1,ky,0.0);
	  glVertex3f(kx+1,ky+1,0.0);
	  glVertex3f(kx+1,ky+1,-e);
	  glVertex3f(kx+1,ky,-e);
	}
    }
  glEnd();


}

void mousemotion(int x,int y)
{
  if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
      anglex=anglex-(x-camera_xold); 
      angley=angley-(y-camera_yold);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }
  if(presse_d)
    {
      zoom = zoom + (y-camera_yold)/50.0;
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }

  
  camera_xold=x; /* sauvegarde des valeurs courante de le position de la souris */
  camera_yold=y;
}

void draw_elephant(float x,float y,orientation_deplacement orientation)
{
    glPushMatrix();
    glTranslatef(x+0.5,y+0.5,0.5);
    glRotatef(angle_for_orientation(orientation),0,0,1);

    draw_off(mesh_elephant);

    glPopMatrix();
}

void draw_rhinoceros(float x,float y,orientation_deplacement orientation)
{
    glPushMatrix();
    glTranslatef(x+0.5,y+0.5,0.5);
    glRotatef(angle_for_orientation(orientation),0,0,1);

    draw_off(mesh_rhinoceros);

    glPopMatrix();
}

void draw_rock(float x,float y)
{
    glPushMatrix();
    glTranslatef(x+0.5,y+0.5,0.5);
    glRotatef(90,1,0,0);

    draw_off(mesh_rock);

    glPopMatrix();
}





void draw_off(const mesh& mesh_to_draw)
{
  int i=0;

  glPushMatrix();
  glTranslatef(translation_x,translation_y,0.0);

  int N=mesh_to_draw.connectivity.size();
  glBegin(GL_TRIANGLES);

  float X0[3],X1[3],X2[3];
  float N0[3],N1[3],N2[3];
  double u[3],v[3];
  double normal[3],n;
  for(i=0;i<N;i++)
  {
      for(int k=0;k<3;k++)
      {
          X0[k] = mesh_to_draw.geometry[mesh_to_draw.connectivity[i].index[0]].x[k];
          X1[k] = mesh_to_draw.geometry[mesh_to_draw.connectivity[i].index[1]].x[k];
          X2[k] = mesh_to_draw.geometry[mesh_to_draw.connectivity[i].index[2]].x[k];

          N0[k] = mesh_to_draw.normal[mesh_to_draw.connectivity[i].index[0]].x[k];
          N1[k] = mesh_to_draw.normal[mesh_to_draw.connectivity[i].index[1]].x[k];
          N2[k] = mesh_to_draw.normal[mesh_to_draw.connectivity[i].index[2]].x[k];
      }
      for(int k=0;k<3;u[k]=X1[k]-X0[k],v[k]=X2[k]-X0[k],k++);
      

      //normal
      normal[0]=u[1]*v[2]-u[2]*v[1];
      normal[1]=u[2]*v[0]-u[0]*v[2];
      normal[2]=u[0]*v[1]-u[1]*v[0];
      n = powf(normal[0]*normal[0]+normal[1]*normal[1]+normal[2]*normal[2],0.5);
      if(n>=0.0001)
          for(int k=0;k<3;k++)
              normal[k]/=n;


      //vertex
      glNormal3fv(N0);
      glVertex3fv(X0);
      glNormal3fv(N1);
      glVertex3fv(X1);
      glNormal3fv(N2);
      glVertex3fv(X2);

  }

  glEnd();

  glPopMatrix();
}
	
	
void affiche_jeu()
{
    const plateau_siam* plateau=&jeu_a_visualiser.plateau;
    for(int kx=0;kx<5;++kx)
    {
        for(int ky=0;ky<5;++ky)
        {
            const piece_siam* piece_courante=plateau_obtenir_piece_info(plateau,kx,ky);

            switch(piece_courante->type)
            {
            case rocher:
                glColor3f(0.9,0.9,0.8);
                draw_rock(kx,ky);
                break;
            case elephant:
                glColor3f(0.81,0.72,0.63);
                draw_elephant(kx,ky,piece_courante->orientation);
                break;
            case rhinoceros:
                glColor3f(0.4,0.4,0.35);
                draw_rhinoceros(kx,ky,piece_courante->orientation);
                break;
            case case_vide:
                break;//n'affiche rien
            default:
                puts("Probleme type piece courante");
                abort();
            }
        }
    }

    const int N_elephant=5-plateau_denomber_type(plateau,elephant);
    const int N_rhinoceros=5-plateau_denomber_type(plateau,rhinoceros);

    glColor3f(0.81,0.72,0.63);
    for(int k=0;k<N_elephant;++k)
        draw_elephant(k,-2,haut);

    glColor3f(0.4,0.4,0.35);
    for(int k=0;k<N_rhinoceros;++k)
        draw_rhinoceros(k,6,haut);


}




void idle(int )
{
  glutPostRedisplay();
  glutTimerFunc(300,idle,0);

  struct stat stat_buffer;
  int stat_return;
  stat_return=stat(fichier_a_lire,&stat_buffer);

  if(stat_return!=0)
    printf("Erreur stat fichier\n");

  if(derniere_modification_fichier!=stat_buffer.st_mtime)
    {
      derniere_modification_fichier=stat_buffer.st_mtime;
      api_lire_fichier(&jeu_a_visualiser,fichier_a_lire);
      glutPostRedisplay();
    }

  
}


void affiche_coord()
{
  glColor3f(0.1,0.1,0.5);

  glPushMatrix();
  glRotatef(180,1,0,0);
  glTranslatef(0,1.0,0.0);
  glTranslatef(0.5,-0.5,0.0);
  draw_off(mesh_0);
  glTranslatef(1.0,0.0,0.0);
  draw_off(mesh_1);
  glTranslatef(1.0,0.0,0.0);
  draw_off(mesh_2);
  glTranslatef(1.0,0.0,0.0);
  draw_off(mesh_3);
  glTranslatef(1.0,0.0,0.0);
  draw_off(mesh_4);

  glPopMatrix();

  glPushMatrix();
  glRotatef(180,1,0,0);
  glRotatef(-90,0,0,1);
  glTranslatef(0,0.0,0.0);
  glTranslatef(0.5,-0.5,0.0);
  draw_off(mesh_0);
  glTranslatef(1.0,0.0,0.0);
  draw_off(mesh_1);
  glTranslatef(1.0,0.0,0.0);
  draw_off(mesh_2);
  glTranslatef(1.0,0.0,0.0);
  draw_off(mesh_3);
  glTranslatef(1.0,0.0,0.0);
  draw_off(mesh_4);

  glPopMatrix();
}

void mesh_scale(mesh *m,double s)
{
  unsigned int N=m->geometry.size();
  for(unsigned int k=0;k<N;++k)
    {
      for(unsigned int k_dim=0;k_dim<3;++k_dim)
	m->geometry[k].x[k_dim]*=s;
    }
}

void mesh_translate(mesh *m,float tx,float ty,float tz)
{
  unsigned int N=m->geometry.size();
  for(unsigned int k=0;k<N;++k)
    {
      m->geometry[k].x[0]+=tx;
      m->geometry[k].x[1]+=ty;
      m->geometry[k].x[2]+=tz;
    }
}


