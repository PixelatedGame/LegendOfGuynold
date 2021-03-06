#pragma once
#ifndef GUI_H
#define GUI_H

#include <SDL.h>
#include "Entity.h"

class gui{
	int const MAX_BAR = 165;
	int const MIN_BAR = 20;
	SDL_Rect rect_zen_logo;
	SDL_Rect rect_live_logo;
	SDL_Rect rect_zen_bar;
	SDL_Rect rect_live_bar;
	SDL_Rect rect_zen;
	SDL_Rect rect_live;
public:
	location zen_location, live_location;
	Entity *current_hero;
	SDL_Texture * texture_live;
	SDL_Texture * texture_zen;
	SDL_Texture * texture_live_bar;
	SDL_Texture * texture_zen_bar;
	SDL_Texture * texture_live_logo;
	SDL_Texture * texture_zen_logo;
	gui(Entity *hero);
	int calculate_zen();
	int calculate_live();
	void render();
};
#endif