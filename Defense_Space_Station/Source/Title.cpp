#include "../Header/Title.h"
#include "../Header/Main.h"

void TITLE::UpdateScene() {
	switch (step)
	{
	case TITLE::LoadStep:Load();
		break;
	case TITLE::MainStep:Control();
		Draw();
		break;
	case TITLE::ReleaseStep:Release();
		break;
	default:
		break;
	}
}

void TITLE::Load() {

}

void TITLE::Control() {

}

void TITLE::Draw() {

}

void TITLE::Release() {

}

TITLE::TITLE() {

}

TITLE::~TITLE() {

}