#include "../Header/Player.h"
#include "../Header/Collision.h"

using DIRECTION::RIGHT;
using DIRECTION::LEFT;

void PLAYER::SetPos(float x, float y) {
	this->pos.x = x;
	this->pos.y = y;
}

Vec PLAYER::GetPos() {
	return pos;
}

void PLAYER::SetSize(float width, float height) {
	this->size.width = width;
	this->size.height = height;
}

Size PLAYER::GetSize() {
	return size;
}

void PLAYER::SetHp(int hp) {
	this->hp = hp;
}

int PLAYER::GetHp() {
	return this->hp;
}

void PLAYER::SetCatchCount(int catchcount) {
	this->catchcount = catchcount;
}

int PLAYER::GetCatchCount() {
	return this->catchcount;
}

DIRECTION::Direction PLAYER::GetDirection() {
	return direction;
}

void PLAYER::Control(Enemy enemy[]) {
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		direction = RIGHT;
		speed = 7.5f;
		is_move = true;
	}
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		direction = LEFT;
		speed = -7.5f;
		is_move = true;
	}
	if (dx.GetKeyState(DIK_D) == dx.OFF && speed >= 0.0f) {
		speed -= acc;
		if (speed <= 0.0f
			|| Collision::SquareCollision(pos, size, Collision::GroundPos, Collision::GroundSize)
			|| Collision::SquareCollision(pos, size, Collision::RightAirBlockPos, Collision::DrawAirBlockSize)
			|| Collision::SquareCollision(pos, size, Collision::LeftAirBlockPos, Collision::DrawAirBlockSize)) {
			speed = 0.0f;
		}
		is_move = false;
	}
	if (dx.GetKeyState(DIK_A) == dx.OFF && speed <= 0.0f) {
		speed += acc;
		if (speed >= 0.0f 
			|| Collision::SquareCollision(pos, size, Collision::GroundPos, Collision::GroundSize)
			|| Collision::SquareCollision(pos, size, Collision::RightAirBlockPos, Collision::DrawAirBlockSize)
			|| Collision::SquareCollision(pos, size, Collision::LeftAirBlockPos, Collision::DrawAirBlockSize)) {
			speed = 0.0f;
		}
		is_move = false;
	}
	if (dx.GetKeyState(JUMP) == dx.PUSH || dx.GetKeyState(JUMP) == dx.ON) {
		this->jump.SetJumpFlag(true);

	}
	if (dx.GetKeyState(DIK_J) == dx.PUSH) {
		Attack(enemy);
		item = LAST_ITEM::HAMMER;
		is_attack = true;
	}
	if (dx.GetKeyState(DIK_K) == dx.PUSH) {
		Catch(enemy);
		item = LAST_ITEM::NET;
		soundsManager.Start("CatchSE", false);
		is_attack = true;
	}
	if (dx.GetKeyState(DIK_L) == dx.PUSH) {
		SpecialAttack(enemy);
	}
#ifdef _DEBUG
	if (dx.GetKeyState(DIK_RETURN) == dx.PUSH) {
		for (int i = 0; i < EnemyMax; i++) {
			enemy[i].SetMode(Enemy::MODE::ALIVE);
		}
	}
	if (dx.GetKeyState(DIK_S) == dx.ON) {
		pos.y += 10.0f;
	}
#endif
	Collision(enemy);
	pos.x += speed;
	this->jump.Jump(&this->pos);
}

void PLAYER::Attack(Enemy enemy[]) {
	for (int i = 0; i < EnemyMax; i++) {
		Vec EnemyCenter = { enemy[i].GetPos().x + enemy[i].GetSize().width, enemy[i].GetPos().y + enemy[i].GetSize().height / 2 };
		Vec UnderPos = {pos.x + size.width / 2, pos.y + size.height};

		if (enemy[i].GetMode() == Enemy::MODE::ALIVE) {
			if (direction == RIGHT) {
				if (Collision::CircleCollision(UnderPos, size.height, EnemyCenter, enemy[i].GetRadius()) 
					&& UnderPos.x <= EnemyCenter.x 
					&& UnderPos.y >= EnemyCenter.y) {
					soundsManager.Start("PlayerAttackSE", false);
					enemy[i].SetMode(Enemy::MODE::SWOON);
					enemy[i].DeadPos = enemy[i].GetPos();
				}
			}
			if (direction == LEFT) {
				if (Collision::CircleCollision(UnderPos, size.height / 2, EnemyCenter, enemy[i].GetRadius()) 
					&& UnderPos.x >= EnemyCenter.x 
					&& UnderPos.y >= EnemyCenter.y) {
					soundsManager.Start("PlayerAttackSE", false);
					enemy[i].SetMode(Enemy::MODE::SWOON);
					enemy[i].DeadPos = enemy[i].GetPos();
				}
			}
		}
		
	}
}

