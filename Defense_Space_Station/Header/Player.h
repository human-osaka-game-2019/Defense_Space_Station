#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Header/Vector.h"
#include "../Header/Size.h"
#include "../Header/Enemy.h"
#include "../Header/Jump.h"
#include "../Header/Direction.h"

class PLAYER{
public:
	PLAYER();
	~PLAYER();

	void SetPos(float x, float y);
	Vec GetPos();
	void SetSize(float width, float height);
	Size GetSize();
	DIRECTION::Direction GetDirection();
	void Control(Enemy enemy[]);

private:

	Vec pos;
	Vec UnderPos;
	Size size;
	DIRECTION::Direction direction;
	JUMP_MOVE jump;
	float speed;

	//! Acceleration(加速度)
	float acc;

	void Attack(Enemy enemy[]);
	void Catch(Enemy enemy[]);
	void SpecialAttack(Enemy enemy[]);
};

#endif
