#include "Schwärme.h"

void Schwärme::Update(sf::Time *delta)
{
	Enemy::Update(delta);
	EnemyRandomShooter::UpdateShots(delta);

	if (Entity::m_Active)
	{
		if (EnemyTargetedMover::DoesMovementChange())
		{
			EnemyTargetedMover::ChaseTarget(Enemy::pPlayer->GetPosition());
		}

		EnemyTargetedMover::Update(delta);
		EnemyRandomShooter::Update(delta, EnemyTargetedMover::GetPosition());
	}
}

void Schwärme::Draw(sf::RenderWindow *window)
{
	Enemy::Draw(window);
	EnemyRandomShooter::Draw(window);
}

void Schwärme::DrawOtherSide(sf::RenderWindow *window)
{
	Enemy::DrawOtherSide(window);
	EnemyRandomShooter::DrawOtherSide(window);
}

void Schwärme::Initialize(sf::Texture *texture, sf::Texture *radarTexture, sf::Texture *shotTexture, sf::Texture *shipExplosion,
	sf::Vector2u windowSize, sf::Vector2f worldSize)
{
	EnemyTargetedMover::Initialize(texture, windowSize, worldSize);
	EnemyRandomShooter::Initialize(shotTexture, sf::Vector2i(texture->getSize().x / 2, texture->getSize().y / 2), windowSize, worldSize);
	Enemy::Initialize(shipExplosion);
	Enemy::mRadar->setTexture(*radarTexture);
}

void Schwärme::Setup(sf::Vector2f position, sf::Vector2f velocity)
{
	EnemyTargetedMover::Setup(position, velocity);
	m_Acceleration = sf::Vector2f(0,0);
	SetActive(true);
}

void Schwärme::PlayerPointer(std::shared_ptr<Player> playerSP)
{
	EnemyRandomShooter::PlayerPointer(playerSP);
	Enemy::pPlayer = playerSP;
}

void Schwärme::SetActive(bool active)
{
	EnemyTargetedMover::SetActive(active);
	EnemyRandomShooter::SetActive(active);
	Entity::m_Active = active;
}

Schwärme::Schwärme(void)
{
}
