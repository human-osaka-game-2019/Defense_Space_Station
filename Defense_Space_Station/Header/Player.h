#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Header/Vector.h"
#include "../Header/Size.h"

class Hammer {
public:
	Hammer(float x, float y);
	~Hammer();

	void SetPos(float x, float y);
	Vec GetPos();
	void SetSize(float width, float height);
	Size GetSize();
	void SetDegree();
	float GetDegree();

private:
	Vec pos;
	Size size;
	float degree;
};

class PLAYER{
public:
	PLAYER();
	~PLAYER();

	void SetPos(float x, float y);
	Vec GetPos();
	void SetSize(float width, float height);
	Size GetSize();
	void Control();

private:
	Vec pos;
	Size size;
	//JUMP_MOVE jump;
	Hammer hammer;
	const float speed;

	void Attack();
	void Catch();
	void SpecialAttack();
};

#endif
