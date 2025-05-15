
#ifndef FOOD_H_
#define FOOD_H_
#include"CommonFunc.h"

class Food {
private:
	SDL_Rect food_frame_;
	int x_pos;
	int y_pos;
public:
	Food();
	~Food();
	void renderFood(SDL_Renderer* renderer);
	void setXPOS(int xpos) { x_pos = xpos; }
	void setYPOS(int ypos) { y_pos = ypos; }
	int getXPOS()  const { return x_pos; }
	int getYPOS()  const { return y_pos; }
};
#endif // 
#pragma once
