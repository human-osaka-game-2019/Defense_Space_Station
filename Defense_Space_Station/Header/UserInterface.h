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

	void HpUi1(int hpcount, UV* hpuv);

	void HpUi2(int hpcount, UV* hpuv);

	void HpUi3(int hpcount, UV* hpuv);

	void HpUi4(int hpcount, UV* hpuv);

	void HpUi5(int hpcount, UV* hpuv);

	void HpUi6(int hpcount, UV* hpuv);

	void UltUi1(int count, UV* ultuv);

	void UltUi2(int count, UV* ultuv);

	void UltUi3(int count, UV* ultuv);

	void UltUi4(int count, UV* ultuv);

	void UltUi5(int count, UV* ultuv);

	void UltUi6(int count, UV* ultuv);
}

#endif // !UserInterface_H
