#ifndef UserInterface_H_
#define UserInterface_H_

#include<string>
#include"Vector.h"
#include"Size.h"

namespace UserInterface
{
	struct UV {
		float tu;
		float tv;
		float tw;
		float th;
	};

	void HpUi(int hpcount, UV*);

}

#endif // !UserInterface_H
