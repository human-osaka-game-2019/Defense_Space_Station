#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Header/Vector.h"
#include "../Header/Size.h"
#include "../Header/Enemy.h"
#include "../Header/Jump.h"
#include "../Header/Direction.h"
#include "../Header/Main.h"

#define JUMP DIK_W

class PLAYER{
public:
	PLAYER();
	~PLAYER();

	enum LAST_ITEM
	{
		HAMMER,
		NET
	};

	void SetPos(float x, float y);
	Vec GetPos();
	void SetSize(float width, float height);
	Size GetSize();
	void SetHp(int);
	int GetHp();
	void SetCatchCount(int);
	int GetCatchCount();
	void SetRemainingEnemyCount(int);
	int GetRemainingEnemyCount();
	DIRECTION::Direction GetDirection();
	void Control(Enemy enemy[]);
	LAST_ITEM item;
	bool is_attack;
	bool is_catch;
	bool is_move;
	bool is_damege;
	JUMP_MOVE jump;
	

private:

	Vec pos;
	Vec UnderPos;
	Size size;
	Vec collision_pos;
	Size collision_size;
	DIRECTION::Direction direction;
	float speed;
	int hp;
	int collision_count;
	bool is_god;
	int catchcount;
	int remainingenemycount;

	Vec PrevPos;

	//! Acceleration(加速度)
	float acc;

	void Attack(Enemy enemy[]);
	void Catch(Enemy enemy[]);
	void SpecialAttack(Enemy enemy[]);

	void Collision(Enemy enemy[]);

};

#endif
