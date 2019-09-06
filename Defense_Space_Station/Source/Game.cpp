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
	dx.LoadTexture("Resource/Player/hammer.png", "HammerAction");
	dx.LoadTexture("Resource/Player/hammerdamage.png", "HammerDamage");
	dx.LoadTexture("Resource/Player/hammerjump.png", "HammerJump");
	dx.LoadTexture("Resource/Player/playerdown.png", "HammerDown");
	dx.LoadTexture("Resource/Player/runhammer.png", "RunHammer");
	dx.LoadTexture("Resource/Player/net.png", "NetAction");
	dx.LoadTexture("Resource/Player/netdamage.png", "NetDamage");
	dx.LoadTexture("Resource/Player/netdown.png", "NetDown");
	dx.LoadTexture("Resource/Player/netjump.png", "NetJump");
	dx.LoadTexture("Resource/Player/playerdash.png", "NetDash");
	dx.LoadTexture("Resource/Enemy/enemyattack.png", "EnemyAttack");
	dx.LoadTexture("Resource/Enemy/Enemy.png", "Enemy");
	dx.LoadTexture("Resource/Enemy/LowEnemy.png", "Low_Enemy");
	dx.LoadTexture("Resource/Enemy/Boss_Purple.png", "Boss");
	dx.LoadTexture("Resource/UI/UI.png", "UI");
	dx.LoadTexture("Resource/Enemy/kurobosi.png", "SwoonEnemy");

	soundsManager.AddFile("Resource/BGM/game_bgm.mp3", "GameBGM");
	soundsManager.AddFile("Resource/SE/player_attack.mp3", "PlayerAttackSE");
	soundsManager.AddFile("Resource/SE/player_catch.mp3", "CatchSE");
	soundsManager.AddFile("Resource/SE/enemy_attack.mp3", "EnemyAttackSE");
	
	soundsManager.SetVolume("GameBGM", 10);
	soundsManager.SetVolume("AttackSE", 15);
	soundsManager.SetVolume("CatchSE", 15);
	soundsManager.SetVolume("EnemyAttackSE", 15);

	/*
	for (int i = 0; i < 6; i++) {
		float width = 56.0f;
		HpPos[i].x = HpLeftPos.x + width * i;
		HpPos[i].y = HpLeftPos.y;
	}
	*/

	HpPos1.x = HpLeftPos.x;
	HpPos2.x = HpLeftPos.x + 56 * 1;
	HpPos3.x = HpLeftPos.x + 56 * 2;
	HpPos4.x = HpLeftPos.x + 56 * 3;
	HpPos5.x = HpLeftPos.x + 56 * 4;
	HpPos6.x = HpLeftPos.x + 56 * 5;

	HpPos1.y = HpLeftPos.y;
	HpPos2.y = HpLeftPos.y;
	HpPos3.y = HpLeftPos.y;
	HpPos4.y = HpLeftPos.y;
	HpPos5.y = HpLeftPos.y;
	HpPos6.y = HpLeftPos.y;



	for (int i = 0; i < EnemyMax; i++) {
		if ( i % 2 == 0) {
			enemy[i].SetPos(200, 780);
		}
		else {
			enemy[i].SetPos(940, 780);
		}
	}
	for (int j = 0; j < 3; j++) {
		enemy[j].SetJump(25.0f, 0.09f);
	}
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
	//dx.Draw(700, 500, 100, 100, 0.0f, 1.0f, false, "Boss");

	for (int i = 0; i < EnemyMax; i++) {
		if (enemy[i].GetMode() == Enemy::MODE::ALIVE) {
			dx.DrawEx(enemy[i].GetPos().x, enemy[i].GetPos().y, 0.0f, enemy[i].GetSize().width, enemy[i].GetSize().height, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "Enemy", 0.0f, 0.0f, 1.0f, 1285.0f / 1500.0f);
		}
		if (enemy[i].GetMode() == Enemy::MODE::SWOON) {
			Anime::Animation(&SwoonEnemy, 100.0f / 1024.0f * 2, true);
			dx.DrawEx(enemy[i].GetPos().x, enemy[i].GetPos().y, 0.0f, enemy[i].GetSize().width, enemy[i].GetSize().height, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "SwoonEnemy", SwoonEnemy.Tu, 0.0f, SwoonEnemy.Tw, 100.0f / 256.0f);
		}
	}

	/*
	for (int i = 0; i < 6; i++) {
		dx.DrawEx(HpPos[i].x, HpPos[i].y, 0.0f, HpSize.width, HpSize.height, 0.0f, 1.0f, false, "UI", HpUV.tu, HpUV.tv, HpUV.tw, HpUV.th);
	}
	*/
	PlayerDraw();
	
	DrawUI();
}

void GAME::Release() {
	dx.ReleaseTexture("SwoonEnemy");
	dx.ReleaseTexture("UI");
	dx.ReleaseTexture("Boss");
	dx.ReleaseTexture("Low_Enemy");
	dx.ReleaseTexture("Enemy");
	dx.ReleaseTexture("EnemyAttack");
	dx.ReleaseTexture("NetDash");
	dx.ReleaseTexture("NetJump");
	dx.ReleaseTexture("NetDown");
	dx.ReleaseTexture("NetDamage");
	dx.ReleaseTexture("NetAction");
	dx.ReleaseTexture("RunHammer");
	dx.ReleaseTexture("HammerDown");
	dx.ReleaseTexture("HammerJump");
	dx.ReleaseTexture("HammerDamage");
	dx.ReleaseTexture("HammerAction");
	dx.ReleaseTexture("AirBlock");
	dx.ReleaseTexture("GameBack");
}

