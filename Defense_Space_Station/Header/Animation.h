#ifndef _ANIMATION_
#define _ANIMATION_

#define TextureMax 8

#define _4F 4
#define _8F 8
#define _10F 10
#define _15F 15
#define _20F 20
#define _30F 30


/*
@param [in/out] Tu テクスチャx座標
@param [in/out] Tw テクスチャ一枚の横幅
@param [in] FrameCount フレームカウント
@param [in] TargetValue 切り替えのタイミング
*/

struct AnimeData
{
	float Tu;
	float Tw;
	int FrameCount;
	int TargetValue;
	bool flag;
};

namespace Anime
{
void Animation(AnimeData* data, float max, bool is_loop);

}

#endif //_ANIMATION_
