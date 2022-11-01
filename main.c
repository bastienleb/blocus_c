#include<graph.h>
#include<stdio.h>
#include <stdlib.h>

#include "graphique.h"
#include "jeux.h"
#include "fin.h"
 
#define tx 700
#define ty 600

/*----------------------------------------------------------------------------*/
int main(void)
{ 
	int taille=0; 
	int joueur=0;  
	couleur fond=CouleurParComposante(17,122,101);
  
	page_menu(taille,joueur,fond);
} 