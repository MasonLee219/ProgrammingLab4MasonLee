#include "Tank.h"


Tank::Tank(sf::Texture const & texture, sf::Vector2f const & pos)
: m_texture(texture)
{
	initSprites(pos);
}

void Tank::update(double dt)
{
	

	double x = m_tankBase.getPosition().x + std::cos(MathUtility::DEG_TO_RAD * m_rotation) * m_speed * (dt / 1000);
	
	double y = m_tankBase.getPosition().y + std::sin(MathUtility::DEG_TO_RAD * m_rotation) * m_speed * (dt / 1000);
	
	m_tankBase.setRotation(m_rotation);
	m_turret.setRotation(m_rotation);
	m_tankBase.setPosition(x, y);
	m_turret.setPosition(m_tankBase.getPosition());

	//if (m_speed >= 1)
	//{
		m_speed *= 0.99;
	//}

	m_speed = std::clamp(m_speed, -20.0, 50.0);
}

void Tank::render(sf::RenderWindow & window) 
{
	window.draw(m_tankBase);
	window.draw(m_turret);
}


void Tank::initSprites(sf::Vector2f const & pos)
{
	// Initialise the tank base
	m_tankBase.setTexture(m_texture);
	sf::IntRect baseRect(2, 43, 79, 43);
	m_tankBase.setTextureRect(baseRect);
	m_tankBase.setOrigin(baseRect.width / 2.0, baseRect.height / 2.0);
	m_tankBase.setPosition(pos);

	// Initialise the turret
	m_turret.setTexture(m_texture);
	sf::IntRect turretRect(19, 1, 83, 31);
	m_turret.setTextureRect(turretRect);
	m_turret.setOrigin(turretRect.width / 3.0, turretRect.height / 2.0);
	m_turret.setPosition(pos);

}

////////////////////////////////////////////////////////////
void Tank::increaseSpeed()
{
	if (m_speed < 100.0)
	{
		m_speed +=1 ;
		
	}
}

////////////////////////////////////////////////////////////
void Tank::decreaseSpeed()
{
	if (m_speed > -100.0)
	{
		m_speed -= 1;
		
	}
}

////////////////////////////////////////////////////////////
void Tank::increaseRotation()
{
	m_rotation += 1;
	if (m_rotation == 360.0)
	{
		m_rotation = 0;
	}
}

////////////////////////////////////////////////////////////
void Tank::decreaseRotation()
{
	m_rotation -= 1;
	if (m_rotation == 0.0)
	{
		m_rotation = 359.0;
	}
}

void Tank::setPosition(sf::Vector2f t_pos)
{
	m_tankBase.setPosition(t_pos);
}