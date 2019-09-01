#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Header/Vector.h"
#include "../Header/Size.h"
#include "../Header/Enemy.h"
#include "../Header/Jump.h"

class PLAYER{
public:
	PLAYER();
	~PLAYER();

	void SetPos(float x, float y);
	Vec GetPos();
	void SetSize(float width, float height);
	Size GetSize();
	DIRECTION GetDirection();
	void Control(Enemy enemy[]);

private:

	Vec pos;
	Vec UnderPos;
	Size size;
	DIRECTION direction;
	JUMP_MOVE jump;
	const float speed;

	void Attack(Enemy enemy[]);
	void Catch();
	void SpecialAttack();
};

#endif
