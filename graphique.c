#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "jeux.h"
#include "fin.h"
#include "graphique.h" 

#define tx 700
#define ty 600


void page_menu(int taille,int joueur,couleur fond){
	InitialiserGraphique(); 
	CreerFenetre(500,250,tx,ty);
	afficher_menu(taille,joueur,fond);
}

void afficher_menu(int taille,int joueur,couleur fond){ /* afficher le menu*/
	int fin=0;

	EffacerEcran(fond); 
	SourisPosition();
	

	while(!fin){
		EcrireTexte(200,50,"Selectionner une taille :",2);
		
		DessinerRectangle(225,100,50,53); /*Zone 3*/
		EcrireTexte(235,138,"3",2);

		DessinerRectangle(325,100,50,53); /*Zone 4*/
		EcrireTexte(335,138,"4",2);

		DessinerRectangle(425,100,50,53); /*Zone 5*/
		EcrireTexte(435,138,"5",2);

		DessinerRectangle(225,200,50,53); /*Zone 6*/
		EcrireTexte(235,238,"6",2);

		DessinerRectangle(325,200,50,53); /*Zone 7*/
		EcrireTexte(335,238,"7",2);

		DessinerRectangle(425,200,50,53); /*Zone 8*/
		EcrireTexte(435,238,"8",2);

		DessinerRectangle(325,300,50,53); /*Zone 9*/
		EcrireTexte(335,338,"9",2);

		DessinerRectangle(200,375,130,53); /* Zone J1*/
		EcrireTexte(210,413,"1 joueur",2);

		DessinerRectangle(375,375,142,53); /* Zone J2*/
		EcrireTexte(385,413,"2 joueurs",2);

		DessinerRectangle(125,475,115,53); /*Zone Jouer */
		EcrireTexte(135,513,"Jouer !",2);
		
		DessinerRectangle(475,475,130,53); /*Zone Fermer*/
		EcrireTexte(485,513,"Fermer !",2);

		while(SourisCliquee())
		{

			if((_X>=225 && _X<=275)&&(_Y>=100 && _Y<=153)){ /*3*/
				taille=3;
				printf(" Taille = %d\n", taille);
				EffacerEcran(fond);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(225,100,50,53);
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(235,138,"3",2);

		
			}
			if((_X>=325 && _X<=375)&&(_Y>=100 && _Y<=153)){ /*4*/
				taille=4;
				printf(" Taille = %d\n", taille);
				EffacerEcran(fond);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(325,100,50,53);
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(335,138,"4",2);
				
			}
			if((_X>=425 && _X<=475)&&(_Y>=100 && _Y<=153)){ /*5*/
				taille=5;
				printf(" Taille = %d\n", taille);
				EffacerEcran(fond);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(425,100,50,53); 
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(435,138,"5",2);
			}
			if((_X>=225 && _X<=275)&&(_Y>=200 && _Y<=253)){ /*6*/
				taille=6;
				printf(" Taille = %d\n", taille);
				EffacerEcran(fond);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(225,200,50,53);
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(235,238,"6",2);
				
			}

			if((_X>=325 && _X<=375)&&(_Y>=200 && _Y<=253)){ /*7*/
				taille=7;
				printf(" Taille = %d\n", taille);
				EffacerEcran(fond);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(325,200,50,53);
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(335,238,"7",2);
				
			}
			if((_X>=425 && _X<=475)&&(_Y>=200 && _Y<=253)){ /*8*/
				taille=8;
				printf(" Taille = %d\n", taille);
				EffacerEcran(fond);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(425,200,50,53);
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(435,238,"8",2);

			}
			if((_X>=325 && _X<=375)&&(_Y>=300 && _Y<=353)){ /*9*/
				taille=9;
				printf(" Taille = %d\n", taille);
				EffacerEcran(fond);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(325,300,50,53); 
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(335,338,"9",2);
				
			}

			if((_X>=200 && _X<=342)&&(_Y>=375 && _Y<=413)){ /*J1*/
				joueur=1;
				printf(" joueur = %d\n", joueur);
				
			}

			if((_X>=375 && _X<=510)&&(_Y>=375 && _Y<=413)){ /*J2*/
				joueur=2;
				printf(" joueur = %d\n", joueur);
				
				
			}

			if (joueur==1){
				
				ChoisirCouleurDessin(fond);
				RemplirRectangle(375,375,142,53);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(200,375,130,53);
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(210,413,"1 joueur",2);
			}

			if (joueur==2){
				ChoisirCouleurDessin(fond);
				RemplirRectangle(200,375,130,53);
				ChoisirCouleurDessin(CouleurParNom("green"));
				RemplirRectangle(375,375,142,53);
				ChoisirCouleurDessin(CouleurParNom("black"));
				EcrireTexte(385,413,"2 joueurs",2);
			}

			if((_X>=475 && _X<=610)&&(_Y>=475 && _Y<=513)){ /*quitter*/
				fin = 2;
				FermerGraphique();
				return EXIT_SUCCESS;
			}

			if((_X>=125 && _X<=240)&&(_Y>=475 && _Y<=513)){ /*Jouer*/
				if(taille==0 || joueur==0){
					fond=CouleurParComposante(200,47,47);
					FermerGraphique();
					afficher_menu(taille,joueur,fond);
				}
				fin = 1;
				FermerGraphique();
				jeux(joueur,taille);
				
			}
		}
	}
}
