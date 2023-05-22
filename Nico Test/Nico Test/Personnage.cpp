#include "Personnage.h"
Personnage::Personnage(std::string texte)
{
	texture.loadFromFile(texte);
	sf::Sprite spriteT(texture, sf::IntRect(0, 0, 50, 88.75));
	sprite = spriteT;

	sf::IntRect pos1T(280, 88.75, 54.3, 88.5);
	sf::IntRect pos2T(334.3, 88.75, 70, 88.5);
	sf::IntRect pos3T(410, 88.75, 70, 88.5);
	sf::IntRect pos4T(490, 88.75, 54.3, 88.5);
	sf::IntRect pos5T(540, 88.75, 54.3, 88.5);
	sf::IntRect pos6T(600, 88.75, 60, 88.5);
	pos1 = pos1T;
	pos2 = pos2T;
	pos3 = pos3T;
	pos4 = pos4T;
	pos5 = pos5T;
	pos6 = pos6T;
	vitessey=0;
	vitessex=0;
	b = 0;
}
void Personnage::Posture(bool R, bool L, sf::Time dureeIteration)
{
	if (0.0 < b && b < 1.0)
	{
		sprite.setTextureRect(pos1);
	}
	else if (1.0 < b && b < 2.0)
	{
		sprite.setTextureRect(pos2);
	}
	else if (2.0 < b && b < 3.0)
	{
		sprite.setTextureRect(pos3);
	}
	else if (3.0 < b && b < 4.0)
	{
		sprite.setTextureRect(pos4);
	}
	else if (4.0 < b && b < 5.0)
	{
		sprite.setTextureRect(pos5);
	}
	else if (5.0 < b && b < 6.0)
	{
		sprite.setTextureRect(pos6);
	}
	if (R || L)
	{
		b += (5 * dureeIteration.asSeconds());
	}
	if (b >= 6)
	{
		b = 0;
	}

	
}
sf::Sprite Personnage::renvois_sprite()
{
	return sprite;
}
void Personnage::bouge(sf::Time DI)
{
	sprite.move(vitessex * DI.asSeconds(), vitessey * DI.asSeconds());
}
void Personnage::check(sf::Time dureeIteration)
{
	if (sprite.getPosition().y < 300)
	{
		vitessey += 300 * dureeIteration.asSeconds();
	}
	else if (vitessey > 0)
	{
		vitessey = 0;
	}

	if (vitessex > 0)
	{
		vitessex -= 50 * dureeIteration.asSeconds();
	}
	if (vitessex < 0)
	{
		vitessex += 50 * dureeIteration.asSeconds();
	}

}
void Personnage::changement_vitesse(bool U, bool D, bool R, bool L,sf::Time dureeIteration)
{
	if (D)
	{
		if (vitessey < 2000)
		{
			vitessey += 500 * dureeIteration.asSeconds();
		}
	}
	if (U)
	{
		if (vitessey > -2000)
		{
			vitessey -= 500 * dureeIteration.asSeconds();
		}
	}
	if (R)
	{
		if (vitessex < 2000)
		{
			vitessex += 500 * dureeIteration.asSeconds();
		}
	}
	if (L)
	{
		if (vitessex > -2000)
		{
			vitessex -= 500 * dureeIteration.asSeconds();
		}
	}
}