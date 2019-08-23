#ifndef SIZE_H_
#define SIZE_H_

struct Size {
	Size() {
		width = 0.0f;
		height = 0.0f;
	}

	Size(float width, float height) {
		this->width = width;
		this->height = height;
	}

	float width, height;
};

#endif