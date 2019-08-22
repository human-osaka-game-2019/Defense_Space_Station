#ifndef ENEMYCPU
#define ENEMYCPU

class Enemy
{
public:
	Enemy();
	~Enemy();

	float GetPos_X();
	void SetPos_X(float Pos_X);
	int GetRePopCount();
	void SetRePopCount();
	int GetMode();
	void SetMode();

private:
	float Pos_X;
	int RePopCount;
	int Mode;

};

float Enemy::GetPos_X()
{

	return this->Pos_X;

}

void Enemy::SetPos_X(float Pos_X)
{

	this->Pos_X = Pos_X;

}

int Enemy::GetRePopCount()
{

	return this->RePopCount;

}

void Enemy::SetRePopCount()
{

}

#endif // !1

