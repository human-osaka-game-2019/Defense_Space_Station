#ifndef GAME_OVER_H_
#define GAME_OVER_H_

class GAME_OVER {
public:
	GAME_OVER();
	~GAME_OVER();

	void UpdateScene();

private:
	enum STEP {
		LoadStep,
		MainStep,
		ReleaseStep
	};

	STEP step = LoadStep;



	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_CLEAR_H_
