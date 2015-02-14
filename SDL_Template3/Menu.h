#pragma once
#ifndef MENU_H
#define MENU_H


#include <SDL.h>
#include <string>
#include <map>
#include <vector>


class Menu{
	
public:
	int mode=0,state[3],workpoint;  //workpoint 0 indicate menu mode, 1 indicate game / state indicate where is the pointer in each mode
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