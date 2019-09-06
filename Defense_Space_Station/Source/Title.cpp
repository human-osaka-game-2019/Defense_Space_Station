#include "../Header/Title.h"
#include "../Header/Main.h"
#include "../Header/Jump.h"

extern SCENE g_scene;

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
	dx.LoadTexture("Resource/BackGround/TitleBack.png", "BackGround");
	dx.LoadTexture("Resource/UI/TitleLogo.png", "Logo");
	dx.LoadTexture("Resource/UI/PushEnter.png", "PushEnter");

	step = MainStep;
}

void TITLE::Control() {

	ZoomLogo();

	if (dx.GetKeyState(DIK_RETURN) == dx.PUSH && dx.GetKeyState(DIK_RMENU) == dx.OFF) {
		step = ReleaseStep;
	}
}

void TITLE::Draw() {
	dx.Draw(BackGroundPos.x, BackGroundPos.y, BackGroundSize.width, BackGroundSize.height, 0.0f, 1.0f, false, "BackGround");
	dx.DrawCenter(LogoCenterPos.x, LogoCenterPos.y, LogoSize.width, LogoSize.height, 0.0f, logo_zoom, false, "Logo");
	dx.Draw(PushEnterPos.x, PushEnterPos.y, PushEnterSize.width, PushEnterSize.height, 0.0f, 1.0f, false, "PushEnter");
}

void TITLE::Release() {
	dx.ReleaseTexture("PushEnter");
	dx.ReleaseTexture("Logo");
	dx.ReleaseTexture("BackGround");

	g_scene = Game;
}

void TITLE::ZoomLogo() {
	if (will_big) {
		logo_zoom += ZoomSpeed;
		if (logo_zoom >= MaxZoom) {
			will_big = false;
		}
	}
	if (!will_big) {
		logo_zoom -= ZoomSpeed;
		if (logo_zoom <= MinZoom) {
			will_big = true;
		}
	}
}

TITLE::TITLE(){

}

TITLE::~TITLE() {

}