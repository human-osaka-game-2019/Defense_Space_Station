#ifndef ENEMY_H_
#define ENEMY_H_
#include"..//Header/Vector.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	Vec GetPos();
	void SetPos(Vec Pos);
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
	float MoveSpeed;
	int RePopCount;
	int Mode;
	bool DeadFlag;
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

