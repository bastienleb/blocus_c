#include<graph.h>
#include<stdio.h>
#include <stdlib.h>

 
#define tx 700
#define ty 600

void gagnant(int tour,int taille){ /*Cette fonction affiche le gagnant*/
printf("dans la fonction gagnat \n");
	int end=0;
	InitialiserGraphique();
	CreerFenetre(500,250,tx,ty); 

	SourisPosition();
	EffacerEcran(CouleurParComposante(17,122,101));
	printf("tour = %d\n",tour );
			
	if(tour==1){
		EcrireTexte(50,50,"Le gagnant est le joueur noir",2);
		printf("noir gagnant\n");
	}

	if (tour==2){
		EcrireTexte(50,50,"Le gagnant est le joueur blanc",2);
		printf("blanc gagnant\n");
	}

	DessinerRectangle(125,475,130,53); /*Zone Quitter */
	EcrireTexte(135,513,"Quitter !",2);

	DessinerRectangle(475,475,145,53); /*Zone Rejouer */
	EcrireTexte(485,513,"Rejouer !",2);
	while(end==0)

	while(SourisCliquee()){
		int tmp=SourisCliquee();

		if((_X>=125 && _X<=255)&&(_Y>=475 && _Y<=528)){ /*Quitter*/

			end=1;
			FermerGraphique();
			return EXIT_SUCCESS;
		
		}
		if((_X>=475 && _X<=620)&&(_Y>=475 && _Y<=528)){ /*Rejouer*/


			end=1;
			taille=0; 
			int joueur=0;  
			couleur fond=CouleurParComposante(17,122,101);
			FermerGraphique();
			page_menu(taille,joueur,fond);
		}
	}
}