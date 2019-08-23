#ifndef GAME_H_
#define GAME_H_

class GAME {
public:
	GAME();
	~GAME();

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
#endif //GAME_H_
