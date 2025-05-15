#include"Text.h"

void DisPlayMenu(SDL_Renderer* renderer, SDL_Event e) {
	SDL_Color Purple = { 128, 0 ,128 };
	SDL_Color Yellow = { 255,255,0 };
	TTF_Font* font = TTF_OpenFont("font.ttf", 30);
	if (font == NULL) {
		cout << "ERROR" << endl;
		return;
	}
	SDL_Surface* menu = TTF_RenderText_Solid(font, (string("MENU")).c_str(), Purple);
	SDL_Texture* menu_text = SDL_CreateTextureFromSurface(renderer, menu);
	SDL_Rect menu_rect;
	menu_rect.w = 500;
	menu_rect.h = 200;
	menu_rect.x = (TILE * TILE - menu_rect.w) / 2;
	menu_rect.y = (TILE * TILE - menu_rect.h) / 2;
	SDL_RenderCopy(renderer, menu_text, NULL, &menu_rect);
	font = TTF_OpenFont("font.ttf", 15);
	SDL_Surface* message = TTF_RenderText_Solid(font, (string("Press Enter Key To Play")).c_str(), Yellow);
	SDL_Texture* message_text = SDL_CreateTextureFromSurface(renderer, message);
	SDL_Rect message_rect;
	message_rect.w = TILE * TILE - 6 * TILE;
	message_rect.h = 100;
	message_rect.x = (TILE * TILE - message_rect.w) / 2;
	message_rect.y = menu_rect.y + menu_rect.h + 50;
	SDL_RenderCopy(renderer, message_text, NULL, &message_rect);
	while (true) {
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit(0);
			}
			if (event.key.keysym.sym == SDLK_RETURN) {
				return;
			}
		}
	}
}
void DisPlayYouWin(SDL_Renderer* renderer, SDL_Event e) {
	SDL_Color Purple = { 128, 0 ,128 };
	SDL_Color Yellow = { 255,255,0 };
	TTF_Font* font = TTF_OpenFont("font.ttf", 30);
	if (font == NULL) {
		cout << "ERROR" << endl;
		return;
	}
	SDL_Surface* menu = TTF_RenderText_Solid(font, (string("CONGRATULATION!!!!")).c_str(), Purple);
	SDL_Texture* menu_text = SDL_CreateTextureFromSurface(renderer, menu);
	SDL_Rect menu_rect;
	menu_rect.w = 500;
	menu_rect.h = 200;
	menu_rect.x = (TILE * TILE - menu_rect.w) / 2;
	menu_rect.y = (TILE * TILE - menu_rect.h) / 2;
	SDL_RenderCopy(renderer, menu_text, NULL, &menu_rect);
	font = TTF_OpenFont("font.ttf", 15);
	SDL_Surface* message = TTF_RenderText_Solid(font, (string("Press Enter Key To Play")).c_str(), Yellow);
	SDL_Texture* message_text = SDL_CreateTextureFromSurface(renderer, message);
	SDL_Rect message_rect;
	message_rect.w = TILE * TILE - 6 * TILE;
	message_rect.h = 100;
	message_rect.x = (TILE * TILE - message_rect.w) / 2;
	message_rect.y = menu_rect.y + menu_rect.h + 50;
	SDL_RenderCopy(renderer, message_text, NULL, &message_rect);
	while (true) {
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
				exit(0);
			}
			if (event.key.keysym.sym == SDLK_RETURN) {
				return;
			}
		}
	}
}
void DisplayGameOver(SDL_Renderer* renderer, SDL_Event e, int tailLength) {
	SDL_Color Purple = { 128, 0 ,128 };
	SDL_Color Yellow = { 255,255,0 };
	SDL_Color White = { 255,255,255 };
	TTF_Font* font = TTF_OpenFont("font.ttf", 20);
	if (font == NULL) {
		cout << "ERROR" << endl;
		return;
	}
	SDL_Surface* score_ = TTF_RenderText_Solid(font, (string("Your score is: ") + to_string(tailLength * 100)).c_str(), White);
	SDL_Texture* tex_score_ = SDL_CreateTextureFromSurface(renderer, score_);
	SDL_Rect score;
	score.w = 250;
	score.h = 100;
	score.x = (TILE * TILE - score.w) / 2;
	score.y = 50;
	SDL_RenderCopy(renderer, tex_score_, NULL, &score);
	font = TTF_OpenFont("font.ttf", 30);
	SDL_Surface* menu = TTF_RenderText_Solid(font, (string("GAME OVER!!!")).c_str(), Purple);
	SDL_Texture* menu_text = SDL_CreateTextureFromSurface(renderer, menu);
	SDL_Rect menu_rect;
	menu_rect.w = 500;
	menu_rect.h = 200;
	menu_rect.x = (TILE * TILE - menu_rect.w) / 2;
	menu_rect.y = (TILE * TILE - menu_rect.h) / 2;
	SDL_RenderCopy(renderer, menu_text, NULL, &menu_rect);
	font = TTF_OpenFont("font.ttf", 15);
	SDL_Surface* message = TTF_RenderText_Solid(font, (string("Press Enter Key To Try Again")).c_str(), Yellow);
	SDL_Texture* message_text = SDL_CreateTextureFromSurface(renderer, message);
	SDL_Rect message_rect;
	message_rect.w = TILE * TILE - 6 * TILE;
	message_rect.h = 100;
	message_rect.x = (TILE * TILE - message_rect.w) / 2;
	message_rect.y = menu_rect.y + menu_rect.h + 50;
	SDL_RenderCopy(renderer, message_text, NULL, &message_rect);
	while (true) {
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
				exit(0);
			}
			if (event.key.keysym.sym == SDLK_RETURN) {
				return;
			}
		}
	}
}
void RenderScrore(SDL_Renderer* renderer, int taillength) {
	SDL_Color White = { 255,255,255 };
	TTF_Font* font = TTF_OpenFont("font.ttf", 10);
	if (font == NULL) {
		cout << "ERROR" << endl;
		return;
	}
	SDL_Surface* score_ = TTF_RenderText_Solid(font, (string("Score: ") + to_string(taillength * 100)).c_str(), White);
	SDL_Texture* tex_score_ = SDL_CreateTextureFromSurface(renderer, score_);
	SDL_Rect score;
	score.w = 200;
	score.h = 30;
	score.x = (TILE * TILE - score.w) / 2;
	score.y = 0;
	SDL_RenderCopy(renderer, tex_score_, NULL, &score);
	TTF_CloseFont(font);
}