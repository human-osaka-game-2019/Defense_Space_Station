#include "../Header/Collision.h"


namespace Collision 
{
	/*
		�������Ă��邩�̔���
		�������Ă����ꍇTRUE���Ԃ��B
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

		PreviousPos�ɂ�1�t���[���O��Y���W���������B

		1�t���[���O��Y���W��
		���������ꍇFALSE�i�������Ă��Ȃ��j���Ԃ��B

		1�t���[���O��Y���W��
		�ゾ�����ꍇTRUE�i�������Ă����j���Ԃ��B
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