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


	void UltUi1(int count, UV* ultuv) {
		
		if (count > 1) {
			ultuv->tu = 200.0f / 2480.0f;
		}

		switch (count)
		{

		case 1:
			ultuv->tu = 200.0f / 2480.0f;

			break;

		case 0:
			ultuv->tu = 260.0f / 2480.0f;

			break;
		}
		
	}

	void UltUi2(int count, UV* ultuv) {

		if (count > 2) {
			ultuv->tu = 200.0f / 2480.0f;
		}

		switch (count)
		{
		case 2:
			ultuv->tu = 200.0f / 2480.0f;

			break;

		case 0:
			ultuv->tu = 260.0f / 2480.0f;

			break;

		}
	}

	void UltUi3(int count, UV* ultuv) {

		if (count > 3) {
			ultuv->tu = 200.0f / 2480.0f;
		}

		switch (count)
		{
		case 3:
			ultuv->tu = 200.0f / 2480.0f;
			
			break;

		case 0:
			ultuv->tu = 260.0f / 2480.0f;

			break;
		}
	}

	void UltUi4(int count, UV* ultuv) {

		if (count > 4) {
			ultuv->tu = 200.0f / 2480.0f;
		}

		switch (count)
		{
		case 4:
			ultuv->tu = 200.0f / 2480.0f;

			break;

		case 0:
			ultuv->tu = 260.0f / 2480.0f;

			break;
		}
	}

	void UltUi5(int count, UV* ultuv) {

		if (count > 5) {
			ultuv->tu = 200.0f / 2480.0f;
		}

		switch (count)
		{
		case 5:
			ultuv->tu = 200.0f / 2480.0f;

			break;

		case 0:
			ultuv->tu = 260.0f / 2480.0f;

			break;

		}
	}

	void UltUi6(int count, UV* ultuv) {

		if (count > 6) {
			ultuv->tu = 200.0f / 2480.0f;
		}

		switch (count)
		{
		case 6:
			ultuv->tu = 200.0f / 2480.0f;

			break;

		case 0:
			ultuv->tu = 260.0f / 2480.0f;

			break;

		}
	}

	//��
	void RemainingUV(int remainingenemy,UV* remainingenemyuv) {
		if(remainingenemy < 10){
			remainingenemyuv->tu = 20 / 2480.0f;
		}
	}

	//�E
	void RemainingUV2(int remainingenemy, UV* remainingenemyuv) {

		if (remainingenemy == 1) {
			remainingenemyuv->tu = 140 / 2480.0f;
		}
		else if (remainingenemy==2) {
			remainingenemyuv->tu = 260 / 2480.0f;
		}

		else if (remainingenemy == 3) {
			remainingenemyuv->tu = 380 / 2480.0f;
		}

		else if (remainingenemy == 4) {
			remainingenemyuv->tu = 500 / 2480.0f;
		}

		else if (remainingenemy == 5) {
			remainingenemyuv->tu = 620 / 2480.0f;
		}

		else if (remainingenemy == 6) {
			remainingenemyuv->tu = 740 / 2480.0f;
		}

		else if (remainingenemy == 7) {
			remainingenemyuv->tu = 860 / 2480.0f;
		}

		else if (remainingenemy == 8) {
			remainingenemyuv->tu = 980 / 2480.0f;
		}

		else if (remainingenemy == 9) {
			remainingenemyuv->tu = 1100 / 2480.0f;
		}

		else if (remainingenemy == 10) {
			remainingenemyuv->tu = 20 / 2480.0f;
		}

		else if (remainingenemy == 0) {
			remainingenemyuv->tu = 20 / 2480.0f;
		}

	}
}