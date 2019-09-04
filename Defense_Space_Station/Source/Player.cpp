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

DIRECTION::Direction PLAYER::GetDirection() {
	return direction;
}

void PLAYER::Control(Enemy enemy[]) {
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		direction = RIGHT;
		speed = 5.0f;
	}
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		direction = LEFT;
		speed = -5.0f;
	}
	if (dx.GetKeyState(DIK_D) == dx.OFF && speed >= 0.0f) {
		speed -= acc;
		if (speed <= 0.0f || Collision::SquareCollision(pos, size, Collision::GroundPos, Collision::GroundSize)) {
			speed = 0.0f;
		}
	}
	if (dx.GetKeyState(DIK_A) == dx.OFF && speed <= 0.0f) {
		speed += acc;
		if (speed >= 0.0f || Collision::SquareCollision(pos, size, Collision::GroundPos, Collision::GroundSize)) {
			speed = 0.0f;
		}
	}
	if (dx.GetKeyState(JUMP) == dx.PUSH || dx.GetKeyState(JUMP) == dx.ON) {
		this->jump.SetJumpFlag(true);
	}
	if (dx.GetKeyState(DIK_J) == dx.PUSH) {
		Attack(enemy);
		soundsManager.Start("PlayerAttackSE", false);
	}
	if (dx.GetKeyState(DIK_K) == dx.PUSH) {
		Catch(enemy);
		soundsManager.Start("CatchSE", false);
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
	Collision();
	pos.x += speed;
	this->jump.Jump(&this->pos);
}

void PLAYER::Attack(Enemy enemy[]) {
	for (int i = 0; i < EnemyMax; i++) {
		Vec EnemyCenter = { enemy[i].GetPos().x + enemy[i].GetSize().width / 2, enemy[i].GetPos().y + enemy[i].GetSize().height / 2 };
		Vec UnderPos = {pos.x + size.width / 2, pos.y + size.height};

		if (enemy[i].GetMode() == Enemy::MODE::ALIVE) {
			if (direction == RIGHT) {
				if (Collision::CircleCollision(UnderPos, size.height, EnemyCenter, enemy[i].GetRadius()) 
					&& UnderPos.x <= EnemyCenter.x 
					&& UnderPos.y >= EnemyCenter.y) {
					enemy[i].SetMode(Enemy::MODE::SWOON);
				}
			}
			if (direction == LEFT) {
				if (Collision::CircleCollision(UnderPos, size.height, EnemyCenter, enemy[i].GetRadius()) 
					&& UnderPos.x >= EnemyCenter.x 
					&& UnderPos.y >= EnemyCenter.y) {
					enemy[i].SetMode(Enemy::MODE::SWOON);
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
			if (pos.y <= enemy[i].GetPos().y) {
				if (direction == RIGHT) {
					if (Collision::CircleCollision(UnderPos, size.height, EnemyCenter, enemy[i].GetRadius()) && pos.x < enemy[i].GetPos().x) {
						enemy[i].SetMode(Enemy::MODE::DEAD);
					}
				}
				if (direction == LEFT) {
					if (Collision::CircleCollision(UnderPos, size.height, EnemyCenter, enemy[i].GetRadius()) && pos.x > enemy[i].GetPos().x) {
						enemy[i].SetMode(Enemy::MODE::DEAD);
					}
				}
			}
		}
	}
}

void PLAYER::SpecialAttack(Enemy enemy[]) {
	for (int i = 0; i < EnemyMax; i++) {
		enemy[i].SetMode(Enemy::MODE::SWOON);
	}
}

void PLAYER::Collision() {
	//Left
	if (Collision::AirBlockCollision(pos, size, Collision::LeftAirBlockPos, Collision::JudgeAirBlockSize, PrevPos)) {
		if (dx.GetKeyState(JUMP) != dx.PUSH) {
			jump.SetJumpFlag(false);
			jump.SetInitialSpeed(25.0f);
		}
		pos.y = Collision::LeftAirBlockPos.y - size.height;
	}
	//Right
	else if (Collision::AirBlockCollision(pos, size, Collision::RightAirBlockPos, Collision::JudgeAirBlockSize, PrevPos)) {
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
	if (pos.x <= 0.0f) {
		pos.x = 0.0f;
	}
	else if (pos.x + size.width >= DISPLAY_WIDTH) {
		pos.x = DISPLAY_WIDTH - size.width;
	}

	//床
	if (pos.y + size.height >= DISPLAY_HEIGHT - Collision::GroundSize.height) {
		pos.y = DISPLAY_HEIGHT - Collision::GroundSize.height - size.height;
		if (dx.GetKeyState(JUMP) == dx.OFF || dx.GetKeyState(JUMP) == dx.RELEASE) {
			jump.SetJumpFlag(false);
		}
	}
}

PLAYER::PLAYER():pos(100.0f,100.0f),direction(RIGHT),speed(0.0f),PrevPos(pos), is_onBlock(false), acc(0.20f){
	SetSize(100.0f, 100.0f);
}

PLAYER::~PLAYER() {

}
