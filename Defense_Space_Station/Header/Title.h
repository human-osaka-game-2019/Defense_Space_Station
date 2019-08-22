#ifndef TITLE_H_
#define TITLE_H_

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

	void Load();
	void Control();
	void Draw();
	void Release();

};

#endif //TITLE_H_
