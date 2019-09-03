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
	dx.LoadTexture("Resource/Player/test.png", "test");
	dx.LoadTexture("Resource/Enemy/Enemy.png", "Enemy");
	dx.LoadTexture("Resource/Enemy/LowEnemy.png", "Low_Enemy");
	dx.LoadTexture("Resource/Enemy/Boss_Purple.png", "Boss");
	dx.LoadTexture("Resource/BackGround/GameBack.png", "GameBack");
	dx.LoadTexture("Resource/BackGround/Footing.png", "AirBlock");

	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0) {
			enemy[i].SetPos(1800, 800);
		}
		else {
			enemy[i].SetPos(0, 800);
		}
	}
	enemy[0].SetJump(8.0f, 0.2f);
	step = MainStep;
}

void GAME::Control() {
	player.Control(enemy);

	for (int i = 0; i < EnemyMax; i++) {
		enemy[i].EnemyMove(player.GetPos());
	}

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
		if (enemy[i].GetMode() != Enemy::MODE::DEAD) {
			dx.Draw(enemy[i].GetPos().x, enemy[i].GetPos().y, 100, 100, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "Enemy");
		}
	}
}

void GAME::Release() {
	dx.ReleaseTexture("AirBlock");
	dx.ReleaseTexture("GameBack");
	dx.ReleaseTexture("Boss");
	dx.ReleaseTexture("Low_Enemy");
	dx.ReleaseTexture("Enemy");
	dx.ReleaseTexture("test");
}

GAME::GAME() {

}

GAME::~GAME() {

}