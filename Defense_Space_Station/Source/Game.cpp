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
	dx.LoadTexture("Resource/Player/Animetion.png", "Anime");
	dx.LoadTexture("Resource/Enemy/Enemy.png", "Enemy");
	dx.LoadTexture("Resource/Enemy/LowEnemy.png", "Low_Enemy");
	dx.LoadTexture("Resource/Enemy/Boss_Purple.png", "Boss");
	dx.LoadTexture("Resource/Enemy/SwoonEnemy.png", "SwoonEnemy");
	dx.LoadTexture("Resource/UI/UI.png", "UI");
	soundsManager.AddFile("Resource/BGM/game_bgm.mp3", "GameBGM");
	soundsManager.AddFile("Resource/SE/player_attack.mp3", "PlayerAttackSE");
	soundsManager.AddFile("Resource/SE/player_catch.mp3", "CatchSE");
	soundsManager.AddFile("Resource/SE/enemy_attack.mp3", "EnemyAttackSE");
	
	soundsManager.SetVolume("GameBGM", 10);
	soundsManager.SetVolume("AttackSE", 15);
	soundsManager.SetVolume("CatchSE", 15);
	soundsManager.SetVolume("EnemyAttackSE", 15);


	for (int i = 0; i < 6; i++) {
		float width = 56.0f;
		HpPos[i].x = HpLeftPos.x + width * i;
		HpPos[i].y = HpLeftPos.y;
	}
	

	for (int i = 0; i < EnemyMax; i++) {
		if ( i % 2 == 0) {
			enemy[i].SetPos(200, 780);
		}
		else {
			enemy[i].SetPos(940, 780);
		}
	}

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

	

	Anime::Animation(data, 0.75f);
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
	dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "Anime", data[0].Tu, 0.0f, data[0].Tw, 0.25f);
	dx.DrawEx(HpVarPos.x, HpVarPos.y, 0.0f, HpVarSize.width, HpVarSize.height, 0.0f, 1.0f, false, "UI", HpVarUV.tu, HpVarUV.tv, HpVarUV.tw, HpVarUV.th);
	//dx.Draw(player.GetPos().x, player.GetPos().y, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "test");
	//dx.Draw(700, 500, 100, 100, 0.0f, 1.0f, false, "Boss");

	for (int i = 0; i < EnemyMax; i++) {
		if (enemy[i].GetMode() == Enemy::MODE::ALIVE) {
			dx.Draw(enemy[i].GetPos().x, enemy[i].GetPos().y, enemy[i].GetSize().width, enemy[i].GetSize().height, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "Enemy");
		}
		if (enemy[i].GetMode() == Enemy::MODE::SWOON) {
			dx.Draw(enemy[i].GetPos().x, enemy[i].GetPos().y, enemy[i].GetSize().width, enemy[i].GetSize().height, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "SwoonEnemy");
		}
	}

	for (int i = 0; i < 6; i++) {
		dx.DrawEx(HpPos[i].x, HpPos[i].y, 0.0f, HpSize.width, HpSize.height, 0.0f, 1.0f, false, "UI", HpUV.tu, HpUV.tv, HpUV.tw, HpUV.th);
	}

}

void GAME::Release() {
	dx.ReleaseTexture("UI");
	dx.ReleaseTexture("Boss");
	dx.ReleaseTexture("Low_Enemy");
	dx.ReleaseTexture("Enemy");
	dx.ReleaseTexture("test");
	dx.ReleaseTexture("Anime");
	dx.ReleaseTexture("AirBlock");
	dx.ReleaseTexture("GameBack");
}

GAME::GAME() {

}

GAME::~GAME() {

}