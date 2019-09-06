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

		default:
			if (hpcount < 10) {
				hpuv->tu = 140.0f / 2480.0f;
			}

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

		default:
			if (hpcount < 8) {
				hpuv->tu = 140.0f / 2480.0f;
			}

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

		default:
			if (hpcount < 6) {
				hpuv->tu = 140.0f / 2480.0f;
			}

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

		default:
			if (hpcount < 4) {
				hpuv->tu = 140.0f / 2480.0f;
			}

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

		default:
			if (hpcount < 2) {
				hpuv->tu = 140.0f / 2480.0f;
			}

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


	void Ult1(int count, UV* ultuv) {
		switch (count)
		{
		case 1:
			ultuv->tu = 200;
		}
	}

	void Ult2(int count, UV* ultuv) {
		switch (count)
		{
		case 2:
			ultuv->tu = 200;
		}
	}

	void Ult3(int count, UV* ultuv) {
		switch (count)
		{
		case 3:
			ultuv->tu = 200;
		}
	}

	void Ult4(int count, UV* ultuv) {
		switch (count)
		{
		case 4:
			ultuv->tu = 200;
		}
	}

	void Ult5(int count, UV* ultuv) {
		switch (count)
		{
		case 5:
			ultuv->tu = 200;
		}
	}

	void Ult6(int count, UV* ultuv) {
		switch (count)
		{
		case 6:
			ultuv->tu = 200;
		}
	}
}