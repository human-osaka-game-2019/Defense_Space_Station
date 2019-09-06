#ifndef Collision_H_
#define Collision_H_

#include"Vector.h"
#include"Size.h"

namespace Collision
{
	const Vec GroundPos = { 0,1030 };
	const Size GroundSize = { 1920, 50 };
	const Vec LeftAirBlockPos = { 250, 530 };
	const Vec RightAirBlockPos = { 1210,530 };
	const Size DrawAirBlockSize = { 470,100 };
	const Vec JudgeLeftAirBlockPos = { 340,530 };
	const Vec JudgeRightAirBlockPos = { 1270, 530 };
	const Size JudgeAirBlockSize = { 310, 0 };
	
	bool SquareCollision(
		Vec pos1, Size size1,
		Vec pos2, Size size2);


	bool AirBlockCollision(
		Vec pos1, Size size1,
		Vec pos2, Size size2,
		Vec PreviousPos1);


	/*
	*@brief 円同士の当たり判定
	*@param [in] 比較対象1の位置(中心の座標)
	*@param [in] 比較対象1の半径
	*@param [in] 比較対象2の位置(中心の座標)
	*@param [in] 比較対象2の半径
	*/
	bool CircleCollision(
		Vec pos1, const float radius1,
		Vec pos2, const float radius2
	);
}
#endif // !Collision_H_