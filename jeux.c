#include<graph.h>
#include<stdio.h>
#include<time.h>
#include <stdlib.h>

#include "graphique.h"
#include "jeux.h"
 
#define tx 700
#define ty 600

struct valeur1{
	int x;
	int y;
}valeur1;

struct valeur2{
	int x;
	int y;
}valeur2;

struct croix1{
	int x;
	int y;
}croix1;

struct croix2{
	int x;
	int y;
}croix2; 

struct param{
	int tour;
	int tmp;
	int tab[15][15];
	int pion[15][15];
	int joueur;
}param;


void jeux2j(int taille){ /*cette fonction recupere la position du clic de la souris*/
int i=0;
int j=0;
int tmp_1_x=0;
int tmp_1_y=0;
int tmp_2_x=0;
int tmp_2_y=0;
EffacerEcran(CouleurParComposante(17,122,101));
afficher_pion(taille);
	while(1){
	    while(SourisCliquee()){
			SourisPosition();
			for (i = 0; i < taille; ++i){
				
				if((_X>=50+(50*i) && _X<=150+(50*i))&&(_Y>=50 && _Y<=50+(50*taille))){

					for (j = 0; j < taille; ++j)
					{

						if((_X>=50 && _X<=50+(50*taille))&&(_Y>=50+(50*j) && _Y<=150+(50*j))){
											
							

							if (param.tour==1){/*pion j1*/
								
								

								if (param.tmp==0)
								{
									valeur1.x=j;
									valeur1.y=i;
								}
								else{
									tmp_1_x=j;
									tmp_1_y=i;
								}
							}

							
							else if (param.tour==2){/*croix j1*/
								croix1.x=i;
								croix1.y=j;
							}
							
							
							else if (param.tour==3){/*pion j2*/
								
								if (param.tmp==0)
								{
									valeur2.x=j;
									valeur2.y=i;
								}
								else{
									tmp_2_x=j;
									tmp_2_y=i;
								}							
							}

							else if (param.tour==4){/*croix j2*/
								
								croix2.x=i;
								croix2.y=j;					
							}
						}
					}
				}
			}

			
			afficher_tab(taille);

			

			if (param.tour==1){
				if (param.tmp==0){
					param.tour=3;
				}
				else{
					int ecart_1_x = 0;
					int ecart_1_y = 0;

					ecart_1_x = valeur1.x-tmp_1_x;
					ecart_1_y = valeur1.y-tmp_1_y;

					if((ecart_1_x<=1 && ecart_1_x>=-1) && ((ecart_1_y<=1) && ecart_1_y>=-1)){ 
					/*deplacerment j1 apres t1*/
										
						valeur1.x=tmp_1_x;
						valeur1.y=tmp_1_y;
					}
					else{
						printf("tu peut pas jouer ici\n ");
						jeux2j(taille);
					}
					param.tour++;
				}			
				afficher_pion(taille);
			}
			else if (param.tour==2){
				afficher_croix(taille);
				param.tour++;
			}

			else if (param.tour==3){
				if (param.tmp==0)
				{
					
					param.tmp=1;
					param.tour=1;

					afficher_pion(taille);
					jeux2j(taille);
				}
				else{
					int ecart_2_x = 0;
					int ecart_2_y = 0;

					ecart_2_x = valeur2.x-tmp_2_x;
					ecart_2_y = valeur2.y-tmp_2_y;

					if((ecart_2_x<=1 && ecart_2_x>=-1) && ((ecart_2_y<=1) && ecart_2_y>=-1)){ 
					   /*deplacerment j2 apres t1*/
										
						valeur2.x=tmp_2_x;
						valeur2.y=tmp_2_y;
					}
					else{
						printf("tu peut pas jouer ici\n ");
						jeux2j(taille);
					}
					param.tour++;
				}	
				afficher_pion(taille);	
			}
			else if (param.tour==4){
				afficher_croix(taille);
				verif(param.tour-1,taille);
				param.tour=1;
				jeux2j(taille);
			}

			verif(param.tour,taille);
		}
	}
}

