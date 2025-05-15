
#include"Food.h"

Food::Food() {
	food_frame_.x = 0;
	food_frame_.y = 0;
	food_frame_.w = 0;
	food_frame_.h = 0;
	x_pos = TILE;
	y_pos = TILE;
}

Food::~Food() {}

void Food::renderFood(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	food_frame_.w = TILE;
	food_frame_.h = TILE;
	food_frame_.x = x_pos;
	food_frame_.y = y_pos;
	SDL_RenderFillRect(renderer, &food_frame_);
}
