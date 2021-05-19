#include "Menu.h"


int main()
{
	


	Menu menu;
	menu.editScoreboard(new Score("Gael", menu.getSettings().getStrDifficulty(), 250));
	menu.editScoreboard(new Score("Antoine", menu.getSettings().getStrDifficulty(), 120));


	menu.title();

	for (;;)
	{
		
		
		menu.display();

		int choice = 0;
		while (choice < 1 || choice > 4)
		{
			choice = menu.enterChoice();
		}

		switch (choice)
		{
		case 1: //Play
			menu.play();
			break;
		case 2: //Settings
			menu.setUp();
			break;
		case 3: //Scoreboard
			menu.goToScoreboard();
			break;
		case 4: //Exit
			return 0;
			break;
		default:
			break;
			return 0;
		}
		system("CLS");
	}


	//Score score1("Gael", 1, 1, 1, 1);
	//Score score2("Antoine", 2, 1, 3, 1);
	//scoreboard.addScore(score1);
	//scoreboard.addScore(score2);
	//scoreboard.display();
	////menu.editScoreboard(scoreboard);

	system("PAUSE");
	return 0;
}
