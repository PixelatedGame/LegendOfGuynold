
#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>
#include <vector>
#include "texture.h"




class Sprite {
private:
	int direction = 0;
	int iW = 32, iH = 48;
	int current_clip = 0;
	
	
	SDL_Rect clips[16];
	SDL_Texture * texture;
	void moveAnimation(int new_direction);
	void parseSprite(int ax, int ay, int aw, int ah, std::string sprite_file);
public:
	SDL_Rect collision_rect;
	SDL_Rect rect;
	void render();
	void update();
	void move(int ax = 0, int ay = 0);

	bool isAbleToMove(int &rect_dimension, int ax);

	bool is_x_in_screen(int ax);

	bool Sprite::CheckCollision(const SDL_Rect &rect1);
	Sprite(int x = 0, int y = 0, int w = 32, int h = 48, std::string sprite_file = "sprite.png");
	void turnAnimation(int new_direction);
};



#endif 