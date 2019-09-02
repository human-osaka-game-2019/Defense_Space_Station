#include <math.h>

#include "../Header/Collision.h"


namespace Collision 
{
	/*
		&&
		FirstRectX<=SecondRectX+SecondRectWhith)
		if (FirstRectY + FirstRectHight >= SecondRectHight
		当たっているかの判定
		当たっていた場合TRUEを返す。
		?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽﾄゑｿｽ?ｽ驍ｩ?ｽﾌ費ｿｽ?ｽ?ｽ
		?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽﾄゑｿｽ?ｽ?ｽ?ｽ鼾ⅠRUE?ｽ?ｽ?ｽﾔゑｿｽ?ｽB
	*/
	bool SquareCollision(
		const Vec& pos1, const Size& size1,
		const Vec& pos2, const Size& size2)
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
		当たっているかの判定
		?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽﾄゑｿｽ?ｽ驍ｩ?ｽﾌ費ｿｽ?ｽ?ｽ

	PastPosYには60分の1秒前のY座標を入れる。
		PreviousPosには1フレーム前のY座標を入れる。
		PreviousPos?ｽﾉゑｿｽ1?ｽt?ｽ?ｽ?ｽ[?ｽ?ｽ?ｽO?ｽ?ｽY?ｽ?ｽ?ｽW?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽB

	60分の1秒前のY座標が
	下だった場合FALSE（当たっていない）を返す。
		1フレーム前のY座標が
		下だった場合FALSE（当たっていない）を返す。
		1?ｽt?ｽ?ｽ?ｽ[?ｽ?ｽ?ｽO?ｽ?ｽY?ｽ?ｽ?ｽW?ｽ?ｽ
		?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ鼾⑦ALSE?ｽi?ｽ?ｽ?ｽ?ｽ?ｽ?ｽ?ｽﾄゑｿｽ?ｽﾈゑｿｽ?ｽj?ｽ?ｽ?ｽﾔゑｿｽ?ｽB

	60分の1秒前のY座標が
	上だった場合TRUE（当たっている）を返す。
*/

	bool AirBloackCollion(
		const Vec& pos1, const Size& size1,
		const Vec& pos2, const Size& size2,
		const Vec& PreviousPos1)
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
		Vec& pos1, const float radius1,
		Vec& pos2, const float radius2
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