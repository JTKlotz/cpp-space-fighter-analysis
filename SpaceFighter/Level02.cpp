

#include "Level02.h"
#include "BioEnemyShip.h"


void Level02::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");

	const int COUNT = 22;

	/*double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55, .6
	};*/

	double yPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.85, 0.8, 0.85,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.8, 0.85, 0.75, 0.85, 0.7,
		0.5, 0.4, 0.6, 0.45, 0.55, .6
	};

	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		//position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

		// change the starting position of the enemy ships so that they appear from the left side of the screen
		position.Set(-pTexture->GetCenter().X,yPositions[i] * Game::GetScreenHeight());

		BioEnemyShip* pEnemy = new BioEnemyShip();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);
	}

	// Setup background
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground04.jpg"));

	Level::LoadContent(resourceManager);
}

