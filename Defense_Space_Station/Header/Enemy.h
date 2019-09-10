#ifndef ENEMY_H_
#define ENEMY_H_
#include"../Header/Vector.h"
#include "../Header/Size.h"
#include"../Header/Jump.h"
#include"../Header/Direction.h"

#define EnemyMax 3

class Enemy
{
public:
	Enemy();
	~Enemy();

	enum MODE
	{
		ALIVE,
		SWOON,
		DEAD

	};

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
	MODE GetMode();
	void SetMode(MODE Mode);
	bool GetJumpFlag();
	void SetJumpFlag(bool JumpFlag);
	void EnemyMove(Vec PlayerPos, Size PlayerSize);
	void EnemyAliveMove(Vec PlayerPos);
	void EnemySwoonMove(Vec PlayerPos);
	void EnemyDeadMove();
	void Chase(Vec PlayerPos, Size PlayerSize);
	void Escape(Vec PlayerPos);
	void SetJump(float InitSpeed, float SetSpeed);
	bool Is_Stop;
	bool PlayerSearch(Vec PlayerPos, DIRECTION::Direction direc);
	Vec DeadPos;
	bool ReviveRange();

private:

	void Collision();

	Vec Pos;
	Size size;
	const float radius;
	float MoveSpeed;
	int RePopCount;
	MODE Mode;
	bool JumpFlag;
	JUMP_MOVE Jump_Move;
	DIRECTION::Direction direction;
	int DirectionTime;
	int RandomMove;
	float SearchLeft;
	float SearchRight;
	float SearchTop;
	float SearchBottom;
	float SearchHeight;
	float SearchWidth;
	int ReviveCount;
	int RandomJump;
	Vec PrevPos;
};

#endif // ENEMY_H_