void PLAYER::Catch(Enemy enemy[]) {
	for (int i = 0; i < EnemyMax; i++) {
		Vec EnemyCenter = { enemy[i].GetPos().x + enemy[i].GetSize().width / 2, enemy[i].GetPos().y + enemy[i].GetSize().height / 2 };
		Vec UnderPos = { pos.x + size.width / 2, pos.y + size.height };

		if (enemy[i].GetMode() == Enemy::MODE::SWOON) {
			if (direction == RIGHT) {
				if (Collision::CircleCollision(UnderPos, size.height / 2, EnemyCenter, enemy[i].GetRadius())
					&& UnderPos.x <= EnemyCenter.x
					&& UnderPos.y >= EnemyCenter.y) {
					enemy[i].SetMode(Enemy::MODE::DEAD);
					catchcount++;
					if (0 < remainingenemycount) {remainingenemycount--;}
				}
			}
			if (direction == LEFT) {
				if (Collision::CircleCollision(UnderPos, size.height / 2, EnemyCenter, enemy[i].GetRadius())
					&& UnderPos.x >= EnemyCenter.x
					&& UnderPos.y >= EnemyCenter.y) {
					enemy[i].SetMode(Enemy::MODE::DEAD);
					catchcount++;
				}
			}
		}
	}
}

void PLAYER::SpecialAttack(Enemy enemy[]) {
	if(catchcount>=6){
		for (int i = 0; i < EnemyMax; i++) {
			enemy[i].SetMode(Enemy::MODE::SWOON);
			catchcount = 0;
		}
	}
}

void PLAYER::Collision(Enemy enemy[]) {
	//LeftAirBlock
	collision_pos = { pos.x + 150.0f, pos.y + 375.0f};
	collision_size = { 200.0f,25.0f };
	if (Collision::AirBlockCollision(collision_pos, collision_size, Collision::JudgeLeftAirBlockPos, Collision::JudgeAirBlockSize, PrevPos)) {
		if (dx.GetKeyState(JUMP) != dx.PUSH) {
			jump.SetJumpFlag(false);
		}
		else {
			jump.SetInitialSpeed(25.0f);
		}
		pos.y = Collision::LeftAirBlockPos.y - size.height;
	}
	//RightAirBlock
	else if (Collision::AirBlockCollision(collision_pos, collision_size, Collision::JudgeRightAirBlockPos, Collision::JudgeAirBlockSize, PrevPos)) {
		if (dx.GetKeyState(JUMP) != dx.PUSH) {
			jump.SetJumpFlag(false);
			jump.SetInitialSpeed(25.0f);
		}
		pos.y = Collision::RightAirBlockPos.y - size.height;
	}
	else {
		PrevPos = pos;
	}

	//壁
	if (pos.x <= -75.0f) {
		pos.x = -75.0f;
	}
	else if (pos.x + size.width >= DISPLAY_WIDTH + 75.0f) {
		pos.x = DISPLAY_WIDTH + 75.0f - size.width;
	}

	//床
	if (pos.y + size.height >= DISPLAY_HEIGHT - Collision::GroundSize.height) {
		pos.y = DISPLAY_HEIGHT - Collision::GroundSize.height - size.height;
		if (dx.GetKeyState(JUMP) == dx.OFF || dx.GetKeyState(JUMP) == dx.RELEASE) {
			jump.SetJumpFlag(false);
		}
	}

	collision_pos = {pos.x + 150.0f, pos.y};
	collision_size = { 200.0f,400.0f };
	//敵
	if (!is_god) {
		for (int i = 0; i < EnemyMax; i++) {
			if (Collision::SquareCollision(collision_pos, collision_size, enemy[i].GetPos(), enemy[i].GetSize()) && enemy[i].GetMode() == enemy->MODE::ALIVE) {
				hp -= 1;
				if (collision_count <= 120) {
					collision_count = 0;
					is_god = true;
				}
			}
		}
	}
	if (collision_count >= 120) {
		is_god = false;
		collision_count = 0;
	}
	collision_count++;
}

PLAYER::PLAYER():item(HAMMER), is_attack(false), is_catch(false), is_move(false), pos(100.0f,100.0f),direction(RIGHT),speed(0.0f),hp(12), collision_count(0), is_god(false), PrevPos(pos), acc(0.20f), is_damege(false),catchcount(0),remainingenemycount(10){
	SetSize(500.0f, 400.0f);
}

PLAYER::~PLAYER() {

}
