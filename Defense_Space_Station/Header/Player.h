#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Header/Vector.h"
#include "../Header/Size.h"
#include "../Header/Jump.h"

class HAMMER {
public:
	HAMMER(float x, float y);
	~HAMMER();

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

	bool is_Reverse;

	void SetPos(float x, float y);
	Vec GetPos();
	void SetSize(float width, float height);
	Size GetSize();
	void Control();

private:
	Vec pos;
	Size size;
	JUMP_MOVE jump;
	HAMMER hammer;
	const float speed;

	void Attack();
	void Catch();
	void SpecialAttack();
};

#endif
