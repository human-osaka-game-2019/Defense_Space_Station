#include "../Header/Collision.h"

/*
	�������Ă��邩�̔���
	�������Ă����ꍇTRUE��Ԃ��B
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
	�������Ă��邩�̔���

	PastPosY�ɂ�60����1�b�O��Y���W������B

	60����1�b�O��Y���W��
	���������ꍇFALSE�i�������Ă��Ȃ��j��Ԃ��B

	60����1�b�O��Y���W��
	�ゾ�����ꍇTRUE�i�������Ă���j��Ԃ��B
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