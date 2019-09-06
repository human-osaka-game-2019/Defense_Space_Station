#include "../Header/Title.h"
#include "../Header/Main.h"
#include "../Header/Jump.h"

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
	//JumpPushEnter();
	//if (PushEnterPos.y > 50) {
	//	JumpSpeed = 7.0f;
	//}
	if (is_Slide) {
		Slide();
	}

	if (dx.GetKeyState(DIK_RETURN) == dx.PUSH && dx.GetKeyState(DIK_RMENU) == dx.OFF) {
		is_Slide = true;
	}
	if (TopStartButtonPos.x <= -540) {
		step = ReleaseStep;
	}
}

void TITLE::Draw() {
	dx.Draw(BackGroundPos.x, BackGroundPos.y, BackGroundSize.width, BackGroundSize.height, 0.0f, 1.0f, false, "BackGround");
	dx.DrawCenter(LogoCenterPos.x, LogoCenterPos.y, LogoSize.width, LogoSize.height, 0.0f, logo_zoom, false, "Logo");
	dx.DrawEx(TopStartButtonPos.x, TopStartButtonPos.y, 0, TopStartButtonSize.width, TopStartButtonSize.height, 0.0f, 1.0f, false, "PushEnter", 0.0f, 0.0f,1.0f, 910.0f / 1080.0f);
	dx.DrawEx(UnderStartButtonPos.x, UnderStartButtonPos.y, 0, UnderStartButtonSize.width, UnderStartButtonSize.height, 0.0f, 1.0f, false, "PushEnter", 0.0f, 910.0f / 1080.0f, 1.0f, 1.0f);
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

//void TITLE::JumpPushEnter() {
//	JumpSpeed += JumpAcc;
//	PushEnterPos.y -= JumpSpeed;
//}

void TITLE::Slide(){
	TopStartButtonPos.x -= 40.0f;
	UnderStartButtonPos.x += 40.0f;
}

TITLE::TITLE():JumpSpeed(0.0f){

}

TITLE::~TITLE() {

}