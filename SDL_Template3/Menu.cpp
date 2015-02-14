#include "Menu.h"

Menu::Menu(){

	rect = { 100, 100, 400, 400 };
	rect_pointer = { 140, 216, 20, 20 };
	texture = loadTexture(resPath + "menu.png", renderer);
	texture_pointer = loadTexture(resPath + "pointer.png", renderer);
	for (int i = 0; i < 3; i++){
		clips[i].x = 400 * i;
		clips[i].y = 0;
		clips[i].h = 400;
		clips[i].w = 400;

	}
}

void Menu::move(int upanddown){
	int min=0, max;
	switch (mode)
	{
	case 0:
		max = 2;
		break;
	case 1:
		max = 5;
	}
	if (upanddown == 1 && state[mode] > min){
		state[mode] = state[mode] - 1;
		rect_pointer.y = 216 + state[mode] * 35;
	}
	if (upanddown == 2 && state[mode] < max){
		state[mode] = state[mode] + 1;
		rect_pointer.y = 216 + state[mode] * 35;
	}

}

void Menu::start(){
	mode = 0;
	for (int i:state)
		state[i] = 0;
	rect_pointer.y = 216 + state[mode] * 35;
}
void Menu::render(){
	if (workpoint != 1){
		renderTexture(texture, renderer, rect, &clips[mode]);
		renderTexture(texture_pointer, renderer, rect_pointer, NULL);
		SDL_Delay(100);
	}
	
}

void Menu::update(std::map<int, int> &keys, int &work_mode){
	if (work_mode != 1){
		workpoint = work_mode;
		if (keys[SDLK_ESCAPE]){
			workpoint = 1;
			work_mode = 1;
			this->move(0);
			keys[SDLK_ESCAPE] = 0;
		}

		if (keys[SDLK_UP]) {
			this->move(1);
		}
		else if (keys[SDLK_DOWN]) {
			this->move(2);
		}

		//actions
		if (keys[SDLK_RETURN]){
			switch (mode)
			{
			case 0:
				switch (state[mode])
				{
				case 1:
					mode = 1;
					break;
				case 2:
					workpoint = 1;
					work_mode = 1;
					this->move(0);
					break;
				default:
					break;
				}
				break;



			case 1:
				break;
			}
		}
	}
}