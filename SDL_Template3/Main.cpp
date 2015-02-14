

/*
SDL2 example that allows user to move an object using arrow keys.
This is meant to be used as a convenient single-file starting point for
more complex projects.

Author: Andrew Lim Chong Liang
windrealm.org
*/
#include "Main.h"




class Game {
public:
	Game();
	~Game();
	void start();
	void stop();
	void draw();
	bool CheckCollision(const SDL_Rect &rect1, const SDL_Rect &rect2);
	void fillRect(SDL_Rect* rc, int r, int g, int b);
	void fpsChanged(int fps);
	void onQuit();
	void onKeyDown(SDL_Event* event);
	void onKeyUp(SDL_Event* event);
	void run();
	void update();
private:
	std::map<int, int> keys; // No SDLK_LAST. SDL2 migration guide suggests std::map  
	int frameSkip;
	int running;
	int state = 1;
	Menu * mymenu;
	Sprite * hero;
	Sprite * Enemy;
	
	
};

Game::Game()
	:frameSkip(0), running(0) {
	

	

}

Game::~Game() {
	this->stop();
}


void Game::start() {
	int flags = SDL_WINDOW_SHOWN;
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		return;
	}

	if (SDL_CreateWindowAndRenderer(DISPLAY_WIDTH, DISPLAY_HEIGHT, flags, &window, &renderer)) {
		return;
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return;
	}

	

	resPath = getResourcePath();
	std::cout << "Resource path is: " << resPath << std::endl;

	

	//Mix_FreeChunk(music);

	hero = new Sprite(0, 0);
	Enemy = new Sprite(200, 200);
	mymenu = new Menu();

	this->running = 1;
	run();
}
struct SortByX
{
	bool operator() (Sprite * L, Sprite * R) { return L->rect.y < R->rect.y; }
};

void Game::draw() {
	

	// Clear screen  
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	// Render hero  
	

	std::sort(sprites.begin(), sprites.end(), SortByX());

	for (auto p : sprites)
	{
		p->render();
	}
	if (state == 0)
		mymenu->render();
	// fillRect(&hero->rect, 255, 0, 0);

	
	// fillRect(&Enemy->rect, 255, 255, 0);

	

	SDL_RenderPresent(renderer);
}

void Game::stop() {
	if (NULL != renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	if (NULL != window) {
		SDL_DestroyWindow(window);
		window = NULL;
	}
	SDL_Quit();
}

void Game::fillRect(SDL_Rect* rc, int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, rc);
}

void Game::fpsChanged(int fps) {
	char szFps[128];
	sprintf_s(szFps, "%s: %d FPS", "SDL2 Base C++ - Use Arrow Keys to Move", fps);
	SDL_SetWindowTitle(window, szFps);
}

void Game::onQuit() {
	running = 0;
}

void Game::run() {
	int past = SDL_GetTicks();
	int now = past, pastFps = past;
	int fps = 0, framesSkipped = 0;
	SDL_Event event;
	while (running) {
		int timeElapsed = 0;
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:    onQuit();            break;
			case SDL_KEYDOWN: onKeyDown(&event); break;
			case SDL_KEYUP:   onKeyUp(&event);   break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEMOTION:
				break;
			}
		}
		// update/draw  
		timeElapsed = (now = SDL_GetTicks()) - past;
		if (timeElapsed >= UPDATE_INTERVAL) {
			past = now;
			update();
			if (framesSkipped++ >= frameSkip) {
				draw();
				++fps;
				framesSkipped = 0;
			}
		}
		// fps  
		if (now - pastFps >= 1000) {
			pastFps = now;
			fpsChanged(fps);
			fps = 0;
		}


		//menu 
		mymenu->update(keys, state);

		// sleep?  
		SDL_Delay(1);

	}
}

void Game::update() {
	if (state == 1){
		if ((keys[SDLK_LEFT]) && (keys[SDLK_DOWN])) {
			hero->move(-2, 2);
		}
		else if ((keys[SDLK_RIGHT]) && (keys[SDLK_DOWN])) {
			hero->move(2, 2);
		}
		else if ((keys[SDLK_LEFT]) && (keys[SDLK_UP])) {
			hero->move(-2, -2);
		}
		else if ((keys[SDLK_RIGHT]) && (keys[SDLK_UP])) {
			hero->move(2, -2);
		}
		else if (keys[SDLK_LEFT]) {
			hero->move(-2);
		}
		else if (keys[SDLK_RIGHT]) {
			hero->move(2);
		}
		else if (keys[SDLK_UP]) {
			hero->move(0, -2);
		}
		else if (keys[SDLK_DOWN]) {
			hero->move(0, 2);
		}
		Enemy->update();
		//Enter to menu state:
		if (keys[SDLK_ESCAPE]){
			state = 0;
			mymenu->start();
			mymenu->move(0);
			keys[SDLK_ESCAPE] = 0;
		}
	}
	

}

void Game::onKeyDown(SDL_Event* evt) {
	keys[evt->key.keysym.sym] = 1;
}

void Game::onKeyUp(SDL_Event* evt) {
	keys[evt->key.keysym.sym] = 0;
}

int main(int argc, char** argv){
	Game game;
	game.start();
	return 0;
}