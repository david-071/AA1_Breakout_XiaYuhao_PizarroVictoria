#pragma once
#include "GameObject.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "PlayerStats.h"
#include <vector>

class Ball : public GameObject {
protected:
	Vector2 direction;
	std::vector<GameObject*> objects;
	PlayerStats* stats;					//Hacemos otro puntero de stats
	Vector2 CalculateCollision( GameObject* other);
public:
	Ball(Vector2 _pos, ConsoleColor c, std::vector<GameObject*> _objects, PlayerStats* _stats)	//Le ponemos lo mismo que en lo de objetos solo que no es un vector
		: GameObject(_pos, '@', c), objects(_objects), stats(_stats), direction(Vector2(1, 1)) {}	//Le ponemos lo mismo que lo de los objetos
	void Update() override;
};