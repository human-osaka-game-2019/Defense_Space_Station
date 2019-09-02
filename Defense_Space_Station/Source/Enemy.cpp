#include "../Header/Enemy.h"
#include "../Header/Jump.h"
#include "../Header/Main.h"

using DIRECTION::RIGHT;
using DIRECTION::LEFT;

JUMP_MOVE Jump_Move;

Vec Enemy::GetPos()
{

	return this->Pos;

}

void Enemy::SetPos(float x, float y)
{

	this->Pos.x = x;
	this->Pos.y = y;

}

Size Enemy::GetSize() {
	return this->size;
}

void Enemy::SetSize(float width, float height) {
	this->size.width = width;
	this->size.height = height;
}

float Enemy::GetRadius() {
	return this->radius;
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
	
	switch (direction)
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
	this->Jump_Move.SetSpeed(0.05f);
	if (PlayerPos.x >= this->Pos.x) 
	{
		direction = RIGHT;
	}else
	 if (PlayerPos.x <= this->Pos.x)
	{
		 direction = LEFT;
	}
	
	if (PlayerPos.y < this->Pos.y && ((PlayerPos.x  )> (this->Pos.x -200)) && (PlayerPos.x < (this->Pos.x + 200)))
	{
		this->JumpFlag = true;
	}
	 
		if (this->JumpFlag == true) {
			this->Jump_Move.EnemyJump(&this->Pos);
			if (this->Pos.y > 939)
			{
				this->JumpFlag = false;
				this->Pos.y = 939;
				this->Jump_Move.SetInitialSpeed(8.0f);
			}
		}
	

}
void Enemy::SetJump(float InitSpeed, float SetSpeed)
{

	this->Jump_Move.EnemyJumpSet(InitSpeed, SetSpeed);

}

Enemy::Enemy():is_dead(false), Pos(0.0f,0.0f), size(100, 50), radius((size.width / 2 + size.height / 2) / 2), RePopCount(600), Mode(ALIVE), direction(RIGHT), JumpFlag(false)
{
	
}


Enemy::~Enemy()
{

}


