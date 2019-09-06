#include "../Header/UserInterface.h"

namespace UserInterface
{
	void HpUi1(int hpcount, UV* hpuv) {
		switch (hpcount)
		{
		case 11:

			hpuv->tu = 80.0f / 2480.0f;

			break;

		case 10:

			hpuv->tu = 140.0f / 2480.0f;

			break;
		}
	}

	void HpUi2(int hpcount, UV * hpuv) {
		switch (hpcount)
		{
		case 9:

			hpuv->tu = 80.0f / 2480.0f;

			break;

		case 8:

			hpuv->tu = 140.0f / 2480.0f;

		break;

			}
		}

	void HpUi3(int hpcount, UV* hpuv) {
		switch (hpcount) {
			
		case 7:

			hpuv->tu = 80.0f / 2480.0f;

			break;

		case 6:

			hpuv->tu = 140.0f / 2480.0f;

			break;

			}
		}

	void HpUi4(int hpcount, UV * hpuv){
		switch (hpcount){
		case 5:

			hpuv->tu = 80.0f / 2480.0f;

			break;

		case 4:

			hpuv->tu = 140.0f / 2480.0f;

			break;

		}
	}

	void HpUi5(int hpcount, UV* hpuv) {
		switch (hpcount) {
		case 3:

			hpuv->tu = 80.0f / 2480.0f;

			break;

		case 2:

			hpuv->tu = 140.0f / 2480.0f;

			break;

		}
	}

	void HpUi6(int hpcount, UV* hpuv) {
		switch (hpcount) {
		case 1:

			hpuv->tu = 80.0f / 2480.0f;

			break;

		case 0:

			hpuv->tu = 140.0f / 2480.0f;

			break;

		}
	}

}