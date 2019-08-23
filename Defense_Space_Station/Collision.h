#ifndef Collision_H_
#define Collision_H_


class JudgeCollision
{
public:

	bool RectCollion(
		float FirstRectX,float FirstRectY,
		int FirstRectWhith, int FirstRectHight,
		float SecondRectX, float SecondRectY,
		int SecondRectWhith, int ScondRectHight);

	bool AirBloackCollion(
		float FirstRectX, float FirstRectY,
		int FirstRectWhith, int FirstRectHight,
		float SecondRectX, float SecondRectY,
		int SecondRectWhith, int ScondRectHight,
		int PastPosY);

private:

};

#endif // !Collision_H_