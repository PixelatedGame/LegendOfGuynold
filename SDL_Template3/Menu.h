#pragma once
#ifndef MENU_H
#define MENU_H


#include <SDL.h>
#include <string>
#include <map>
#include "texture.h"
#include "res_path.h"
#include "globals.h"

class Menu{
	
public:
	enum mode {MENU_MAIN=0, MENU_CONTROLEERS, MENU_VIDEO, MENU_SOUNDS};
	enum state {MENU, GAME};
	enum upanddown { STAY=0, UP, DOWN };
	int current_mode=MENU_MAIN,state,workpoint[3];  //workpoint 0 indicate menu mode, 1 indicate game / state indicate where is the pointer in each mode
	SDL_Rect rect;
	SDL_Rect rect_pointer;
	SDL_Rect clips[3] = {};
	SDL_Rect clips_pointer;
	SDL_Texture * texture;
	SDL_Texture * texture_pointer;
	Menu();
	void render();
	void start();
	void move(int upanddown);
	void update(std::map<int,int> &keys, int &mode);

};

#endif MENU_H