#include "Game.h"

// Principal
int main()
{
	//Janela

	RenderWindow window(VideoMode(800, 600), "Projeto AED1", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);

	Clock deltaClock;

	//Assets

	//Nave
	Texture ship_tex;
	ship_tex.loadFromFile("Assets/Spaceship.png");

	Sprite nave(ship_tex);

	nave.setPosition(Vector2f(384.f, 284.f));
	nave.setScale(1.5f, 1.5f);

	//Asteroide
	Texture ast_tex;
	ast_tex.loadFromFile("Assets/Asteroid.png");

	Sprite asteroide(ast_tex);
	asteroide.setScale(2.6f, 2.6f);


	srand(time(0));
	asteroide.setOrigin(24.f, 24.f);
	asteroide.setPosition(((rand() % 640) + 1), -(rand() % 600));

	//Background
	Texture bg_tex;
	bg_tex.loadFromFile("Assets/Background.png");

	Sprite bg(bg_tex);



	while (window.isOpen())
	{
		Event event;

		Time dt = deltaClock.restart();

		float Ast_Velocity = 50.f * dt.asSeconds();
		float Ship_Velocity = 150.f * dt.asSeconds();

		
		// Movimentação do Asteroide

		asteroide.move(0.f, Ast_Velocity);

		asteroide.rotate(1.f);

		//Movimentos

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			nave.move(-Ship_Velocity, 0.f);
		}

		if (Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			nave.move(Ship_Velocity, 0.f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			nave.move(0.f, -Ship_Velocity);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			nave.move(0.f, Ship_Velocity);
		}


		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

			
		//Limpar a janela
		window.clear(Color::Black);

		//Desenhar
		window.draw(bg);
		window.draw(nave);
		window.draw(asteroide);

		//Terminar o Frame
		window.display();

	}

	//Fim do aplicativo
	return 0;
}