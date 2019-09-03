#include "../Header/Enemy.h"
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

DIRECTION::Direction Enemy::GetDirection() {
	return direction;
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

Enemy::MODE Enemy::GetMode()
{

	return this->Mode;

}

void Enemy::SetMode(MODE Mode)
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


//謨?�縺?�迥?�諷?
void Enemy::EnemyMove(Vec PlayerPos)
{

	switch (this->GetMode())
	{
	case MODE::ALIVE:
		this->Chase(PlayerPos);
		this->EnemyAliveMove(PlayerPos);
		break;
	case MODE::SWOON:
		this->Escape(PlayerPos);
		this->EnemySwoonMove(PlayerPos);
		break;
	case MODE::DEAD:
		this->EnemyDeadMove();
		break;
    }
}

//謨?�縺?�陦悟虚
void Enemy::EnemyAliveMove(Vec PlayerPos)
{
	if (!((PlayerPos.x) > (this->Pos.x - 50)) || !(PlayerPos.x < (this->Pos.x + 50)))
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

}

//繧?�繝ｭ繝懊す縺?�AI縺�??譚･縺溘ｉ霑?�險?
void Enemy::EnemySwoonMove(Vec PlayerPos)
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

void Enemy::EnemyDeadMove()
{
	



}

void Enemy::Chase(Vec PlayerPos)
{

	if (PlayerPos.x > this->Pos.x) 
	{
		direction = RIGHT;
	}else if (PlayerPos.x <= this->Pos.x)
	{
		 direction = LEFT;
	}
	
	if (PlayerPos.y < this->Pos.y && ((PlayerPos.x  )> (this->Pos.x - 200)) && (PlayerPos.x < (this->Pos.x + 200)))
	{
		this->JumpFlag = true;
	}
	 
		if (this->JumpFlag == true) {
			this->Jump_Move.EnemyJump(&this->Pos);
			if (this->Pos.y > 940)
			{
				this->JumpFlag = false;
				this->Pos.y = 940;
				this->Jump_Move.SetInitialSpeed(8.0f);
			}
		}
	

}

void Enemy::Escape(Vec PlayerPos)
{


	if (PlayerPos.x < this->Pos.x)
	{
		this->direction = RIGHT;
	}
	else
		if (PlayerPos.x >= this->Pos.x)
		{
			this->direction = LEFT;
		}

	
		this->JumpFlag = true;
	

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

Enemy::Enemy():Pos(0.0f,0.0f), size(100, 100), radius((size.width / 2 + size.height / 2) / 2), MoveSpeed(5.0f), RePopCount(600), Mode(ALIVE), direction(RIGHT), JumpFlag(false)
{
	
}


Enemy::~Enemy()
{

}


