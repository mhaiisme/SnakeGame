#include"Object.h"

Object::Object() {
	text_ = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.h = 0;
	rect_.w = 0;
}
Object::~Object() {
	Free();
}

bool Object::LoadImg(string path, SDL_Renderer* renderer) {
	Free();
	SDL_Texture* new_texture = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());
	if (load_surface != NULL)
	{
		new_texture = SDL_CreateTextureFromSurface(renderer, load_surface);
		if (new_texture != NULL) {
			rect_.w = load_surface->w;
			rect_.h = load_surface->h;
		}
		SDL_FreeSurface(load_surface);
	}
	text_ = new_texture;
	return text_ != NULL;
}
void Object::RenderBackGround(SDL_Renderer* renderer) {
	SDL_Rect quad = { rect_.x, rect_.y, rect_.w, rect_.h };
	SDL_RenderCopy(renderer, text_, NULL, &quad);
}
void Object::Free() {
	if (text_ != NULL) {
		SDL_DestroyTexture(text_);
		text_ = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}