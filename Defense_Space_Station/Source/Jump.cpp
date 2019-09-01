#include "../Header/Jump.h"
#include "../Header/Main.h"
#include "../Header/Size.h"

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

void JUMP_MOVE::JumpFlagTrue()
{

	this->JumpFlag = true;

}

void JUMP_MOVE::Jump(Vec *PlayerPos)
{
		
	if (this->JumpFlag == true) 
	{
		this->Initial_speed -= this->Speed;
		PlayerPos->y -= this->Initial_speed;
	}
	else if (this->JumpFlag == false) {
		this->Gravity(PlayerPos);
	}
	if (PlayerPos->y > 940)
	{
		if (dx.GetKeyState(DIK_W) != dx.ON) {
			this->JumpFlag = false;
		}
		PlayerPos->y = 940;
		this->Initial_speed = 25;

	}

}

void JUMP_MOVE::EnemyJump(Vec EnemyPos)
{

		this->Initial_speed -= this->Speed;
		EnemyPos.y -= this->Initial_speed;


}

void JUMP_MOVE::Gravity(Vec *Pos)
{

	Pos->y += 3;
	
}


float JUMP_MOVE::GetInitialSpeed()
{

	return this->Initial_speed;

}

void JUMP_MOVE::SetInitialSpeed(float Initial_speed)
{

	this->Initial_speed = Initial_speed;

}

JUMP_MOVE::JUMP_MOVE() :Initial_speed(25), Speed(0.5), JumpFlag(false)
{



}

JUMP_MOVE::~JUMP_MOVE()
{



}