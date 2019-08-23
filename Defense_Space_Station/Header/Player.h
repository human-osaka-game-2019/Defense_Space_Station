#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Header/Vector.h"
#include "../Header/Size.h"

class PLAYER {
public:
	PLAYER();
	~PLAYER();

	void SetPos(float x, float y);
	Vec GetPos();
	void SetSize(float width, float height);
	Size GetSize();
	void Move();

private:
	Vec pos;
	Size size;
	//JUMP_MOVE jump;
	const float speed;
};

#endif
