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

	void HpUi1(int hpcount, UV*);

	void HpUi2(int hpcount, UV*);

	void HpUi3(int hpcount, UV*);

	void HpUi4(int hpcount, UV*);

	void HpUi5(int hpcount, UV* hpuv);

	void HpUi6(int hpcount, UV* hpuv);
}

#endif // !UserInterface_H
