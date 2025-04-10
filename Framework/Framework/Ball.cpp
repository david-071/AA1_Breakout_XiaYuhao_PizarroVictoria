#include "Ball.h"
#include "Brick.h"

Vector2 Ball::CalculateCollision( GameObject* other)
{
	int vertical = 0;
	int horizontal = 0;

	for ( int i=0;i < objects.size();i++) {
		//Check verticals
		bool top = (other->GetPosition() + Vector2(0, -1)) == objects[i]->GetPosition();
		bool bottom = (other->GetPosition() + Vector2(0, 1)) == objects[i]->GetPosition();
		vertical += (int)top + (int)bottom;

		//Check horizontals
		bool left = (other->GetPosition() + Vector2(-1, 0)) == objects[i]->GetPosition();
		bool right = (other->GetPosition() + Vector2(1, 0)) == objects[i]->GetPosition();
		horizontal += (int)left + (int)right;
	}

	Vector2 outDir = direction;

	//isolated
	if (vertical == 0 && horizontal == 0) {
		vertical = rand() % 2 > 0;
		horizontal = rand() % 2 > 0;
	}

	if (vertical >= horizontal)
		outDir.x = -outDir.x;
	if (horizontal > vertical)
		outDir.y = -outDir.y;

	return outDir;
}

void Ball::Update()
{
	//1 -> Moviment
	position = position + direction;
	//2 -> Col·lisió
		//Parets
		//Bricks
		//Pad
	for (GameObject* go : objects) {
		if (go == this) {
			continue;
		}
		bool collision = position == go->GetPosition();
		if (collision) {
			//Check if this is a wall
			if (Wall* w = dynamic_cast<Wall*>(go)) {
				//Si toca la pared de abajo va a la posicion 7 en y la pelota
				if (w->GetIsBottom()) {
					position.y = 6.25;
				}
				else {
					direction = CalculateCollision(go);
				}
			}
			else if (Pad* w = dynamic_cast<Pad*>(go)) {
				direction = CalculateCollision(go);
				direction.y = -1;
			}
			else if (Brick* w = dynamic_cast<Brick*>(go)) {
				//Si el brick no esta destruido, se destruye y se cambia su dirección, si está destruido es como no hubiera nada
				if (!w->GetDestroyed()) {
					direction = CalculateCollision(go);
					w->Destroy();
				}
			}
		}

	}
}
