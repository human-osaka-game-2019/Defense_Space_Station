#ifndef GAME_H_
#define GAME_H_

class GAME {
public:
	GAME();
	~GAME();

	void UpdateScene();

private:
	enum STEP {
		Load,
		Main,
		Release
	};

	STEP step = Load;

	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_H_
