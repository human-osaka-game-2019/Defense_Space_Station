#ifndef JUMP
#define JUMP

class JUMP_MOVE
{
public:

	JUMP_MOVE();
	~JUMP_MOVE();

	int GetPos_Y();
	void SetPos_Y(float Pos_Y);
	int GetSpeed();
	void SetSpeed(float Speed);
	int GetInitialSpeed();
	void SetInitialSpeed(float Initial_speed);
	void jump(float* Pos_Y, float* Initial_speed, float Speed);

private:

	float Pos_Y;
	float Speed;
	float Initial_speed;

};



#endif //JUMP
