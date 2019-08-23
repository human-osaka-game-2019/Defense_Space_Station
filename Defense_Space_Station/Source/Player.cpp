#include "../Header/Player.h"
#include "../Header/Main.h"
#include "../Header/Jump.h"

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

void PLAYER::Move() {
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		pos.x -= speed;
	}
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		pos.x += speed;
	}
	if (dx.GetKeyState(DIK_W) == dx.ON) {
		//JUMP!!
	}
}

PLAYER::PLAYER():speed(5.0f) {
	SetPos(100.0f, 100.0f);
	SetSize(100.0, 100.0f);
}

PLAYER::~PLAYER() {

}
