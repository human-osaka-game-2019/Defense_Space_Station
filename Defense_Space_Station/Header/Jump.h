#ifndef JUMP
#define JUMP
#include "../Header/Vector.h"

class JUMP_MOVE
{
public:

	JUMP_MOVE();
	~JUMP_MOVE();

	Vec GetPos();
	void SetPos(Vec Pos);
	float GetSpeed();
	void SetSpeed(float Speed);
	float GetInitialSpeed();
	void SetInitialSpeed(float Initial_speed);
	void Jump();
	void EnemyJump();

private:

	Vec Pos;
	float Speed;
	float Initial_speed;
	bool JumpFlag;
};





#endif //JUMP
