#include "../Header/Game.h"
#include "../Header/Main.h"
#include "../Header/Collision.h"

using Collision::RightAirBlockPos;
using Collision::LeftAirBlockPos;
using Collision::DrawAirBlockSize;

void GAME::UpdateScene() {
	switch (step)
	{
	case GAME::LoadStep:
		Load();
		break;
	case GAME::MainStep:
		Control();
		Draw();
		break;
	case GAME::ReleaseStep:
		Release();
		break;
	default:
		break;
	}
}

void GAME::Load() {
	dx.LoadTexture("Resource/BackGround/GameBack.png", "GameBack");
	dx.LoadTexture("Resource/BackGround/Footing.png", "AirBlock");
	dx.LoadTexture("Resource/Player/test.png", "test");
	dx.LoadTexture("Resource/Enemy/Enemy.png", "Enemy");
	dx.LoadTexture("Resource/Enemy/LowEnemy.png", "Low_Enemy");
	dx.LoadTexture("Resource/Enemy/Boss_Purple.png", "Boss");
	dx.LoadTexture("Resource/Enemy/SwoonEnemy.png", "SwoonEnemy");
	dx.LoadTexture("Resource/UI/hp_border.png", "hp_border");
	dx.LoadTexture("Resource/UI/hp.png", "hp");
	dx.LoadTexture("Resource/UI/half_hp.png", "half_hp.png");

	soundsManager.AddFile("Resource/BGM/game_bgm.mp3", "GameBGM");
	soundsManager.AddFile("Resource/SE/player_attack.mp3", "PlayerAttackSE");
	soundsManager.AddFile("Resource/SE/player_catch.mp3", "CatchSE");
	soundsManager.AddFile("Resource/SE/enemy_attack.mp3", "EnemyAttackSE");

	soundsManager.SetVolume("GameBGM", 10);
	soundsManager.SetVolume("AttackSE", 15);
	soundsManager.SetVolume("CatchSE", 15);
	soundsManager.SetVolume("EnemyAttackSE", 15);


	enemy[0].SetPos(200, 940);
	enemy[1].SetPos(940, 940);
	enemy[2].SetPos(400, 940);
	enemy[0].SetJump(8.0f, 0.2f);
	step = MainStep;

}

void GAME::Control() {
	soundsManager.Start("GameBGM", true);
	player.Control(enemy);

	for (int i = 0; i < EnemyMax; i++) {
		enemy[i].EnemyMove(player.GetPos(), player.GetSize());
		}
	//EnemyCollision(enemy);

	

#ifdef _DEBUG
	if (dx.GetKeyState(DIK_ESCAPE) == dx.PUSH) {
		step = ReleaseStep;
	}
#endif
}

void GAME::Draw() {
	dx.Draw(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 1.0f, false, "GameBack");
	dx.Draw(RightAirBlockPos.x, RightAirBlockPos.y, DrawAirBlockSize.width, DrawAirBlockSize.height, 0.0f, 1.0f, false, "AirBlock");
	dx.Draw(LeftAirBlockPos.x, LeftAirBlockPos.y, DrawAirBlockSize.width, DrawAirBlockSize.height, 0.0f, 1.0f, false, "AirBlock");
	dx.Draw(player.GetPos().x, player.GetPos().y, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "test");
	//dx.Draw(700, 500, 100, 100, 0.0f, 1.0f, false, "Boss");

	for (int i = 0; i < EnemyMax; i++) {
		if (enemy[i].GetMode() == Enemy::MODE::ALIVE) {
			dx.Draw(enemy[i].GetPos().x, enemy[i].GetPos().y, enemy[i].GetSize().width, enemy[i].GetSize().height, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "Enemy");
		}
		if (enemy[i].GetMode() == Enemy::MODE::SWOON) {
			dx.Draw(enemy[i].GetPos().x, enemy[i].GetPos().y, enemy[i].GetSize().width, enemy[i].GetSize().height, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "SwoonEnemy");
		}
	}
}

void GAME::Release() {
	dx.ReleaseTexture("Boss");
	dx.ReleaseTexture("Low_Enemy");
	dx.ReleaseTexture("Enemy");
	dx.ReleaseTexture("test");
	dx.ReleaseTexture("AirBlock");
	dx.ReleaseTexture("GameBack");
}

GAME::GAME() {

}

GAME::~GAME() {

}