#include "../Header/Player.h"
#include "../Header/Main.h"

HAMMER::HAMMER(float x, float y):degree(0.0f) {
	this->pos.x = x;
	this->pos.y = y;
}

HAMMER::~HAMMER() {

}

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

void PLAYER::Control() {
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		is_Reverse = true;
		pos.x -= speed;
	}
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		is_Reverse = false;
		pos.x += speed;
	}
	if (dx.GetKeyState(DIK_J) == dx.PUSH) {
		Attack();
	}
	if (dx.GetKeyState(DIK_K) == dx.PUSH) {
		Catch();
	}
	if (dx.GetKeyState(DIK_L) == dx.PUSH) {
		SpecialAttack();
	}
}

void PLAYER::Attack() {

}

void PLAYER::Catch() {

}

void PLAYER::SpecialAttack() {

}

PLAYER::PLAYER():is_Reverse(false),pos(100.0f,100.0f),speed(5.0f),hammer(pos.x, pos.y){
	SetSize(100.0, 100.0f);
}

PLAYER::~PLAYER() {

}
