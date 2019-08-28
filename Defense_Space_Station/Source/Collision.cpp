#include "../Header/Collision.h"

/*
	当たっているかの判定
	当たっていた場合TRUEを返す。
*/
bool JudgeCollision::RectCollsion(
		float FirstRectX, float FirstRectY,
		int FirstRectWhith, int FirstRectHight,
		float SecondRectX, float SecondRectY,
		int SecondRectWhith, int SecondRectHight)
{
	if(FirstRectX+FirstRectWhith>= SecondRectX
		&&
		FirstRectX<=SecondRectX+SecondRectWhith)
		if (FirstRectY + FirstRectHight >= SecondRectHight
			&&
			FirstRectY <= SecondRectY + SecondRectHight)
		{
			return true;
		}
	return false;
}

/*
	当たっているかの判定

	PastPosYには60分の1秒前のY座標を入れる。

	60分の1秒前のY座標が
	下だった場合FALSE（当たっていない）を返す。

	60分の1秒前のY座標が
	上だった場合TRUE（当たっている）を返す。
*/
bool JudgeCollision::AirBloackCollsion(
	float FirstRectX, float FirstRectY,
	int FirstRectWhith, int FirstRectHight,
	float SecondRectX, float SecondRectY,
	int SecondRectWhith, int SecondRectHight,
	int PastPosY) 
{

	if (FirstRectX + FirstRectWhith >= SecondRectX
		&&
		FirstRectX <= SecondRectX + SecondRectWhith)
		if (FirstRectY + FirstRectHight >= SecondRectHight
			&&
			FirstRectY <= SecondRectY + SecondRectHight)
		{
			if (PastPosY > FirstRectX)
			{
				return false;
			}
			else return true;
		}
	return false;

}