void afficher_pion(int taille){ 
	couleur b;
	couleur w;
	b=CouleurParNom("black");
	w=CouleurParNom("white");
	EffacerEcran(CouleurParComposante(17,122,101));
	afficher_croix(taille);
	ChoisirCouleurDessin(b);
	RemplirArc(55+(50*valeur1.y),55+(50*valeur1.x),40,40,0,360);
	ChoisirCouleurDessin(w);
	RemplirArc(55+(50*valeur2.y),55+(50*valeur2.x),40,40,0,360);
	afficher_tab(taille);
	afficher_graph(taille);
}

 
void afficher_croix(int taille){
	if (param.tour==2){		
		ChargerSprite("./croix_projet_noir.png");
		AfficherSprite(1,50+(50*croix1.x),50+(50*croix1.y));
	} 
	if (param.tour==4){
		ChargerSprite("./croix_projet_blanc.png");
		AfficherSprite(2,50+(50*croix2.x),50+(50*croix2.y));
	}

}


void afficher_tab(int taille){/*Cette fonction affiche le tableau dans le terminal*/

	if (param.tmp==0)
	{
		for (int i = 0; i < taille; ++i){/*initialiser le tableau a 0*/
			for (int j = 0; j <= taille; ++j){
				param.tab[j][i]=0;
			}
		}
	}
/*
	if(param.pion[croix1.x][croix1.y]!=0){/ *Fonction de verif de superposition* /
		printf("il y a deja quelque chose \n");
		param.tab[croix1.x][croix1.y]=0;
		croix1.x=12;
		croix1.x=12;
		jeux2j(taille);
	}*/

	for (int i = 0; i < taille; ++i){/*remplie le tableau de croix*/
		for (int j = 0; j <= taille; ++j){
			param.tab[croix1.y][croix1.x]=2;
			param.tab[croix2.y][croix2.x]=4;
		}
	}
	

	

	for (int i = 0; i < taille; i++){/*Affichage des croix noir sur le graphique */
	    for (int j = 0; j < taille; j++){
	    	if(param.tab[i][j]==2){
	        	ChargerSprite("./croix_projet_noir.png");
				AfficherSprite(3,50+(50*j),50+(50*i));
			}
	    }
	}

	for (int a = 0; a < taille; a++){/*Affichage des croix blanche sur le graphique */
	    for (int b = 0; b < taille; b++)
	    {
	    	if (param.tab[a][b]==4){
	    		if (param.joueur==1){
	        		ChargerSprite("./croix_projet_blanc.png");
					AfficherSprite(4,50+(50*b),50+(50*a));
	    		}
	    		else if(param.joueur==2){
	        		ChargerSprite("./croix_projet_blanc.png");
					AfficherSprite(5,50+(50*b),50+(50*a));
	    		}
	        }
	    }
	}

	for (int i = 0; i < taille; ++i){/*initialiser le tableau des pion a 0*/
		for (int j = 0; j <= taille; ++j){
			param.pion[j][i]=0;
			param.pion[valeur1.x][valeur1.y]=1;
			param.pion[valeur2.x][valeur2.y]=3;
		}
	}
	
	/*
	printf("tableau de croix\n");
	for (int i = 0; i < taille; i++){/ *Affichage du tableau dans le terminal * /
	    for (int j = 0; j < taille; j++){ 
	    	printf("%d ", param.tab[i][j]);
	    } 
	    printf("\n");
	}
	printf("\n");
	printf("tableau de pion\n");
	for (int i = 0; i < taille; i++){/ *Affichage du tableau dans le terminal * /
	    for (int j = 0; j < taille; j++){  
	    	printf("%d ", param.pion[i][j]);
	    } 
	    printf("\n");
	}
	printf("\n");*/
}



void afficher_graph(int taille){ /*Cette fonction affiche le graph en mode graphique*/
	couleur b;
	b=CouleurParNom("black");
	ChoisirCouleurDessin(b);
	for (int i = 0; i <= taille; ++i)
    {
    	DessinerSegment(50+(50*i),50,50+(50*i),50+(50*taille));
    	for (int i = 0; i <= taille; ++i)
    	{
    		DessinerSegment(50,50+(50*i),50+(50*taille),50+(50*i));
    	}
    }

}

