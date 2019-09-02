#ifndef ENEMY_H_
#define ENEMY_H_
#include"../Header/Vector.h"
#include "../Header/Size.h"
#include"../Header/Jump.h"
#include"../Header/Direction.h"

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
	DIRECTION::Direction GetDirection();
	float GetRadius();
	float GetMoveSpeed();
	void SetMoveSpeed(float MoveSpeed);
	int GetRePopCount();
	void SetRePopCount(int RePopCount);
	int GetMode();
	void SetMode(int Mode);
	bool GetJumpFlag();
	void SetJumpFlag(bool JumpFlag);
	void EnemyMove(Vec PlayerPos);
	void EnemyAliveMove();
	void EnemySwoonMove();
	void EnemyDeadMove();
	void Chase(Vec PlayerPos);
	void SetJump(float InitSpeed, float SetSpeed);

private:

	Vec Pos;
	Size size;
	const float radius;
	float MoveSpeed;
	int RePopCount;
	int Mode;
	bool JumpFlag;
	JUMP_MOVE Jump_Move;
	DIRECTION::Direction direction;
};



enum MODE 
{
	ALIVE,
	SWOON,
	DEAD

};

#endif // ENEMY_H_

