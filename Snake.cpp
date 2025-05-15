#include"Snake.h"

Snake::Snake() {
	snake_frame_.x = 0;
	snake_frame_.y = 0;
	snake_frame_.w = 0;
	snake_frame_.h = 0;

	x_pos_ = TILE * TILE / 2;
	y_pos_ = TILE * TILE / 2;
	pre_x_ = 0;
	pre_y_ = 0;
	tail_length_ = 0;

	up = false;
	down = false;
	right = false;
	left = false;
}
Snake::~Snake() {}

void Snake::renderSnake(SDL_Renderer* renderer) {
	snake_frame_.w = TILE;
	snake_frame_.h = TILE;
	// Draw Tail
	for (int i = 0; i < tail_length_; i++)
	{
		snake_frame_.x = tail_x_[i];
		snake_frame_.y = tail_y_[i];
		if (i % 2 == 0) {
			SDL_SetRenderDrawColor(renderer, 131, 121, 94, 255);
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		}
		SDL_RenderFillRect(renderer, &snake_frame_);
	}
	//Draw Head
	snake_frame_.x = x_pos_;
	snake_frame_.y = y_pos_;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &snake_frame_);
}

void Snake::HandleInput(SDL_Event e) {
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return;
		}
		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym)
			{
			case SDLK_LEFT:
				if (!right) {
					right = false;
					left = true;
					up = false;
					down = false;
				}
				break;
			case SDLK_RIGHT:
				if (!left) {
					right = true;
					left = false;
					up = false;
					down = false;
				}
				break;
			case SDLK_UP:
				if (!down) {
					right = false;
					left = false;
					up = true;
					down = false;
				}
				break;
			case SDLK_DOWN:
				if (!up) {
					right = false;
					left = false;
					up = false;
					down = true;
				}
				break;
			case SDLK_ESCAPE:
				exit(0);
			default:
				break;
			}
		}

	}
	pre_x_ = x_pos_;
	pre_y_ = y_pos_;
	if (up) {
		y_pos_ -= TILE;
	}
	else if (down) {
		y_pos_ += TILE;
	}
	else if (right) {
		x_pos_ += TILE;
	}
	else if (left) {
		x_pos_ -= TILE;
	}
}

void Snake::UpdateTail() {
	// cap nhat kich co khi collid
	if (tail_x_.size() != tail_length_) {
		tail_x_.push_back(pre_x_);
		tail_y_.push_back(pre_y_);
	}
	//noi duoi
	for (int i = 1; i < tail_length_; i++) {
		tail_x_[i - 1] = tail_x_[i];
		tail_y_[i - 1] = tail_y_[i];
	}
	if (tail_length_ > 0) {
		tail_x_[tail_length_ - 1] = pre_x_;
		tail_y_[tail_length_ - 1] = pre_y_;
	}
	if (x_pos_ < 0) {
		x_pos_ = TILE * TILE;
	}
	else if (x_pos_ > TILE * TILE - TILE) {
		x_pos_ = 0;
	}
	if (y_pos_ < 0) {
		y_pos_ = TILE * TILE;
	}
	else if (y_pos_ > TILE * TILE - TILE) {
		y_pos_ = 0;
	}
}
bool Snake::CheckGameOver() {
	bool check = false;
	for (int i = 0; i < tail_length_; i++) {
		if (x_pos_ == tail_x_[i] && y_pos_ == tail_y_[i]) {
			check = true;
		}
	}
	return check;
}
bool Snake::CheckWin() {
	return (tail_length_ >= 576);
}
void Snake::NewGame() {
	x_pos_ = TILE * TILE / 2;
	y_pos_ = TILE * TILE / 2;
	tail_length_ = 0;
	tail_x_.clear();
	tail_y_.clear();
	up = false;
	down = false;
	right = false;
	left = false;
}
pair<int, int> Snake::SpawnFood() {
	bool check = true;
	srand(time(0));
	int food_x = TILE * (rand() % TILE);
	int food_y = TILE * (rand() % TILE);
	pair<int, int> food_locate;
	for (int i = 0; i < tail_length_; i++) {
		if ((food_x == tail_x_[i] && food_y == tail_y_[i]) || (food_x == x_pos_ && food_y == y_pos_)) {
			check = false;
		}
	}
	if (!check) {
		food_locate = make_pair(-1000, -1000);
	}
	else {
		food_locate = make_pair(food_x, food_y);
	}
	return food_locate;
}
void Snake::IncreaseTailLength() {
	tail_length_++;
}