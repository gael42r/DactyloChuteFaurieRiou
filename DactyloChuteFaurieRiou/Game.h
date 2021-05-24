#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>

#include "Score.h"
#include "Settings.h"
#include "Dictionary.h"

class Game
{
	//Param�tres de la partie
	Settings settings_;
	//Score de la partie
	Score score_;
	//Dictionaire de mot de la partie
	Dictionary dictionary_;

	//Gestion du temps
	sf::Clock clock_;
	sf::Time frequency_;
	sf::Clock timer_;
	sf::Clock madeByTimer_;
	sf::Clock dactyloChuteTimer_;
	sf::Clock preGameTimer_;

	//Gestion des images
	sf::Texture madeByTexture_;
	sf::Sprite madeBy_;
	sf::Texture dactyloChuteTexture_;
	sf::Sprite dactyloChute_;

	//Gestion de la musique
	sf::Music music_;

	//Gestion saisie du pseudo
	string nameEntered_;
	bool isEnterPressed_;


	//M�thode priv�es
	void restartClock();
	sf::Time getClockTime();
	sf::Time chooseFrequency(int);
	sf::Time remainingTime();

public:
	Game(Settings);

	Score getScore() const { return score_; }

	//Affichage
	//Afficher "Made by"
	void drawMadeBy(sf::RenderWindow&);
	//Afficher "Dactylo-Chute"
	void drawDactyloChute(sf::RenderWindow&);

	//Afficher le chronom�tre
	void drawTimer(sf::RenderWindow&);
	//Afficher le score
	void drawScore(sf::RenderWindow&);
	//Afficher la difficult�
	void drawSettings(sf::RenderWindow&);

	//Afficher les mots
	void drawDictionary(sf::RenderWindow&);

	//Afficher le score de fin
	void drawEndScore(sf::RenderWindow&);
	//Afficher le pseudo et sa saisie
	void drawName(sf::RenderWindow&);
	//Afficher "Press enter"
	void drawPressEnter(sf::RenderWindow&);
	
	//Gestion du temps
	//Initialiser le compteur
	void restartMadeByTimer();
	//V�rifier si "Made By" est termin�
	bool isMadeByTimeIsUp();
	//Initialiser le compteur
	void restartDactyloChuteTimer();
	//V�rifier si "Dactylo-Chute" est termin�
	bool isDactyloChuteTimeIsUp();
	//Initialiser le compteur
	void restartPreGameTimer();
	//V�rifier si le "Pre Game" est termin�
	bool isPreGameTimeIsUp();
	//Initialiser le compteur
	void restartTimer();
	//V�rifier si la partie est termin�e
	bool isTimeIsUp();

	//Ev�nements
	//Ev�nement de saisie des mots
	void eventTextEntered(sf::RenderWindow&, sf::Event&);
	//Ev�nement de fermeture
	void eventClose(sf::RenderWindow&, sf::Event&);
	//Ev�nement de saisie du pseudo
	void eventTextName(sf::Event&);
	//Ev�nement "Press enter"
	void eventEnter(sf::Event&, sf::RenderWindow&);

	//Incr�menter le score
	void upScore();
	//Supprimer les mots hors jeu
	void deleteOutWords();
	//Jouer la musique
	void playMusic();
	//Gestion validation
	bool isEnterAlreadyPressed();
};
