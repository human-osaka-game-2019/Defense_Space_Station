#include "../Header/Animation.h"

namespace Anime {

	void Animation(AnimeData* data,float max) {
		data->FrameCount++;
		if (data->FrameCount == data->TargetValue)
		{

			if (data->Tu >= max)
			{

				data->Tu = 0.0f;
			}
			else {

				data->Tu += data->Tw;
			}
				data->FrameCount = 0;
			


		}
	}
}