void GAME::DrawUI() {
	dx.DrawEx(HpVarPos.x, HpVarPos.y, 0.0f, HpVarSize.width, HpVarSize.height, 0.0f, 1.0f, false, "UI", HpVarUV.tu, HpVarUV.tv, HpVarUV.tw, HpVarUV.th);
	dx.DrawEx(UltVarPos.x, UltVarPos.y, 0.0f, UltVarSize.width, UltVarSize.height, 0.0f, 1.0f, false, "UI", UltVarUV.tu, UltVarUV.tv, UltVarUV.tw, UltVarUV.th);

	dx.DrawEx(HpPos1.x, HpPos1.y, 0.0f, HpSize.width, HpSize.height, 0.0f, 1.0f, false, "UI", HpUV1.tu, HpUV1.tv, HpUV1.tw, HpUV1.th);
	dx.DrawEx(HpPos2.x, HpPos2.y, 0.0f, HpSize.width, HpSize.height, 0.0f, 1.0f, false, "UI", HpUV2.tu, HpUV2.tv, HpUV2.tw, HpUV2.th);
	dx.DrawEx(HpPos3.x, HpPos3.y, 0.0f, HpSize.width, HpSize.height, 0.0f, 1.0f, false, "UI", HpUV3.tu, HpUV3.tv, HpUV3.tw, HpUV3.th);
	dx.DrawEx(HpPos4.x, HpPos4.y, 0.0f, HpSize.width, HpSize.height, 0.0f, 1.0f, false, "UI", HpUV4.tu, HpUV4.tv, HpUV4.tw, HpUV4.th);
	dx.DrawEx(HpPos5.x, HpPos5.y, 0.0f, HpSize.width, HpSize.height, 0.0f, 1.0f, false, "UI", HpUV5.tu, HpUV5.tv, HpUV5.tw, HpUV5.th);
	dx.DrawEx(HpPos6.x, HpPos6.y, 0.0f, HpSize.width, HpSize.height, 0.0f, 1.0f, false, "UI", HpUV6.tu, HpUV6.tv, HpUV6.tw, HpUV6.th);
}

void GAME::PlayerDraw() {
	if (player.item == player.LAST_ITEM::HAMMER) {
		if (player.is_attack)
		{
			Anime::Animation(&AttackMotion, 535.0f / 16384.0f * 17, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "HammerAction", AttackMotion.Tu, 0.0f, AttackMotion.Tw, 390.0f / 512.0f);
			player.is_attack = AttackMotion.flee_frag;
		}
		else if (player.is_move && player.jump.GetJumpFlag())
		{
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "RunHammer", Ran.Tu, 0.0f, Ran.Tw, 390.0f / 512.0f);
		}
		else if (player.is_move && !player.jump.GetJumpFlag())
		{
			Anime::Animation(&Ran, 535.0f / 8192.0f * 11, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "RunHammer", Ran.Tu, 0.0f, Ran.Tw, 390.0f / 512.0f);

		}
		else if (player.jump.GetJumpFlag())
		{
			Anime::Animation(&Jump, 535.0f / 16384.0f * 17, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "HammerJump", Jump.Tu, 0.0f, Jump.Tw, 390.0f / 512.0f);
			if (player.jump.GetJumpFlag() == false)
			{
				Ran.Tu = 0.0f;
			}
		}
		else if (!player.is_move)
		{
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "HammerAction", 0.0f, 0.0f, 535.0f / 16384.0f * 1, 390.0f / 512.0f);
		}
		//dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "RunHammer", AttackMotion.Tu, 0.0f, AttackMotion.Tw, 400.0f / 512.0f);
		//dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "RunHammer", AttackMotion.Tu, 0.0f, AttackMotion.Tw, 400.0f / 512.0f);
	}
	else if (player.item == player.LAST_ITEM::NET)
	{
		if (player.is_attack)
		{
			Anime::Animation(&AttackMotion, 535.0f / 16384.0f * 17, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetAction", AttackMotion.Tu, 0.0f, AttackMotion.Tw, 390.0f / 512.0f);
			player.is_attack = AttackMotion.flee_frag;
		}
		else if (player.is_move && player.jump.GetJumpFlag())
		{
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetDash", Ran.Tu, 0.0f, Ran.Tw, 390.0f / 512.0f);
		}
		else if (player.is_move && !player.jump.GetJumpFlag())
		{
			Anime::Animation(&Ran, 535.0f / 8192.0f * 11, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetDash", Ran.Tu, 0.0f, Ran.Tw, 390.0f / 512.0f);

		}
		else if (player.jump.GetJumpFlag())
		{
			Anime::Animation(&Jump, 535.0f / 16384.0f * 17, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetJump", Jump.Tu, 0.0f, Jump.Tw, 390.0f / 512.0f);
			if (player.jump.GetJumpFlag() == false)
			{
				Ran.Tu = 0.0f;
			}
		}
		else if (!player.is_move)
		{
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetAction", 0.0f, 0.0f, 535.0f / 16384.0f * 1, 390.0f / 512.0f);
		}
	}
	if (AttackMotion.flee_frag == false)
	{
		AttackMotion.flee_frag = true;
	}
}

GAME::GAME() {

}

GAME::~GAME() {

}