void lancerfenetre(int taille, int joueur){/* Cette fonction ouvre la fenetre de jeu*/
	InitialiserGraphique();
	if (taille==3){
		CreerFenetre(700,400,250,250);
	}

	if (taille==4){
		CreerFenetre(675,400,300,300);
	}

	if (taille==5){
		CreerFenetre(650,400,350,350);
	}

	if (taille==6){
		CreerFenetre(625,400,400,400);
	}

	if (taille==7){
		CreerFenetre(600,400,450,450);
	}

	if (taille==8){
		CreerFenetre(575,400,500,500);
	}

	if (taille==9){
		CreerFenetre(550,250,550,550);
	}
	
 	param.joueur=joueur;
    afficher_tab(taille);
    afficher_graph(taille);
    if (joueur==1){
    	jeux1j(taille);
    }
    if (joueur==2){		
		jeux2j(taille);
	}
    
     
    Touche();
    FermerGraphique();
}

void jeux(int joueur,int taille){


	param.tour=1;
	param.tmp=0;
	valeur1.x=10;
	valeur1.y=11;
	valeur2.x=11;
	valeur2.y=12;
	croix1.x=12;
	croix1.y=13;
	croix2.x=13;
	croix2.y=14;


	if ( joueur==1){
		printf("1 joueur \n");

		lancerfenetre(taille,joueur);
	}

	if (joueur==2){
		printf("2 joueur \n");
		
		lancerfenetre(taille,joueur);
	}
}

void jeux1j(int taille){ /*cette fonction recupere la position du clic de la souris*/

srand(time(NULL));

int j=0;
int i=0;
int tmp_x=0;
int tmp_y=0;
int casej2=0;


EffacerEcran(CouleurParComposante(17,122,101));
afficher_pion(taille);
	while(param.tour==1 || param.tour==2){
	    if(SourisCliquee()){
			SourisPosition();
			for (i = 0; i < taille; ++i){
				if ((_X<50 && _X>50+(taille*50)) && (_Y<50 && _Y>50+(taille*50)) )
				{
					printf("hors du graph\n");
				}
				
				if((_X>=50+(50*i) && _X<=150+(50*i))&&(_Y>=50 && _Y<=50+(50*taille))){

					for (j = 0; j < taille; ++j)
					{

						if((_X>=50 && _X<=50+(50*taille))&&(_Y>=50+(50*j) && _Y<=150+(50*j))){
											
							

							if (param.tour==1){/*pion j1*/
								if (param.tmp==0)
								{

									valeur1.x=j;
									valeur1.y=i;
								}
								else{
									tmp_x=j;
									tmp_y=i;
								}																	
							}

							else if (param.tour==2){/*croix j1*/
									
								croix1.x=i;
								croix1.y=j;
							}
						}
					}
				}
			}

			afficher_tab(taille);

			if (param.tour==1){		
				
				if (param.tmp==0){
					param.tour=3;
				}
				else{
					int ecart_x = 0;
					int ecart_y = 0;

					ecart_x = valeur1.x-tmp_x;
					ecart_y = valeur1.y-tmp_y;

					if((ecart_x<=1 && ecart_x>=-1) && ((ecart_y<=1) && ecart_y>=-1))
					 	{ /*deplacerment j1 apres t1*/
										
						valeur1.x=tmp_x;
						valeur1.y=tmp_y;
					}
					else{
						printf("tu peut pas jouer ici\n ");
						jeux1j(taille);
					}
					param.tour++;
				}			
				afficher_pion(taille);
			}
			else if (param.tour==2){
				afficher_croix(taille);
				param.tour++;
			}
			verif(param.tour-1,taille);
		}
	}

	while(param.tour==3 || param.tour==4){
		if (param.tour==3){/*pion j2*/
			if (param.tmp==0){
				valeur2.x=(rand()%(taille)); 
				valeur2.y=(rand()%(taille));

				sleep(1);
				afficher_pion(taille);
				param.tour=1;
				param.tmp=1;
				jeux1j(taille);		
			}
			else{
				casej2=(rand()%(8));
				if (casej2==0){
					/*printf("la case est haut gauche\n");*/
					valeur2.x=valeur2.x-1;
					valeur2.y=valeur2.y-1;
				}
				else if (casej2==1){
					/*printf("la case est haut centre\n");*/
					valeur2.x=valeur2.x-1;
				}	
				else if (casej2==2){
					/*printf("la case est haut droite\n");*/
					valeur2.x=valeur2.x-1;
					valeur2.y=valeur2.y+1;
				}	
				else if (casej2==3){
					/*printf("la case est gauche\n");*/
					valeur2.y=valeur2.y-1;
				}	
				else if (casej2==4){
					/*printf("la case est droite\n");*/
					valeur2.y=valeur2.y+1;
				}	
				else if (casej2==5){
					/*printf("la case est bas gauche\n");*/
					valeur2.x=valeur2.x+1;
					valeur2.y=valeur2.y-1;
				}
				else if (casej2==6){
					/*printf("la case est bas centre\n");*/
					valeur2.x=valeur2.x+1;
				}	
				else if (casej2==7){
					/*printf("la case est bas droite\n");*/
					valeur2.x=valeur2.x+1;
					valeur2.y=valeur2.y+1;
				}

				if (valeur2.x<0){
					valeur2.x=valeur2.x+2;
				}

				if (valeur2.y<0){
					valeur2.y=valeur2.y+2;
				}

				if(valeur2.x>taille-1){
					valeur2.x=valeur2.x-2;
				}

				if (valeur2.y>taille-1){
					valeur2.y=valeur2.y-2;
				}

				else{
					param.tour++;
					param.tmp=1;
				}
			}
		}

		else if (param.tour==4){/*croix j2*/

			croix2.x=(rand()%(taille));	
			croix2.y=(rand()%(taille));
			sleep(1);
			afficher_croix(taille);
			verif(param.tour-1,taille);
			param.tour=1;
			jeux1j(taille);					
		}
		verif(param.tour,taille);
	}
}

