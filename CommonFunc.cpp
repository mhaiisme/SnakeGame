
#include"CommonFunc.h"

void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window*& window, SDL_Renderer*& renderer,
    int SCREEN_WIDTH, int SCREEN_HEIGHT, const string& WINDOW_TITLE)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_WaitEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}
void DrawBorder(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 0, 0, 0, TILE * TILE);
    SDL_RenderDrawLine(renderer, 0, 0, TILE * TILE, 0);
    SDL_RenderDrawLine(renderer, TILE * TILE, 0, TILE * TILE, TILE * TILE);
    SDL_RenderDrawLine(renderer, 0, TILE * TILE, TILE * TILE, TILE * TILE);
}
bool CheckCollision(int x1, int y1, int x2, int y2) {
    return (x1 == x2 && y1 == y2);
}
