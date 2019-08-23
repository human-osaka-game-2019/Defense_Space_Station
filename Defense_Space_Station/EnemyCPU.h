#ifndef ENEMYCPU
#define ENEMYCPU

class Enemy
{
public:
	Enemy();
	~Enemy();

	float GetPos_X();
	void SetPos_X(float Pos_X);
	float GetPos_Y();
	void SetPos_Y(float Pos_Y);
	float GetMoveSpeed();
	void SetMoveSpeed(float MoveSpeed);
	int GetRePopCount();
	void SetRePopCount(int RePopCount);
	int GetMode();
	void SetMode(int Mode);
	bool GetDeadFlag();
	void SetDeadFlag(bool DeadFlag);
	void SetDeadFlagTrue();
	void ReSetDeadFlag();
	int GetDirection();
	void SetDirection(int Direction);
	bool GetJumpFlag();
	void SetJumpFlag(bool JumpFlag);
	void SetJumpFlagTrue();
	void ReSetJumpFlag();
	void EnemyMove();
	void EnemyAliveMove();
	void EnemySwoonMove();
	void EnemyDeadMove();

private:

	float Pos_X;
	float Pos_Y;
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

#endif // !1

