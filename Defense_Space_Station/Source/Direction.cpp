#include"../Header/Direction.h"

int Direction::GetDirection()
{

	return this->Dir;

}

void Direction::SetDiection(int Direction)
{

	this->Dir = Direction;

}

Direction::Direction() : Dir(0)
{



}
Direction::~Direction()
{



}