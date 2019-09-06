#include "../Header/Enemy.h"
#include "../Header/Jump.h"
#include "../Header/Main.h"
#include "../Header/Collision.h"
#include <time.h>

using DIRECTION::RIGHT;
using DIRECTION::LEFT;

#define ReviveTime 300
#define RePopTime 180

#define LeftPopPos_x 2200
#define RightPopPos_x -300
#define PopPos_y 780

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



void Enemy::EnemyMove(Vec PlayerPos, Size PlayerSize)
{

	switch (this->GetMode())
	{
	case MODE::ALIVE:
		this->Chase(PlayerPos, PlayerSize);
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


void Enemy::EnemyAliveMove(Vec PlayerPos)
{
	size = { 200, 300 };
	Collision();
	if (Is_Stop == false)
	{

		if(PlayerSearch(PlayerPos, direction))
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
		else
		{
			if (Is_Stop == false) {
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
	}

	
	
}


void Enemy::EnemySwoonMove(Vec PlayerPos)
{
	ReviveCount++;
	size = { 100, 100 };
	switch (direction)
	{
	case DIRECTION::RIGHT:

		this->Pos.x += this->MoveSpeed;

		break;
	case DIRECTION::LEFT:

		this->Pos.x -= this->MoveSpeed;

		break;

	}

	

	if (ReviveCount >= ReviveTime && ReviveRange() == true)
	{
		Mode = MODE::ALIVE;
	}
	
}

void Enemy::EnemyDeadMove()
{
	RePopCount++;

	if (RePopCount >= RePopTime)
	{
		if (rand() % 10 < 5) {
			Pos.x = RightPopPos_x;
		}
		else
		{
			Pos.x = LeftPopPos_x;
		}
			Pos.y = PopPos_y;
			Mode = MODE::ALIVE;

	}


	

}

void Enemy::Chase(Vec PlayerPos, Size PlayerSize)
{
	if(PlayerSearch(PlayerPos, direction) == true)
	{
		if (PlayerPos.x > this->Pos.x)
		{
			direction = RIGHT;
		}
		else if (PlayerPos.x <= this->Pos.x)
		{
			direction = LEFT;
		}
		
	}
	else
	{
		if (!Collision::SquareCollision(Pos, size, PlayerPos, PlayerSize)) {
			DirectionTime++;
			if (DirectionTime == 160)
			{
				RandomMove = rand() % 10;
				if (this->RandomMove < 4)
				{
					direction = LEFT;
					DirectionTime = NULL;
				}
				else
				{
					direction = RIGHT;
					DirectionTime = NULL;
				}


				
			}

				if (Collision::RightAirBlockPos.x < Pos.x && (Collision::RightAirBlockPos.x + Collision::DrawAirBlockSize.width) > Pos.x && Pos.y > Collision::LeftAirBlockPos.y)
				{
					RandomJump = rand() % 100;
					if (RandomJump < 30)
					{
						JumpFlag = true;

					}

				}

				if (Pos.x > Collision::LeftAirBlockPos.x && Pos.x < (Collision::LeftAirBlockPos.x + Collision::DrawAirBlockSize.width) && Pos.y > Collision::LeftAirBlockPos.y)
				{
					RandomJump = rand() % 100;
					if (RandomJump < 30)
					{
						JumpFlag = true;
						
					}
				}
		}



	}

	if (Collision::SquareCollision(Pos, size, PlayerPos, PlayerSize) == true)
	{
		Is_Stop = true;
	}
	else 
	{
		Is_Stop = false;
	}




	 
	if (this->JumpFlag == true) 
	{
		this->Jump_Move.EnemyJump(&this->Pos);
		
	}
	else
	{
		Jump_Move.Gravity(&this->Pos);
	}


	if (Pos.x <= 0.0f) {
		direction = RIGHT;
		DirectionTime = 0;
	}
	else if (Pos.x + size.width >= DISPLAY_WIDTH) {
		direction = LEFT;
		DirectionTime = 0;
	}

	if(Collision::AirBlockCollision(Pos, size, Collision::JudgeRightAirBlockPos, Collision::JudgeAirBlockSize, PrevPos))
	{
		this->JumpFlag = false;
		this->Pos.y = Collision::RightAirBlockPos.y - size.height;
		this->Jump_Move.SetInitialSpeed(10.0f);
	}
	else if (Collision::AirBlockCollision(Pos, size, Collision::JudgeLeftAirBlockPos, Collision::JudgeAirBlockSize, PrevPos))
	{
		this->JumpFlag = false;
		this->Pos.y = Collision::RightAirBlockPos.y - size.height;
		this->Jump_Move.SetInitialSpeed(10.0f);
	}
	else 
	{
		PrevPos = Pos;
	}
	if (this->Pos.y > PopPos_y)
	{
		this->JumpFlag = false;
		this->Pos.y = PopPos_y;
		this->Jump_Move.SetInitialSpeed(10.0f);
	}

}

void Enemy::Escape(Vec PlayerPos)
{


	if (PlayerSearch(PlayerPos, direction) == true)
	{
		if (this->direction == LEFT)
		{
		this->direction = RIGHT;
		}
		else
		{
			this->direction = LEFT;
		}
	}
	

	
		this->JumpFlag = true;
	

	if (this->JumpFlag == true) {
		this->Jump_Move.EnemyJump(&this->Pos);
		if (this->Pos.y > DISPLAY_HEIGHT - Collision::GroundSize.height - size.height)
		{
			this->JumpFlag = false;
			this->Pos.y = DISPLAY_HEIGHT - Collision::GroundSize.height - size.height;
			this->Jump_Move.SetInitialSpeed(10.0);
		}
	}

	if (Collision::AirBlockCollision(Pos, size, Collision::JudgeRightAirBlockPos, Collision::JudgeAirBlockSize, PrevPos))
	{
		this->JumpFlag = false;
		this->Pos.y = Collision::RightAirBlockPos.y - size.height;
		this->Jump_Move.SetInitialSpeed(7.5f);
	}
	else if (Collision::AirBlockCollision(Pos, size, Collision::JudgeLeftAirBlockPos, Collision::JudgeAirBlockSize, PrevPos))
	{
		this->JumpFlag = false;
		this->Pos.y = Collision::RightAirBlockPos.y - size.height;
		this->Jump_Move.SetInitialSpeed(7.5f);
	}
	else
	{
		PrevPos = Pos;
	}

	if (Pos.x <= 0.0f)
	{
		
		direction = RIGHT;

	}
	else if (Pos.x > DISPLAY_WIDTH - size.width)
	{

		direction = LEFT;
		
	}


}

void Enemy::SetJump(float InitSpeed, float SetSpeed)
{

	this->Jump_Move.EnemyJumpSet(InitSpeed, SetSpeed);

}


bool Enemy::PlayerSearch(Vec PlayerPos ,DIRECTION::Direction direction)
{

	if (direction == RIGHT)
	{

		SearchLeft = Pos.x;
		SearchRight = Pos.x + (size.width + SearchWidth);
		SearchTop = (Pos.y - SearchHeight);
		SearchBottom = (Pos.y + size.height);
		if (SearchLeft <= PlayerPos.x && PlayerPos.x < SearchRight && SearchTop <=PlayerPos.y && PlayerPos.y <= SearchBottom) 
		{
			return true;
		}
	}
	else
	{

		SearchLeft = (Pos.x - SearchWidth);
		SearchRight = (Pos.x + size.width);
		SearchTop = (Pos.y - SearchHeight);
		SearchBottom = (Pos.y + size.height);
		if (SearchLeft <= PlayerPos.x && SearchRight > PlayerPos.x && SearchTop <=PlayerPos.y && SearchBottom > PlayerPos.y)
		{
			return true;
		}
	}

	
	return false;
	


}

bool Enemy::ReviveRange()
{
	if (DeadPos.x <= Pos.x && DeadPos.x + size.width >= Pos.x && Pos.y >= DeadPos.y && Pos.y <= DeadPos.y + size.height)
	{
		return true;
	}
	return false;
}

void Enemy::Collision() {
	if (Pos.y + size.height >= DISPLAY_HEIGHT - Collision::GroundSize.height) {
		Pos.y = DISPLAY_HEIGHT - Collision::GroundSize.height - size.height;
	}
}

Enemy::Enemy() :Is_Stop(false), Pos(0.0f, 0.0f), size(200, 300), radius(size.width / 2), MoveSpeed(5.0f), RePopCount(600), Mode(ALIVE), direction(RIGHT), JumpFlag(false), DirectionTime(0), RandomMove(0), SearchLeft(300), SearchRight(300),SearchTop(300),SearchBottom(300),SearchHeight(100),SearchWidth(300)
{
	srand((unsigned int)time(NULL));
}


Enemy::~Enemy()
{

}





