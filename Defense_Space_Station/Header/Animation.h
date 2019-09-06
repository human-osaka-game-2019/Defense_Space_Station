#ifndef _ANIMATION_
#define _ANIMATION_

#define TextureMax 8

#define _1F 1
#define _2F 2
#define _4F 4
#define _5F 5
#define _6F 6
#define _7F 7
#define _8F 8
#define _10F 10
#define _15F 15
#define _20F 20
#define _30F 30


/*
@param [in/out] Tu �e�N�X�`��x���W
@param [in/out] Tw �e�N�X�`���ꖇ�̉���
@param [in] FrameCount �t���[���J�E���g
@param [in] TargetValue �؂�ւ��̃^�C�~���O
*/

struct AnimeData
{
	float Tu;
	float Tw;
	int FrameCount;
	int TargetValue;
	bool flag;
	bool flee_frag;
};

namespace Anime
{
void Animation(AnimeData* data, float max, bool is_loop);

}

#endif //_ANIMATION_
