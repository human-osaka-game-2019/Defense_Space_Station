#include "../Header/Collision.h"


namespace Collision 
{
	/*
		当たっているかの判定
		当たっていた場合TRUEを返す。
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

		PreviousPosには1フレーム前のY座標を入れる。

		1フレーム前のY座標が
		下だった場合FALSE（当たっていない）を返す。

		1フレーム前のY座標が
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
}