﻿#ifndef ENEMY_H_
#define ENEMY_H_
#include "../Header/Vector.h"
#include "../Header/Size.h"

#define EnemyMax 20

class Enemy
{
public:
	Enemy();
	~Enemy();

	bool is_dead;

	Vec GetPos();
	void SetPos(float x, float y);
	Size GetSize();
	void SetSize(float width, float height);
	float GetRadius();
	float GetMoveSpeed();
	void SetMoveSpeed(float MoveSpeed);
	int GetRePopCount();
	void SetRePopCount(int RePopCount);
	int GetMode();
	void SetMode(int Mode);
	int GetDirection();
	void SetDirection(int Direction);
	bool GetJumpFlag();
	void SetJumpFlag(bool JumpFlag);
	void EnemyMove(Vec PlayerPos);
	void EnemyAliveMove();
	void EnemySwoonMove();
	void EnemyDeadMove();
	void Chase(Vec PlayerPos);

private:

	Vec Pos;
	Size size;
	const float radius;
	float MoveSpeed;
	int RePopCount;
	int Mode;
	int Direction;
	bool JumpFlag;

};



enum MODE 
{
	ALIVE,
	SWOON,
	DEAD

};

enum DIRECTION
{

	RIGHT,
	LEFT

};

#endif // ENEMY_H_

