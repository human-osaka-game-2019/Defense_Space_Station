#include "../Header/Collision.h"

/*

	矩形と矩形の当たり判定
	当たっていた場合TRUEを返す

*/
bool Collision::SquareCollision (
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

	defineされた値を使うようのオーバーロード

*/
bool Collision::SquareCollision(
	const Vec& pos1, const Size& size1,
	const int pos2X, const int pos2Y,
	const int size2Width, const int size2Height) 
{
	if (pos1.x + size1.width >= pos2X
		&&
		pos1.x <= pos2X + size2Width)
		if (pos1.y + size1.height >= pos2Y
			&&
			pos1.y <= pos2Y + size2Height)
		{
			return true;
		}
	return false;
}

/*

	すり抜け床との当たっているかの判定

	PrevPosには60分の1秒前のY座標を入れる。

	1フレーム前のY座標が
	下だった場合FALSE（当たっていない）を返す。

	1フレーム前のY座標が
	上だった場合TRUE（当たっている）を返す。

*/

bool Collision::OneWayCollision(
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


/*

	defineされた値を使うようのオーバーロード

*/
bool Collision::OneWayCollision(
	const Vec& pos1, const Size& size1,
	const int pos2X, const int pos2Y,
	const int size2Width, const int size2Height,
	const Vec& PreviousPos1)
{

	if (pos1.x + size1.width >= pos2X
		&&
		pos1.x <= pos2X + size2Width)
		if (pos1.y + size1.height >= pos2Y
			&&
			pos1.y <= pos2Y + size2Height)
		{
			if (PreviousPos1.y > pos1.y)
			{
				return false;
			}
			else return true;
		}
	return false;

}

/*

	地面との当たり判定

	もし当たっていた場合１フレーム前のY座標に戻す。

*/
void Collision::GroundColiision(
	Vec& pos1, Size& size1,Vec& PreviousPos1) 
{
	if (SquareCollision(pos1,size1,
		GROUND_X,GROUND_Y,GROUND_WIDTH,GROUND_HEIGHT) == true) 
	{
		pos1.y = PreviousPos1.y;
	}
}


/*

	空中のすり抜け床との当たり判定

	上からしか当たらずもし当たった場合1フレーム前の座標に戻す。

*/
void Collision::LeftAirBlockCollision(
	Vec& pos1, Size& size1, Vec& PreviousPos1)
{
	if (OneWayCollision(pos1, size1,
		LEFT_SIDE_SKY_BLOCK_X, LEFT_SIDE_SKY_BLOCK_Y,
		LEFT_SIDE_SKY_BLOCK_WIDTH, LEFT_SIDE_SKY_BLOCK_HEIGHT,PreviousPos1) == true)
	{
		pos1.y = PreviousPos1.y;
	}
}

void Collision::RightAirBlockCollision(
	Vec& pos1, Size& size1, Vec& PreviousPos1)
{
	if (OneWayCollision(pos1, size1,
		RIGHT_SIDE_SKY_BLOCK_X, RIGHT_SIDE_SKY_BLOCK_Y,
		RIGHT_SIDE_SKY_BLOCK_WIDTH, RIGHT_SIDE_SKY_BLOCK_HEIGHT, PreviousPos1) == true)
	{
		pos1.y = PreviousPos1.y;
	}
}
