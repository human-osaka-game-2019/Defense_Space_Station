#ifndef GAME_H_
#define GAME_H_

#include "../Header/Player.h"
#include "../Header/Enemy.h"
#include "../Header/Animation.h"
#include "../Header/UserInterface.h"

class GAME {
public:
	GAME();
	~GAME();

	void UpdateScene();

	UserInterface::UV HpUV1 = { 20.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV HpUV2 = { 20.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV HpUV3 = { 20.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV HpUV4 = { 20.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV HpUV5 = { 20.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV HpUV6 = { 20.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };

	UserInterface::UV UltUV1 = { 260.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV UltUV2 = { 260.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV UltUV3 = { 260.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV UltUV4 = { 260.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV UltUV5 = { 260.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };
	UserInterface::UV UltUV6 = { 260.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };


private:
	enum STEP {
		LoadStep,
		MainStep,
		ReleaseStep
	};

	STEP step = LoadStep;

	PLAYER player;
	Enemy enemy[EnemyMax];
	const Size HpSize{ 40,40 };
	const Size UltSize{ 40,40 };
	Vec HpLeftPos = { 246, 60 };
	Vec UltLeftPos = {890,60};

	//Vec HpPos[6];
	Vec HpPos1;
	Vec HpPos2;
	Vec HpPos3;
	Vec HpPos4;
	Vec HpPos5;
	Vec HpPos6;
	bool is_clear;
	Vec UltPos1;
	Vec UltPos2;
	Vec UltPos3;
	Vec UltPos4;
	Vec UltPos5;
	Vec UltPos6;
	const Size HpVarSize{580,100};
	const Vec HpVarPos{ 40, 35 };
	UserInterface::UV HpVarUV = { 320.0f / 2480.0f,150.0f / 1024.0f,575.0f / 2480.0f,100.0f / 1024.0f };
	const Size UltVarSize{ 580,100 };
	const Vec UltVarPos{ 675,35 };
	UserInterface::UV UltVarUV = { 980.0f / 2480.f,150.0f / 1024.0f,575.0f / 2480.0f,100.0f / 1024.0f };
	AnimeData AttackMotion = { 0.0f, 535.0f / 16384.0f , 0, _1F, false};
	AnimeData SwoonEnemy = { 0.0f, 100.0f / 1024.0f, 0, _15F, false};
	AnimeData Jump = { 0.0f, 535.0f / 16384.0f, 0, _6F, false };
	AnimeData Ran = { 0.0f, 535.0f / 8192.0f, 0, _8F, false };
	AnimeData Down = { 0.0f, 535.0f / 8192.0f, 0, _8F, false };
	AnimeData Damage = { 0.0f, 535.0f / 4096.0f, 0, _15F, false };
	
	void DrawUI();
	void PlayerDraw();

	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_H_
