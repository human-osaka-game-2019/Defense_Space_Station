#include "../Header/Jump.h"
#include "../Header/Main.h"



Vec JUMP_MOVE::GetPos()
{
	return this->Pos;

}

void JUMP_MOVE::SetPos(Vec Pos)
{

	this->Pos = Pos;

}

float JUMP_MOVE::GetSpeed()
{
	return this->Speed;

}

void JUMP_MOVE::SetSpeed(float Speed)
{

	this->Speed = Speed;

}
/*

第一引数
	Pos_Yは現在のY座標
第二引数
	Initial_speedは初速
第三引数
	Speedは加速度

*/
void JUMP_MOVE::Jump()
{
	
	if (dx.GetKeyState(DIK_W) == dx.PUSH)
	{
		this->JumpFlag = true;
		
	}
	if (this->JumpFlag == true) 
	{
		this->Initial_speed -= this->Speed;
		this->Pos.y -= this->Initial_speed;
	}
	if (this->Pos.y >= DISPLAY_HEIGHT)
	{

		this->JumpFlag = false;
		 this->Pos.y -= this->Pos.y - DISPLAY_HEIGHT;
		 this->SetSpeed(50);
		 this->Initial_speed = this->GetSpeed();
	}

}

void JUMP_MOVE::EnemyJump()
{

		this->Initial_speed -= this->Speed;
		this->Pos.y -= this->Initial_speed;


}


float JUMP_MOVE::GetInitialSpeed()
{

	return this->Initial_speed;

}

void JUMP_MOVE::SetInitialSpeed(float Initial_speed)
{

	this->Initial_speed = Initial_speed;

}

JUMP_MOVE::JUMP_MOVE() :Initial_speed(50),Pos(0,0), Speed(0.5), JumpFlag(false)
{



}

JUMP_MOVE::~JUMP_MOVE()
{



}