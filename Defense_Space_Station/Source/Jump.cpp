#include "../Header/Jump.h"

int JUMP_MOVE::GetPos_Y()
{
	return this->Pos_Y;

}

void JUMP_MOVE::SetPos_Y(float Pos_Y)
{

	this->Pos_Y = Pos_Y;

}

int JUMP_MOVE::GetSpeed()
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
void JUMP_MOVE::Jump(float* Pos_Y, float* Initial_speed, float Speed)
{

	*Initial_speed -= Speed;
	*Pos_Y -= *Initial_speed;

}

int JUMP_MOVE::GetInitialSpeed()
{

	return this->Initial_speed;

}

void JUMP_MOVE::SetInitialSpeed(float Initial_speed)
{

	this->Initial_speed = Initial_speed;

}

JUMP_MOVE::JUMP_MOVE() :Initial_speed(50),Pos_Y(0), Speed(0.5)
{



}

JUMP_MOVE::~JUMP_MOVE()
{



}