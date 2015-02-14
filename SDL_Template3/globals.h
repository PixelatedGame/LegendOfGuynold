#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H


#include <vector>
#include "Sprite.h"

extern std::vector< Sprite * > sprites;
extern std::string resPath;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

enum face_directions {
	DOWN,
	LEFT,
	RIGHT,
	UP

};


enum {
	DISPLAY_WIDTH = 800
	, DISPLAY_HEIGHT = 600
	, UPDATE_INTERVAL = 1000 / 20
	, HERO_SPEED = 20
};

class location{
	std::pair<int,int> xy;
public:
	void set_x(int set_x){ xy.first = set_x; }
	void set_y(int set_y){ xy.second = set_y; }
	void set_xy(int set_x, int set_y) { xy.first = set_x; xy.second = set_y; }
	int get_x() { return xy.first; }
	int get_y() { return xy.second; }
	std::pair<int, int> get_xy() { return xy; }
	
};
#endif 