#ifndef TITLE_H_
#define TITLE_H_

#include "../Header/Main.h"
#include "../Header/Jump.h"
#include "../Header/Vector.h"
#include "../Header/Size.h"

class TITLE {
public:
	TITLE();
	~TITLE();

	void UpdateScene();

private:
	enum STEP {
		LoadStep,
		MainStep,
		ReleaseStep
	};

	STEP step = LoadStep;

	const Vec BackGroundPos = { 0, 0 };
	const Size BackGroundSize = { DISPLAY_WIDTH, DISPLAY_HEIGHT };
	Vec LogoCenterPos = { 924.75, 540 };
	Size LogoSize = { DISPLAY_WIDTH, DISPLAY_HEIGHT };
	Vec TopStartButtonPos = { 0, 0 };
	Vec UnderStartButtonPos = { 0,910 };
	const Size TopStartButtonSize = {DISPLAY_WIDTH, 910};
	const Size UnderStartButtonSize = { DISPLAY_WIDTH, 1080 };

	bool will_big = true;
	float logo_zoom = 1.0f;
	float ZoomSpeed = 0.005f;
	const float MaxZoom = 1.10f;
	const float MinZoom = 0.9f;

	const float JumpAcc = -0.3f;
	float JumpSpeed;

	bool is_Slide = false;

	void Load();
	void Control();
	void Draw();
	void Release();

	void ZoomLogo();
	//void JumpPushEnter();
	void Slide();

};

#endif //TITLE_H_
