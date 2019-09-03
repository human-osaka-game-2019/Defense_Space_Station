#include "../Header/Jump.h"
#include "../Header/Main.h"

float JUMP_MOVE::GetSpeed()
{
	return this->Speed;

}

void JUMP_MOVE::SetSpeed(float Speed)
{

	this->Speed = Speed;

}

/*



*/

void JUMP_MOVE::SetJumpFlag(bool flag)
{

	this->JumpFlag = flag;

}

void JUMP_MOVE::Jump(Vec *PlayerPos)
{
		
	if (this->JumpFlag) 
	{
		this->Initial_speed -= this->Speed;
		PlayerPos->y -= this->Initial_speed;
	}
	else {
		Gravity(PlayerPos);
	}
	if (!JumpFlag) {
		Initial_speed = 25.0f;
	}

}

void JUMP_MOVE::EnemyJumpSet(float SetInitSpeed, float SetSpeed)
{

	this->Initial_speed = SetInitSpeed;
	this->Speed = SetSpeed;

}

void JUMP_MOVE::EnemyJump(Vec *EnemyPos)
{

		this->Initial_speed -= this->Speed;
		EnemyPos->y -= this->Initial_speed;


}

void JUMP_MOVE::Gravity(Vec *Pos)
{

	Pos->y += gravity;
	
}


float JUMP_MOVE::GetInitialSpeed()
{

	return this->Initial_speed;

}

void JUMP_MOVE::SetInitialSpeed(float Initial_speed)
{

	this->Initial_speed = Initial_speed;

}

JUMP_MOVE::JUMP_MOVE() :Initial_speed(25), Speed(0.5), gravity(10.0f), JumpFlag(false)
{



}

JUMP_MOVE::~JUMP_MOVE()
{



}