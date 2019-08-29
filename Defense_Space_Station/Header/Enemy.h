#ifndef ENEMY_H_
#define ENEMY_H_
#include"../Header/Vector.h"
#include"../Header/Jump.h"
#include"../Header/Direction.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	Vec GetPos();
	void SetPos(float pos_x, float pos_y);
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
	void SetJump(float InitSpeed, float SetSpeed);

private:

	Vec Pos;
	float MoveSpeed;
	int RePopCount;
	int Mode;
	bool DeadFlag;
	bool JumpFlag;
	JUMP_MOVE Jump_Move;
	Direction Direction;


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

