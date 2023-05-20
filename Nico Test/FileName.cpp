#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personnage.h"
#include <vector>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1780, 1080), "SFML works!");
	sf::Vector2f positionR(1780, 800);
	sf::RectangleShape shape2(positionR);
	std::vector<Personnage*> refresh;
	std::string image6 = "image6.png";
	refresh.push_back(new Personnage(image6));

	shape2.setFillColor(sf::Color::Green);
	shape2.move(0, 380);
	bool moveU = false;
	bool moveD = false;
	bool moveL = false;
	bool moveR = false;
	bool pressR = false;
	bool pasplus = false;
	int taille;
	window.setFramerateLimit(60);
	sf::Clock clock;
	sf::Time dureeIteration = sf::Time::Zero;
	sf::Texture texture;
	if (!texture.loadFromFile("image6.png", sf::IntRect(10, 10, 32, 32)))
	{
		// erreur...
	}
	texture.loadFromFile("image6.png");
	sf::Sprite sprite(texture, sf::IntRect(0,0,50,88.75));

	
	while (window.isOpen())
	{
		dureeIteration = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type)
			{ 
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::EventType::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					moveR = true;
					break;
				case sf::Keyboard::Left:
					moveL = true;
					break;
				case sf::Keyboard::Up:
					moveU = true;
					break;
				case sf::Keyboard::Down:
					moveD = true;
					break;
				case sf::Keyboard::R:
					pressR = true;
					break;
				}
				break;
			case sf::Event::EventType::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					moveR = false;
					break;
				case sf::Keyboard::Left:
					moveL = false;
					break;
				case sf::Keyboard::Up:
					moveU = false;
					break;
				case sf::Keyboard::Down:
					moveD = false;
					break;
				case sf::Keyboard::R:
					pressR = false;
					pasplus = false;
					break;

					}


			}
		}
		
		taille = refresh.size();
		
		for (int i = 0; i < taille; i++)
		{
			refresh[i]->changement_vitesse(moveU,moveD,moveR,moveL,dureeIteration);
			refresh[i]->check(dureeIteration);
			refresh[i]->Posture(moveR,moveL,dureeIteration);
			refresh[i]->bouge(dureeIteration);
		}
	 // Pour qu'il ne touche pas le sol et decelere
		// change la posture du perso si besoin

		if (!pasplus && pressR)
		{
			refresh.push_back(new Personnage(image6));
			pasplus = true;
		}

		//std::cout << b << std::endl; // pour que la texture change

		window.clear();
		window.draw(shape2);
		for (int i = 0; i < taille; i++)
		{
			window.draw(refresh[i]->renvois_sprite());
		}
		window.display();
	}
	return 0;
}