void verif(int tour,int taille){
	if (param.tmp!=0){
		/*-----------------------------------------------------------------j2*/
		if (((param.tab[valeur2.x-1][valeur2.y-1]!=0) ||
			(param.pion[valeur2.x-1][valeur2.y-1]!=0))&&
		    ((param.tab[valeur2.x-1][valeur2.y]!=0)   ||
		    (param.pion[valeur2.x-1][valeur2.y-1]!=0))&&
		    ((param.tab[valeur2.x-1][valeur2.y+1]!=0) ||
		    (param.pion[valeur2.x-1][valeur2.y+1]!=0))&&
		    ((param.tab[valeur2.x][valeur2.y-1]!=0)   ||
		    (param.pion[valeur2.x][valeur2.y-1]!=0))  &&
		    ((param.tab[valeur2.x][valeur2.y+1]!=0)   ||
		    (param.pion[valeur2.x][valeur2.y+1]!=0))  &&
		    ((param.tab[valeur2.x+1][valeur2.y-1]!=0) ||
		    (param.pion[valeur2.x+1][valeur2.y-1]!=0))&&
		    ((param.tab[valeur2.x+1][valeur2.y]!=0)   ||
		    (param.pion[valeur2.x+1][valeur2.y]!=0))  &&
		    ((param.tab[valeur2.x+1][valeur2.y+1]!=0) ||
		    (param.pion[valeur2.x+1][valeur2.y+1]!=0)))
		{
			FermerGraphique();
			gagnant(1,taille);
		}

		/*-----------------------------------------------------------------j1*/
		if (((param.tab[valeur1.x-1][valeur1.y-1]!=0) ||
			(param.pion[valeur1.x-1][valeur1.y-1]!=0))&&
		    ((param.tab[valeur1.x-1][valeur1.y]!=0) ||
		    (param.pion[valeur1.x-1][valeur1.y-1]!=0))&&
		    ((param.tab[valeur1.x-1][valeur1.y+1]!=0) ||
		    (param.pion[valeur1.x-1][valeur1.y+1]!=0))&&
		    ((param.tab[valeur1.x][valeur1.y-1]!=0)   ||
		    (param.pion[valeur1.x][valeur1.y-1]!=0))  &&
		    ((param.tab[valeur1.x][valeur1.y+1]!=0)   ||
		    (param.pion[valeur1.x][valeur1.y+1]!=0))  &&
		    ((param.tab[valeur1.x+1][valeur1.y-1]!=0) ||
		    (param.pion[valeur1.x+1][valeur1.y-1]!=0))&&
		    ((param.tab[valeur1.x+1][valeur1.y]!=0)   ||
		    (param.pion[valeur1.x+1][valeur1.y]!=0))  &&
		    ((param.tab[valeur1.x+1][valeur1.y+1]!=0) ||
		    (param.pion[valeur1.x+1][valeur1.y+1]!=0)))
		{
			FermerGraphique();
			gagnant(2,taille);
		}


		/*-----------------------------------------------------------------j1 bord tableau*/

		if (valeur1.x-1<0){	
			if (((param.tab[valeur1.x][valeur1.y-1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y-1]!=0))  &&       /*bord haut*/
			    ((param.tab[valeur1.x][valeur1.y+1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y+1]!=0))  &&
			    ((param.tab[valeur1.x+1][valeur1.y-1]!=0) ||
			    (param.pion[valeur1.x+1][valeur1.y-1]!=0))&&
			    ((param.tab[valeur1.x+1][valeur1.y]!=0)   ||
			    (param.pion[valeur1.x+1][valeur1.y]!=0))  &&
			    ((param.tab[valeur1.x+1][valeur1.y+1]!=0) ||
			    (param.pion[valeur1.x+1][valeur1.y+1]!=0)))
			{
				FermerGraphique();
				gagnant(2,taille);
			}
		}

		if (valeur1.y-1<0){
		
			if (((param.tab[valeur1.x-1][valeur1.y+1]!=0) ||
			    (param.pion[valeur1.x-1][valeur1.y+1]!=0))&&       /*bord gauche*/
			    ((param.tab[valeur1.x+1][valeur1.y+1]!=0) ||
			    (param.pion[valeur1.x+1][valeur1.y+1]!=0))&&
			    ((param.tab[valeur1.x+1][valeur1.y]!=0)   ||
			    (param.pion[valeur1.x+1][valeur1.y]!=0))  &&
			    ((param.tab[valeur1.x-1][valeur1.y]!=0)   ||
			    (param.pion[valeur1.x-1][valeur1.y-1]!=0))&&
			    ((param.tab[valeur1.x][valeur1.y+1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y+1]!=0)))
			{
				FermerGraphique();
				gagnant(2,taille);
			}
		}
		if (valeur1.x+1>=taille){
		
			if (((param.tab[valeur1.x-1][valeur1.y-1]!=0) ||
				(param.pion[valeur1.x-1][valeur1.y-1]!=0))&&       /*bord bas*/
			    ((param.tab[valeur1.x-1][valeur1.y]!=0)   ||
			    (param.pion[valeur1.x-1][valeur1.y-1]!=0))&&
			    ((param.tab[valeur1.x-1][valeur1.y+1]!=0) ||
			    (param.pion[valeur1.x-1][valeur1.y+1]!=0))&&
			    ((param.tab[valeur1.x][valeur1.y-1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y-1]!=0))  &&
			    ((param.tab[valeur1.x][valeur1.y+1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y+1]!=0)))
			{
				FermerGraphique();
				gagnant(2,taille);
			}
		}

		if (valeur1.y+1>=taille){
			
			if (((param.tab[valeur1.x+1][valeur1.y-1]!=0) ||
			    (param.pion[valeur1.x+1][valeur1.y-1]!=0))&&       /*bord droit*/
			    ((param.tab[valeur1.x-1][valeur1.y-1]!=0) ||
			    (param.pion[valeur1.x-1][valeur1.y-1]!=0))&&
			    ((param.tab[valeur1.x+1][valeur1.y]!=0)   ||
			    (param.pion[valeur1.x+1][valeur1.y]!=0))  &&
			    ((param.tab[valeur1.x-1][valeur1.y]!=0)   ||
			    (param.pion[valeur1.x-1][valeur1.y-1]!=0))&&
			    ((param.tab[valeur1.x][valeur1.y-1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y-1]!=0)))
			{
				FermerGraphique();
				gagnant(2,taille);
			}
		}
		/*-----------------------------------------------------------------j2 bord tableau*/
		if (valeur2.x-1<0){	

			if (((param.tab[valeur2.x][valeur2.y-1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y-1]!=0))  &&       /*bord haut*/
			    ((param.tab[valeur2.x][valeur2.y+1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y+1]!=0))  &&
			    ((param.tab[valeur2.x+1][valeur2.y-1]!=0) ||
			    (param.pion[valeur2.x+1][valeur2.y-1]!=0))&&
			    ((param.tab[valeur2.x+1][valeur2.y]!=0)   ||
			    (param.pion[valeur2.x+1][valeur2.y]!=0))  &&
			    ((param.tab[valeur2.x+1][valeur2.y+1]!=0) ||
			    (param.pion[valeur2.x+1][valeur2.y+1]!=0)))
			{
				FermerGraphique();
				gagnant(1,taille);
			}
		}
		
		if (valeur2.y-1<0){
			if (((param.tab[valeur2.x-1][valeur2.y+1]!=0) ||
			    (param.pion[valeur2.x-1][valeur2.y+1]!=0))&&       /*bord gauche*/
			    ((param.tab[valeur2.x+1][valeur2.y+1]!=0) ||
			    (param.pion[valeur2.x+1][valeur2.y+1]!=0))&&
			    ((param.tab[valeur2.x+1][valeur2.y]!=0)   ||
			    (param.pion[valeur2.x+1][valeur2.y]!=0))  &&
			    ((param.tab[valeur2.x-1][valeur2.y]!=0)   ||
			    (param.pion[valeur2.x-1][valeur2.y-1]!=0))&&
			    ((param.tab[valeur2.x][valeur2.y+1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y+1]!=0)))
			{
				FermerGraphique();
				gagnant(1,taille);
			}
		}

		if (valeur2.x+1>=taille){
			if (((param.tab[valeur2.x-1][valeur2.y-1]!=0) ||
				(param.pion[valeur2.x-1][valeur2.y-1]!=0))&&       /*bord bas*/
			    ((param.tab[valeur2.x-1][valeur2.y]!=0)   ||
			    (param.pion[valeur2.x-1][valeur2.y-1]!=0))&&
			    ((param.tab[valeur2.x-1][valeur2.y+1]!=0) ||
			    (param.pion[valeur2.x-1][valeur2.y+1]!=0))&&
			    ((param.tab[valeur2.x][valeur2.y-1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y-1]!=0))  &&
			    ((param.tab[valeur2.x][valeur2.y+1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y+1]!=0)))
			{
				FermerGraphique();
				gagnant(1,taille);
			}
		}

		if (valeur2.y+1>=taille){	
			if (((param.tab[valeur2.x+1][valeur2.y-1]!=0) ||
			    (param.pion[valeur2.x+1][valeur2.y-1]!=0))&&       /*bord droit*/
			    ((param.tab[valeur2.x-1][valeur2.y-1]!=0) ||
			    (param.pion[valeur2.x-1][valeur2.y-1]!=0))&&
			    ((param.tab[valeur2.x+1][valeur2.y]!=0)   ||
			    (param.pion[valeur2.x+1][valeur2.y]!=0))  &&
			    ((param.tab[valeur2.x-1][valeur2.y]!=0)   ||
			    (param.pion[valeur2.x-1][valeur2.y-1]!=0))&&
			    ((param.tab[valeur2.x][valeur2.y-1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y-1]!=0)))
			{
				FermerGraphique();
				gagnant(1,taille);
			}
		}

		/*-----------------------------------------------------------------j1 coin tableau*/
		
		if (valeur1.x-1<0 && valeur1.y-1<0){
			
			if(((param.tab[valeur1.x+1][valeur1.y]!=0)   ||
		    	(param.pion[valeur1.x+1][valeur1.y]!=0)) &&		/*coin haut gauche*/
			    ((param.tab[valeur1.x][valeur1.y+1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y+1]!=0))  &&
				((param.tab[valeur1.x+1][valeur1.y+1]!=0)   ||
				(param.pion[valeur1.x+1][valeur1.y+1]!=0)))
			{
			   	FermerGraphique();
				gagnant(2,taille);
			}
		}
		if (valeur1.x-1<0 && valeur1.y+1>=taille){
			if(((param.tab[valeur1.x][valeur1.y-1]!=0)   ||
		    	(param.pion[valeur1.x][valeur1.y-1]!=0)) &&		/*coin haut droit*/
			    ((param.tab[valeur1.x+1][valeur1.y]!=0)   ||
			    (param.pion[valeur1.x+1][valeur1.y]!=0))  &&
				((param.tab[valeur1.x-1][valeur1.y-1]!=0)   ||
				(param.pion[valeur1.x-1][valeur1.y-1]!=0)))
			{
				FermerGraphique();
				gagnant(2,taille);
			}
		}

		if (valeur1.x+1>=taille && valeur1.y-1<0){
			if (((param.tab[valeur1.x-1][valeur1.y]!=0)   ||
		    	(param.pion[valeur1.x-1][valeur1.y]!=0)) &&		/*coin bas droit*/
			    ((param.tab[valeur1.x][valeur1.y+1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y+1]!=0))  &&
				((param.tab[valeur1.x-1][valeur1.y+1]!=0)   ||
				(param.pion[valeur1.x-1][valeur1.y+1]!=0)))
			{
				
			}
		}

		if (valeur1.x+1>=taille && valeur1.y+1>=taille){
			if (((param.tab[valeur1.x-1][valeur1.y]!=0)   ||
		    	(param.pion[valeur1.x-1][valeur1.y]!=0)) &&		/*coin bas droit*/
			    ((param.tab[valeur1.x][valeur1.y-1]!=0)   ||
			    (param.pion[valeur1.x][valeur1.y-1]!=0))  &&
				((param.tab[valeur1.x-1][valeur1.y-1]!=0)   ||
				(param.pion[valeur1.x-1][valeur1.y-1]!=0)))
			{
				FermerGraphique();
				gagnant(2,taille);
			}
		}

		/*-----------------------------------------------------------------j2 coin tableau*/

		if (valeur2.x-1<0 && valeur2.y-1<0){
			
			if(((param.tab[valeur2.x+1][valeur2.y]!=0)   ||
		    	(param.pion[valeur2.x+1][valeur2.y]!=0)) &&		/*coin haut gauche*/
			    ((param.tab[valeur2.x][valeur2.y+1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y+1]!=0))  &&
				((param.tab[valeur2.x+1][valeur2.y+1]!=0)   ||
				(param.pion[valeur2.x+1][valeur2.y+1]!=0)))
			{
			   	FermerGraphique();
				gagnant(2,taille);
			}
		}
		if (valeur2.x-1<0 && valeur2.y+1>=taille){
			if(((param.tab[valeur2.x][valeur2.y-1]!=0)   ||
		    	(param.pion[valeur2.x][valeur2.y-1]!=0)) &&		/*coin haut droit*/
			    ((param.tab[valeur2.x+1][valeur2.y]!=0)   ||
			    (param.pion[valeur2.x+1][valeur2.y]!=0))  &&
				((param.tab[valeur2.x-1][valeur2.y-1]!=0)   ||
				(param.pion[valeur2.x-1][valeur2.y-1]!=0)))
			{
				FermerGraphique();
				gagnant(2,taille);
			}
		}

		if (valeur2.x+1>=taille && valeur2.y-1<0){
			if (((param.tab[valeur2.x-1][valeur2.y]!=0)   ||
		    	(param.pion[valeur2.x-1][valeur2.y]!=0)) &&		/*coin bas droit*/
			    ((param.tab[valeur2.x][valeur2.y+1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y+1]!=0))  &&
				((param.tab[valeur2.x-1][valeur2.y+1]!=0)   ||
				(param.pion[valeur2.x-1][valeur2.y+1]!=0)))
			{
				
			}
		}

		if (valeur2.x+1>=taille && valeur2.y+1>=taille){
			if (((param.tab[valeur2.x-1][valeur2.y]!=0)   ||
		    	(param.pion[valeur2.x-1][valeur2.y]!=0)) &&		/*coin bas droit*/
			    ((param.tab[valeur2.x][valeur2.y-1]!=0)   ||
			    (param.pion[valeur2.x][valeur2.y-1]!=0))  &&
				((param.tab[valeur2.x-1][valeur2.y-1]!=0)   ||
				(param.pion[valeur2.x-1][valeur2.y-1]!=0)))
			{
				FermerGraphique();
				gagnant(2,taille);
			}
		}
	}
}