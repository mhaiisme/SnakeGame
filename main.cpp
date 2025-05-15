#include"CommonFunc.h"
#include"Snake.h"
#include"Object.h"
#include"Food.h"
#include"Text.h"
Snake p_snake;
Food p_food;
Object p_background;
void TrySpawnFood() {
    pair<int, int> loc_food = p_snake.SpawnFood();
    p_food.setXPOS(loc_food.first);
    p_food.setYPOS(loc_food.second);
    if (p_food.getXPOS() == -1000 && p_food.getYPOS() == -1000) {
        re_spawn = true;
    }
}

int main(int argc, char* argv[]) {
	initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	if (!p_background.LoadImg("BackgroundSnake.jpg", renderer)) {
	cout << "ERROR";
		return 0;
	}
	if (TTF_Init() < 0) {
		cout << "ERROR";
		return 0;
	}
	bool re_spawn = false;
	DisPlayMenu(renderer, event);
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
            p_snake.HandleInput(event);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (re_spawn) {
            TrySpawnFood();
        }

        if (CheckCollision(p_snake.getXPOS(), p_snake.getYPOS(), p_food.getXPOS(), p_food.getYPOS())) {
            p_snake.IncreaseTailLength();
            TrySpawnFood();
        }

        p_snake.UpdateTail();

        if (p_snake.CheckGameOver()) {
            DisplayGameOver(renderer, event, p_snake.getLength());
            p_snake.NewGame();
            TrySpawnFood();
        }

        if (p_snake.CheckWin()) {
            DisPlayYouWin(renderer, event);
            p_snake.NewGame();
            TrySpawnFood();
        }

        p_background.RenderBackGround(renderer);
        p_snake.renderSnake(renderer);
        p_food.renderFood(renderer);
        RenderScrore(renderer, p_snake.getLength());
        DrawBorder(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }

	TTF_Quit();
	waitUntilKeyPressed();
	quitSDL(window, renderer);

	return 0;
}