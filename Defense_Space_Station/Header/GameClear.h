#ifndef GAME_CLEAR_H_
#define GAME_CLEAR_H_

class GAME_CLEAR {
public:
	GAME_CLEAR();
	~GAME_CLEAR();

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
