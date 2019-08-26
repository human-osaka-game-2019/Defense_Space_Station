#include "EnemyCPU.h"


float Enemy::GetPos_X()
{

	return this->Pos_X;

}

void Enemy::SetPos_X(float Pos_X)
{

	this->Pos_X = Pos_X;

}

float Enemy::GetPos_Y()
{

	return this->Pos_Y;

}

void Enemy::SetPos_Y(float Pos_Y)
{

	this->Pos_Y = Pos_Y;

}

float Enemy::GetMoveSpeed()
{

	return this->MoveSpeed;

}

void Enemy::SetMoveSpeed(float MoveSpeed)
{

	this->MoveSpeed = MoveSpeed;

}

int Enemy::GetRePopCount()
{

	return this->RePopCount;

}

void Enemy::SetRePopCount(int RePopCount)
{
	this->RePopCount = RePopCount;
}

int Enemy::GetMode()
{

	return this->Mode;

}

void Enemy::SetMode(int Mode)
{

	this->Mode = Mode;

}

bool Enemy::GetDeadFlag()
{

	return this->DeadFlag;

}

void Enemy::SetDeadFlag(bool DeadFlag)
{

	this->DeadFlag = DeadFlag;

}

void Enemy::SetDeadFlagTrue()
{

	this->DeadFlag = true;

}

int Enemy::GetDirection()
{

	return this->Direction;

}

void Enemy::SetDirection(int Direction)
{

	this->Direction = Direction;

}

bool Enemy::GetJumpFlag()
{

	return this->JumpFlag;

}

void Enemy::SetJumpFlag(bool JumpFlag)
{

	this->JumpFlag = JumpFlag;

}

void Enemy::SetJumpFlagTrue()
{

	this->JumpFlag = true;

}

void Enemy::ReSetDeadFlag()
{

	this->DeadFlag = false;

}

void Enemy::ReSetJumpFlag()
{

	this->JumpFlag = false;

}
//敵の状態
void Enemy::EnemyMove()
{

	switch (this->GetMode())
	{
	case MODE::ALIVE:
		this->EnemyAliveMove();
		break;
	case MODE::SWOON:
		this->EnemySwoonMove();
		break;
	case MODE::DEAD:
		this->EnemyDeadMove();
		break;
    }
}

//敵の行動
void Enemy::EnemyAliveMove()
{

	switch (this->Direction)
	{
	case DIRECTION::RIGHT:

		this->Pos_X += this->MoveSpeed;

		break;
	case DIRECTION::LEFT:

		this->Pos_X -= this->MoveSpeed;

		break;

	}

}

//クロボシのAIが出来たら追記
void Enemy::EnemySwoonMove()
{



}

void Enemy::EnemyDeadMove()
{
	this->SetDeadFlagTrue;



}

Enemy::Enemy() :Pos_X(), Pos_Y(), RePopCount(600), Mode(ALIVE), DeadFlag(false), Direction(RIGHT), JumpFlag(false)
{



}


Enemy::~Enemy()
{



}


