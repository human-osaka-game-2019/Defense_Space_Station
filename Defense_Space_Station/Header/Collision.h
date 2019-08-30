#ifndef Collision_H_
#define Collision_H_

#include"Vector.h"
#include"Size.h"

#define RIGHT_SIDE_SKY_BLOCK_WIDTH 470
#define RIGHT_SIDE_SKY_BLOCK_HEIGHT 100
#define RIGHT_SIDE_SKY_BLOCK_X 1240
#define RIGHT_SIDE_SKY_BLOCK_Y 565

#define LEFT_SIDE_SKY_BLOCK_WIDTH 470
#define LEFT_SIDE_SKY_BLOCK_HEIGHT 100
#define LEFT_SIDE_SKY_BLOCK_X 210
#define LEFT_SIDE_SKY_BLOCK_Y 565

#define GROUND_X 0
#define GROUND_Y 1030
#define GROUND_WIDTH 1920
#define GROUND_HEIGHT 50

class Collision
{
	public:
		bool SquareCollision(
			const Vec& pos1, const Size& size1,
			const Vec& pos2, const Size& size2);

		bool SquareCollision(
			const Vec& pos1, const Size& size1,
			const int pos2X, const int pos2Y,
			const int size2Width, const int size2Height);

		bool OneWayCollision(
			const Vec& pos1, const Size& size1,
			const Vec& pos2, const Size& size2,
			const Vec& PreviousPos);

		bool OneWayCollision(
			const Vec& pos1, const Size& size1,
			const int pos2X, const int pos2Y,
			const int size2Width, const int size2Height,
			const Vec& PreviousPos);

		void GroundColiision(
			Vec& pos1, Size& size1, Vec& PreviousPos);

		void LeftAirBlockCollision(
			Vec& pos1, Size& size1, Vec& PreviousPos);

		void RightAirBlockCollision(
			Vec& pos1, Size& size1, Vec& PreviousPos);

	private:

};
#endif // !Collision_H_