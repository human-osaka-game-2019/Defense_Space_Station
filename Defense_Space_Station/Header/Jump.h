#ifndef JUMP
#define JUMP
#include "../Header/Vector.h"
#include "../Header/Size.h"

class JUMP_MOVE
{
public:

	JUMP_MOVE();
	~JUMP_MOVE();


	float GetSpeed();
	void SetSpeed(float Speed);
	float GetInitialSpeed();
	void SetInitialSpeed(float Initial_speed);
	void JumpFlagTrue();
	void Jump(Vec* PlayerPos);
	void EnemyJump(Vec EnemyPos);
	void Gravity(Vec* Pos);

private:

	Vec Pos;
	float Speed;
	float Initial_speed;
	bool JumpFlag;
};





#endif //JUMP
