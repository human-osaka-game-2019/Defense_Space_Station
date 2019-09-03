#include <math.h>

#include "../Header/Collision.h"


namespace Collision 
{
	/*
		当たっているかの判定
		当たっていた場合TRUEを返す。
	*/
	bool SquareCollision(
		Vec pos1, Size size1,
		Vec pos2, Size size2)
	{
		if (pos1.x + size1.width >= pos2.x
			&&
			pos1.x <= pos2.x + size2.width)
			if (pos1.y + size1.height >= pos2.y
				&&
				pos1.y <= pos2.y + size2.height)
			{
				return true;
			}
		return false;
	}

	/*
		当たっているかの判定
		
		PastPosYには60分の1秒前のY座標を入れる。
		PreviousPosには1フレーム前のY座標を入れる。

		1フレーム前のY座標が
		下だった場合FALSE（当たっていない）を返す。
	*/

	bool AirBlockCollision(
		Vec pos1, Size size1,
		Vec pos2, Size size2,
		Vec PreviousPos1)
	{

		if (pos1.x + size1.width >= pos2.x
			&&
			pos1.x <= pos2.x + size2.width)
			if (pos1.y + size1.height >= pos2.y
				&&
				pos1.y <= pos2.y + size2.height)
			{
				if (PreviousPos1.y > pos1.y)
				{
					return false;
				}
				else return true;
			}
		return false;
	}

	bool CircleCollision(
		Vec pos1, float radius1,
		Vec pos2, float radius2
	) {
		float width = (pos2.x - pos1.x) * (pos2.x - pos1.x);
		float height = (pos2.y - pos1.y) * (pos2.y - pos1.y);
		float radius = (radius1 + radius2) * (radius1 + radius2);
		double diff = sqrt((double)width + (double)height);

		if (sqrt(radius) >= diff) {
			return true;
		}
		return false;
	}
}