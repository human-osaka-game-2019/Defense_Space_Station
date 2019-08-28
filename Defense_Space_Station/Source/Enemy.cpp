#include "../Header/Enemy.h"
#include "../Header/Jump.h"
#include "../Header/Main.h"

JUMP_MOVE Jump_Move;

Vec Enemy::GetPos()
{

	return this->Pos;

}

void Enemy::SetPos(Vec Pos)
{

	this->Pos = Pos;

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


//謨ｵ縺ｮ迥ｶ諷?
void Enemy::EnemyMove(Vec PlayerPos)
{

	switch (this->GetMode())
	{
	case MODE::ALIVE:
		this->Chase(PlayerPos);
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

//謨ｵ縺ｮ陦悟虚
void Enemy::EnemyAliveMove()
{
	
	switch (this->Direction)
	{
	case DIRECTION::RIGHT:

		this->Pos.x += this->MoveSpeed;

		break;
	case DIRECTION::LEFT:

		this->Pos.x -= this->MoveSpeed;

		break;

	}

}

//繧ｯ繝ｭ繝懊す縺ｮAI縺悟?譚･縺溘ｉ霑ｽ險?
void Enemy::EnemySwoonMove()
{



}

void Enemy::EnemyDeadMove()
{
	



}

void Enemy::Chase(Vec PlayerPos)
{

	if (PlayerPos.x >= this->Pos.x) 
	{
		this->Direction = DIRECTION::RIGHT;
	}
	else if (PlayerPos.x <= this->Pos.x)
	{

		this->Direction = DIRECTION::LEFT;

	}

	if (PlayerPos.y <= this->Pos.y)
	{
		this->JumpFlag = true;
		Jump_Move.SetPos(this->Pos);
		if (this->JumpFlag == true) {
			Jump_Move.EnemyJump();
			if (this->Pos.y >= DISPLAY_HEIGHT)
			{

				this->Pos.y -= this->Pos.y - DISPLAY_HEIGHT;

			}
		}
	}

}

Enemy::Enemy() :Pos(0.0f,0.0f), RePopCount(600), Mode(ALIVE), DeadFlag(false), Direction(RIGHT), JumpFlag(false)
{



}


Enemy::~Enemy()
{



}


