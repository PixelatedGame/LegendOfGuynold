#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "globals.h"
#include "Sprite.h"

class Entity : Sprite{
	int current_lives, current_zen;
	location current_location;
public:
	Entity(location where_starts, int live=1, int zen=0, std::string entity_file = "sprite.png");
	int get_live() { return current_lives; }
	int get_zen() { return current_zen; }
};

#endif ENTITY_H