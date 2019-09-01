#include "../Header/Player.h"
#include "../Header/Main.h"
#include "../Header/Collision.h"

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

DIRECTION PLAYER::GetDirection() {
	return direction;
}

void PLAYER::Control(Enemy enemy[]) {
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		direction = LEFT;
		pos.x -= speed;
	}
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		direction = RIGHT;
		pos.x += speed;
	}
	if (dx.GetKeyState(DIK_W) == dx.PUSH) {
		this->jump.JumpFlagTrue();
	}
	if (dx.GetKeyState(DIK_J) == dx.PUSH) {
		Attack(enemy);
	}
	if (dx.GetKeyState(DIK_K) == dx.PUSH) {
		Catch(enemy);
	}
	if (dx.GetKeyState(DIK_L) == dx.PUSH) {
		SpecialAttack(enemy);
	}
#ifdef _DEBUG
	if (dx.GetKeyState(DIK_RETURN) == dx.PUSH) {
		for (int i = 0; i < EnemyMax; i++) {
			enemy[i].is_dead = false;
		}
	}
#endif
	this->jump.Jump(&this->pos);

}

void PLAYER::Attack(Enemy enemy[]) {
	for (int i = 0; i < EnemyMax; i++) {
		Vec EnemyCenter = { enemy[i].GetPos().x + enemy[i].GetSize().width / 2, enemy[i].GetPos().y + enemy[i].GetSize().height / 2 };
		Vec UnderPos = {pos.x + size.width / 2, pos.y + size.height};
		if (direction == RIGHT) {
			if (Collision::CircleCollision(UnderPos, size.height, EnemyCenter, enemy[i].GetRadius()) && pos.x < enemy[i].GetPos().x) {
				enemy[i].is_dead = true;
			}
		}
		if (direction == LEFT) {
			if (Collision::CircleCollision(UnderPos, size.height, EnemyCenter, enemy[i].GetRadius()) && pos.x > enemy[i].GetPos().x) {
				enemy[i].is_dead = true;
			}
		}
		
	}
}

void PLAYER::Catch(Enemy enemy[]) {

}

void PLAYER::SpecialAttack(Enemy enemy[]) {
	for (int i = 0; i < EnemyMax; i++) {
		enemy[i].is_dead = true;
	}
}

PLAYER::PLAYER():pos(100.0f,100.0f),direction(RIGHT),speed(15.0f){
	SetSize(100.0, 100.0f);
}

PLAYER::~PLAYER() {

}
