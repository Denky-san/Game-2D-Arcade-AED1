#pragma once

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/*
	Classe empacotadora que age como a Game Engine
*/
class Game
{
private:
	//Vari�veis
	//Janela
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event eventPlayer;

	//Posicoes do Mouse

	sf::Vector2i mousePosWindow;

	//Game Objects

	sf::RectangleShape enemy;

	//Func�es Privadas.
	void initVariables();
	void initWindow();
	void initEnemies();
public:

	//Construtores e Destruidores 

	Game();
	virtual ~Game();

	//Acessores

	const bool running() const;

	//Fun�oes

	void pollEvents();
	void updateMousePositions();
	void update();
	void render();
};

