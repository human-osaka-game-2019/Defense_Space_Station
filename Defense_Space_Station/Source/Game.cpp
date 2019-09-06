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
	dx.LoadTexture("Resource/Player/hammer.png", "HammerAction");
	dx.LoadTexture("Resource/Player/hammerdamage.png", "HammerDamage");
	dx.LoadTexture("Resource/Player/hammerjump.png", "HammerJump");
	dx.LoadTexture("Resource/Player/runhammer.png", "RunHammer");
	dx.LoadTexture("Resource/Player/net.png", "NetAction");
	dx.LoadTexture("Resource/Player/netdamage.png", "NetDamage");
	dx.LoadTexture("Resource/Player/netdown.png", "NetDown");
	dx.LoadTexture("Resource/Player/netjump.png", "NetJump");
	dx.LoadTexture("Resource/Player/playerdash.png", "NetDash");
	dx.LoadTexture("Resource/Player/playerdown.png", "NetDown");
	dx.LoadTexture("Resource/Enemy/enemyattack.png", "EnemyAttack");
	dx.LoadTexture("Resource/Enemy/Enemy.png", "Enemy");
	dx.LoadTexture("Resource/Enemy/LowEnemy.png", "Low_Enemy");
	dx.LoadTexture("Resource/Enemy/Boss_Purple.png", "Boss");
	dx.LoadTexture("Resource/Enemy/kurobosi.png", "SwoonEnemy");
	soundsManager.AddFile("Resource/BGM/game_bgm.mp3", "GameBGM");
	soundsManager.AddFile("Resource/SE/player_attack.mp3", "PlayerAttackSE");
	soundsManager.AddFile("Resource/SE/player_catch.mp3", "CatchSE");
	soundsManager.AddFile("Resource/SE/enemy_attack.mp3", "EnemyAttackSE");
	
	soundsManager.SetVolume("GameBGM", 10);
	soundsManager.SetVolume("AttackSE", 15);
	soundsManager.SetVolume("CatchSE", 15);
	soundsManager.SetVolume("EnemyAttackSE", 15);

	

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
	if (player.Item == player.LAST_ITEM::HAMMER) {
		if(player.is_attack)
		{
			Anime::Animation(&AttackMotion, 535.0f / 16384.0f * 17, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "HammerAction", AttackMotion.Tu, 0.0f, AttackMotion.Tw, 400.0f / 512.0f);
			player.is_attack = AttackMotion.flee_frag;
		}else if (player.is_move && player.jump.GetJumpFlag()) 
		{
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "RunHammer", Ran.Tu, 0.0f, Ran.Tw, 400.0f / 512.0f);
		}
		else if(player.is_move && !player.jump.GetJumpFlag())
		{
			Anime::Animation(&Ran, 535.0f / 8192.0f * 11, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "RunHammer", Ran.Tu, 0.0f, Ran.Tw, 400.0f / 512.0f);

		}else if (player.jump.GetJumpFlag()) 
		{
			Anime::Animation(&Jump, 535.0f / 16384.0f * 17, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "HammerJump", Jump.Tu, 0.0f, Jump.Tw, 400.0f / 512.0f);
			if (player.jump.GetJumpFlag() == false)
			{
				Ran.Tu = 0.0f;
			}
		}
		else if (!player.is_move)
		{
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "HammerAction", 0.0f, 0.0f, 535.0f / 16384.0f * 1, 400.0f / 512.0f);
		}
		//dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "RunHammer", AttackMotion.Tu, 0.0f, AttackMotion.Tw, 400.0f / 512.0f);
		//dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "RunHammer", AttackMotion.Tu, 0.0f, AttackMotion.Tw, 400.0f / 512.0f);
	}
	else if(player.Item == player.LAST_ITEM::NET)
	{
		if (player.is_attack)
		{
			Anime::Animation(&AttackMotion, 535.0f / 16384.0f * 17, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetAction", AttackMotion.Tu, 0.0f, AttackMotion.Tw, 400.0f / 512.0f);
			player.is_attack = AttackMotion.flee_frag;
		}
		else if (player.is_move && player.jump.GetJumpFlag())
		{
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetDash", Ran.Tu, 0.0f, Ran.Tw, 400.0f / 512.0f);
		}
		else if (player.is_move && !player.jump.GetJumpFlag())
		{
			Anime::Animation(&Ran, 535.0f / 8192.0f * 11, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetDash", Ran.Tu, 0.0f, Ran.Tw, 400.0f / 512.0f);
			if (player.jump.GetJumpFlag() == false)
			{
				Ran.Tu = 0.0f;
			}

		}
		else if (player.jump.GetJumpFlag())
		{
			Anime::Animation(&Jump, 535.0f / 16384.0f * 17, false);
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetJump", Jump.Tu, 0.0f, Jump.Tw, 400.0f / 512.0f);
		}
		else if (!player.is_move)
		{
			dx.DrawEx(player.GetPos().x, player.GetPos().y, 0.0f, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, (bool)player.GetDirection(), "NetAction", 0.0f, 0.0f, 535.0f / 16384.0f * 1, 400.0f / 512.0f);
		}
	}
			if (AttackMotion.flee_frag == false)
			{
				AttackMotion.flee_frag = true;
			}
	//dx.Draw(700, 500, 100, 100, 0.0f, 1.0f, false, "Boss");

	for (int i = 0; i < EnemyMax; i++) {
		if (enemy[i].GetMode() == Enemy::MODE::ALIVE) {
			dx.Draw(enemy[i].GetPos().x, enemy[i].GetPos().y, enemy[i].GetSize().width, enemy[i].GetSize().height, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "Enemy");
		}
		if (enemy[i].GetMode() == Enemy::MODE::SWOON) {
			Anime::Animation(&SwoonEnemy, 100.0f / 1024.0f * 2, true);
			dx.DrawEx(enemy[i].GetPos().x, enemy[i].GetPos().y, 0.0f, enemy[i].GetSize().width, enemy[i].GetSize().height, 0.0f, 1.0f, (bool)enemy[i].GetDirection(), "SwoonEnemy", SwoonEnemy.Tu, 0.0f, SwoonEnemy.Tw, 120.0f / 256.0f);
		}
	}
}

void GAME::Release() {
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