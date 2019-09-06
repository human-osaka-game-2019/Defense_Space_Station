#include "../Header/Animation.h"
#include "../Header/Player.h"


namespace Anime {
	
	void Animation(AnimeData* data,float max, bool is_loop) {

		data->FrameCount++;

		if (data->FrameCount == data->TargetValue)
		{
			if (!is_loop) {

				 if(max == data->Tu) {

					data->Tu = 0.0f;
					data->flee_frag = false;
				 }
				 else
				if (data->Tu < max)
				{

					data->Tu += data->Tw;
					
				}
			}
			else 
			{
				if (!data->flag)
				{

					if (data->Tu >= max)
					{
						data->flag = true;
					}
					else {

					data->Tu += data->Tw;

					}
					
				}
				else
				{

					if (data->Tu > 0.0f)
					{
					data->Tu -= data->Tw;
					}
					else if (data->Tu == 0.0f)
					{
						data->flag = false;
					}
				}
			}
			data->FrameCount = 0;
		}
	}
}