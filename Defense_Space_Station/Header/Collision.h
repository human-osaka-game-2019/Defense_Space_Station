#ifndef Collision_H_
#define Collision_H_


class JudgeCollision
{
public:

	bool RectCollsion(
		float FirstRectX,float FirstRectY,
		int FirstRectWhith, int FirstRectHight,
		float SecondRectX, float SecondRectY,
		int SecondRectWhith, int ScondRectHight);

	bool AirBloackCollsion(
		float FirstRectX, float FirstRectY,
		int FirstRectWhith, int FirstRectHight,
		float SecondRectX, float SecondRectY,
		int SecondRectWhith, int ScondRectHight,
		int PastPosY);

private:

};

#endif // !Collision_H_