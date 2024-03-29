﻿#ifndef _JUMP
#define _JUMP
#include "../Header/Vector.h"
#include "../Header/Size.h"

class JUMP_MOVE
{
public:

	JUMP_MOVE();
	~JUMP_MOVE();


	float GetSpeed();
	void SetSpeed(float Speed);
	bool GetJumpFlag();
	float GetInitialSpeed();
	void SetInitialSpeed(float Initial_speed);
	void SetJumpFlag(bool flag);
	void Jump(Vec* PlayerPos);
	void EnemyJumpSet(float InitSpeed, float SetSpeed);
	void EnemyJump(Vec* EnemyPos);
	void Gravity(Vec* Pos);

private:

	Vec Pos;
	float Speed;
	const float gravity;
	float Initial_speed;
	bool JumpFlag;
};





#endif //JUMP
