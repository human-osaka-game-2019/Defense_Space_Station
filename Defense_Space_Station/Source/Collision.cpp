?�#include "../Header/Collision.h"


namespace Collision 
{
	/*
		&&
		FirstRectX<=SecondRectX+SecondRectWhith)
		if (FirstRectY + FirstRectHight >= SecondRectHight
		�������Ă��邩�̔���
		�������Ă����ꍇTRUE��Ԃ��B
		?�?�?�?�?�?�?�Ă�?�邩?�̔�?�?�
		?�?�?�?�?�?�?�Ă�?�?�?�ꍇTRUE?�?�?�Ԃ�?�B
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
	�������Ă��邩�̔���
		�������Ă��邩�̔���
		?�?�?�?�?�?�?�Ă�?�邩?�̔�?�?�

	PastPosY�ɂ�60����1�b�O��Y���W������B
		PreviousPos�ɂ�1�t���[���O��Y���W������B
		PreviousPos?�ɂ�1?�t?�?�?�[?�?�?�O?�?�Y?�?�?�W?�?�?�?�?�?�?�?�?�B

	60����1�b�O��Y���W��
	���������ꍇFALSE�i�������Ă��Ȃ��j��Ԃ��B
		1�t���[���O��Y���W��
		���������ꍇFALSE�i�������Ă��Ȃ��j��Ԃ��B
		1?�t?�?�?�[?�?�?�O?�?�Y?�?�?�W?�?�
		?�?�?�?�?�?�?�?�?�ꍇFALSE?�i?�?�?�?�?�?�?�Ă�?�Ȃ�?�j?�?�?�Ԃ�?�B

	60����1�b�O��Y���W��
	�ゾ�����ꍇTRUE�i�������Ă���j��Ԃ��B
*/
bool JudgeCollision::AirBloackCollion(
	float FirstRectX, float FirstRectY,
	int FirstRectWhith, int FirstRectHight,
	float SecondRectX, float SecondRectY,
	int SecondRectWhith, int SecondRectHight,
	int PastPosY) 
{
		1�t���[���O��Y���W��
		�ゾ�����ꍇTRUE�i�������Ă���j��Ԃ��B
		1?�t?�?�?�[?�?�?�O?�?�Y?�?�?�W?�?�
		?�ゾ?�?�?�?�?�ꍇTRUE?�i?�?�?�?�?�?�?�Ă�?�?�?�j?�?�?�Ԃ�?�B
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