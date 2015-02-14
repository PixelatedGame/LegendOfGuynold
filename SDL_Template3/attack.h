#pragma once
#ifndef ATTACK_H
#define ATTACK_H

#include "Location.h"
#include "Sprite.h"


class Attack : public Sprite{
private:
	int ax, ay;
	int dammage;
	SDL_Rect rect;
	SDL_Rect clips[11];
public:
	SDL_Texture * texture;
	Attack(int x_location, int y_location, int x_speed=5, int y_speed=5, int couse_dammadge=50, std::string attack_file = "attack.png"); 
	void render();
};

#endif ATTACK_H