#include "Menu.h"
#include "globals.h"
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
	switch (current_mode)
	{
	case MENU_MAIN:
		max = 2;
		break;
	case MENU_CONTROLEERS:
		max = 5;
	}
	if (upanddown == UP && workpoint[current_mode] > min){
		workpoint[current_mode] = workpoint[current_mode] - 1;
		rect_pointer.y = 216 + workpoint[current_mode] * 35;
	}
	if (upanddown == DOWN && workpoint[current_mode] < max){
		workpoint[current_mode] = workpoint[current_mode] + 1;
		rect_pointer.y = 216 + workpoint[current_mode] * 35;
	}

}

void Menu::start(){
	current_mode = 0;
	for (int i:workpoint)
		workpoint[i] = 0;
	rect_pointer.y = 216 + workpoint[current_mode] * 35;
}
void Menu::render(){
	if (state != 1){
		renderTexture(texture, renderer, rect, &clips[current_mode]);
		renderTexture(texture_pointer, renderer, rect_pointer, NULL);
		SDL_Delay(100);
	}
	
}

void Menu::update(std::map<int, int> &keys, int &work_mode){
	if (work_mode != 1){
		state = work_mode;
		if (keys[SDLK_ESCAPE]){
			state = GAME;
			work_mode = 1;
			this->move(STAY);
			keys[SDLK_ESCAPE] = 0;
		}

		if (keys[SDLK_UP]) {
			this->move(UP);
		}
		else if (keys[SDLK_DOWN]) {
			this->move(DOWN);
		}

		//actions
		if (keys[SDLK_RETURN]){
			switch (current_mode)
			{
			case 0:
				switch (workpoint[current_mode])
				{
				case 1:
					current_mode = 1;
					break;
				case 2:
					state = 1;
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