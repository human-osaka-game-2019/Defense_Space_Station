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

/*

bool CollisionAirBlock(
	FLOAT PlayerPosX, FLOAT PlayerPosY,
	INT PlayerWhith, INT PlayerHight,
	FLOAT EnemyPosX, FLOAT EnemyPosY,
	INT EnemyWhith, INT fEnemy_Hight)
{
	if (PlayerPosX + PlayerWhith >= EnemyPosX
		&&
		PlayerPosX <= EnemyPosX + EnemyWhith)

		if (PlayerPosY + PlayerHight >= EnemyPosY
			&&
			PlayerPosY <= EnemyPosY + fEnemy_Hight)
		{
			if (CurrentSpotY > PlayerPosY)
			{
				return false;
			}
			else return true;
		}
	return false;
}
*/