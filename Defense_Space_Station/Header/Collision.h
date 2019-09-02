#ifndef Collision_H_
#define Collision_H_

#include"Vector.h"
#include"Size.h"

#define RIGHT_SIDE_SKY_BLOCK_WIDTH 470
#define RIGHT_SIDE_SKY_BLOCK_HIGHT 100
#define RIGHT_SIDE_SKY_BLOCK_X 1240
#define RIGHT_SIDE_SKY_BLOCK_Y 565

#define LEFT_SIDE_SKY_BLOCK_WIDTH 470
#define LEFT_SIDE_SKY_BLOCK_HIGHT 100
#define LEFT_SIDE_SKY_BLOCK_X 210
#define LEFT_SIDE_SKY_BLOCK_Y 565

#define GROUND_X 0
#define GROUND_Y 1030
#define GROUND_WIDTH 1920
#define GROUND_HEIGHT 50

namespace Collision
{
	const Vec GroundPos = { 0,1030 };
	const Size GroundSize = { 1920, 50 };
	
		bool SquareCollision(
			const Vec& pos1, const Size& size1,
			const Vec& pos2, const Size& size2);


		bool AirBloackCollion(
			const Vec& pos1, const Size& size1,
			const Vec& pos2, const Size& size2,
			const Vec& PreviousPos1);


		/*
		*@brief 円同士の当たり判定
		*@param [in] 比較対象1の位置(中心の座標)
		*@param [in] 比較対象1の半径
		*@param [in] 比較対象2の位置(中心の座標)
		*@param [in] 比較対象2の半径
		*/
		bool CircleCollision(
			Vec& pos1, const float radius1,
			Vec& pos2, const float radius2
		);
}
#endif // !Collision_H_