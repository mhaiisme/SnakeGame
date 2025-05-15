
#ifndef OBJECT_H_
#define OBJECT_H_
#include"CommonFunc.h"
class Object
{
public:
	Object();
	~Object();
	bool LoadImg(string path, SDL_Renderer* renderer);
	void RenderBackGround(SDL_Renderer* renderer);
	void Free();
protected:
	SDL_Texture* text_;
	SDL_Rect rect_;
};
#endif // !OBJECT_H_
#pragma once
