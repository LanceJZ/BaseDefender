#include "J�ger.h"

void J�ger::Update(sf::Time *delta)
{
	Enemy::Update(delta);
	EnemyRandomShooter::UpdateShots(delta);

	if (m_Active)
	{
		EnemyTargetedMover::Update(delta);

		if (EnemyTargetedMover::DoesMovementChange())
		{
			EnemyTargetedMover::ChaseTarget(Enemy::pPlayer->GetPosition());
		}

		EnemyRandomShooter::Update(delta, EnemyTargetedMover::GetPosition());
	}
}

void J�ger::Draw(sf::RenderWindow *window)
{
	Enemy::Draw(window);
	EnemyRandomShooter::Draw(window);
}

void J�ger::DrawOtherSide(sf::RenderWindow *window)
{
	Enemy::DrawOtherSide(window);
	EnemyRandomShooter::DrawOtherSide(window);
}

void J�ger::Initialize(sf::Texture *texture, sf::Texture *radarTexture, sf::Texture *shotTexture, sf::Texture *shipExplosion,
	sf::Vector2u windowSize, sf::Vector2f worldSize)
{
	EnemyTargetedMover::Initialize(texture, windowSize, worldSize);
	EnemyRandomShooter::Initialize(shotTexture, sf::Vector2i(texture->getSize().x / 2, texture->getSize().y / 2), windowSize, worldSize);
	Enemy::Initialize(shipExplosion);
	Enemy::mRadar->setTexture(*radarTexture);
}

void J�ger::PlayerPointer(std::shared_ptr<Player> playerSP)
{
	EnemyRandomShooter::PlayerPointer(playerSP);
	Enemy::pPlayer = playerSP;
}

void J�ger::Setup(sf::Vector2f position, sf::Vector2f velocity)
{
	Enemy::m_Active = true;
	EnemyTargetedMover::Setup(position, velocity);
	EnemyRandomShooter::SetActive(true);
}

void J�ger::SetActive(bool active)
{
	EnemyTargetedMover::SetActive(active);
	EnemyRandomShooter::SetActive(active);
}

bool J�ger::GetActive(void)
{
	return EnemyTargetedMover::GetActive();
}

J�ger::J�ger(void)
{
}

