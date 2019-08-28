#include "../Header/Game.h"
#include "../Header/Main.h"

void GAME::UpdateScene() {
	switch (step)
	{
	case GAME::LoadStep:Load();
		break;
	case GAME::MainStep:Control();
		Draw();
		break;
	case GAME::ReleaseStep:Release();
		break;
	default:
		break;
	}
}

void GAME::Load() {
	dx.LoadTexture("Resource/Player/test.png", "test");
	dx.LoadTexture("Resource/Enemy/Enemy.png", "Enemy");
	dx.LoadTexture("Resource/Enemy/LowEnemy.png", "Low_Enemy");
	dx.LoadTexture("Resource/Enemy/Boss_Purple.png", "Boss");
	dx.LoadTexture("Resource/BackGround/GameBack.jpg", "Game_BG");
	step = MainStep;
}

void GAME::Control() {
	player.Control();

	//enemy.EnemyMove();

#ifdef _DEBUG
	if (dx.GetKeyState(DIK_ESCAPE) == dx.PUSH) {
		step = ReleaseStep;
	}
#endif
}

void GAME::Draw() {
	dx.Draw(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 1.0f, false, "Game_BG");
	dx.Draw(player.GetPos().x, player.GetPos().y, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, player.is_Reverse, "test");
	dx.Draw(500, 500, 100, 100, 0.0f, 1.0f, false, "Low_Enemy");
	dx.Draw(700, 500, 100, 100, 0.0f, 1.0f, false, "Boss");
	dx.Draw(enemy.GetPos().x, enemy.GetPos().y, 100, 100, 0.0f, 1.0f, false, "Enemy");
}

void GAME::Release() {
	dx.ReleaseTexture("Game_BG");
	dx.ReleaseTexture("Boss");
	dx.ReleaseTexture("Low_Enemy");
	dx.ReleaseTexture("Enemy");
	dx.ReleaseTexture("test");
}

GAME::GAME() {

}

GAME::~GAME() {

}