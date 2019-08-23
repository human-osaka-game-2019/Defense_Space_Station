#ifndef VECTOR_H_
#define VECTOR_H_

struct Vec {
	Vec() {
		x = 0.0f;
		y = 0.0f;
	}

	Vec(float x, float y) {
		this->x = x;
		this->y = y;
	}

	float x, y;
};

#endif
