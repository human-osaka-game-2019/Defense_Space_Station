#include "../Header/UserInterface.h"

namespace UserInterface
{
	void HpUi(int hpcount,UV* hpuv) {
		switch (hpcount)
		{
		case 12:

			hpuv->tu = 20;

			break;

		case 11:

			hpuv->tu = 80;

			break;

		case 10:

			hpuv->tu = 140;

			break;

		case 9:

			hpuv->tu = 20;

			break;

		case 8:

			hpuv->tu = 80;

			break;

		case 7:

			hpuv->tu = 140;

			break;
		case 6:

			hpuv->tu = 20;

			break;

		case 5:

			hpuv->tu = 80;

			break;

		case 4:

			hpuv->tu = 140;

			break;

		case 3:

			hpuv->tu = 20;

			break;

		case 2:

			hpuv->tu = 80;

			break;

		case 1:

			hpuv->tu = 140;

			break;

		}
	}

}