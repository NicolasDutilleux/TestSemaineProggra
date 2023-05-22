#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Personnage
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect pos1;
	sf::IntRect pos2;
	sf::IntRect pos3;
	sf::IntRect pos4;
	sf::IntRect pos5;
	sf::IntRect pos6;
	float vitessey;
	float vitessex;
	float b;
public : 
	Personnage(std::string texte);
	void Posture(bool R, bool L, sf::Time dureeIteration);
	void bouge(sf::Time DI);
	sf::Sprite renvois_sprite();
	void check(sf::Time dureeIteration);
	void changement_vitesse(bool U, bool D, bool R, bool L, sf::Time dureeIteration);
};

