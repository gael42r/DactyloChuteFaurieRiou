#include "Menu.h"

int main()
{
	//Création du menu
	Menu menu;
	//Chargement des scores
	menu.load();
	//Ecran titre
	menu.title();

	//Boucle du menu
	for (;;)
	{	
		//Affichage du menu
		menu.display();

		//Choix de navigation
		int choice = 0;
		while (choice < 1 || choice > 4)
		{
			choice = menu.enterChoice();
		}

		switch (choice)
		{
		case 1: //Jouer
			menu.play();
			break;
		case 2: //Changer la difficulté
			menu.setUp();
			break;
		case 3: //Tableau des scores
			menu.goToScoreboard();
			break;
		case 4: //Quitter
			menu.save();
			return 0;
			break;
		default:
			break;
			return 0;
		}
		system("CLS");
	}
	system("PAUSE");
	return 0;
}
