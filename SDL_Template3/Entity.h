#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "Location.h"
#include "Sprite.h"
#include "attack.h"


class Entity : public Sprite{
private:
	int const MAX_BAR = 100;
	int current_lives, current_zen;
	location *current_location;
	void init(int live, int zen);
public:
	Entity(int x_location, int y_location, int live = 1, int zen = 0, std::string entity_file = "sprite.png");
	Entity(location where_starts, int live=1, int zen=0, std::string entity_file = "sprite.png");

	int get_live();
	int get_zen();
	void add_live(int live);
	void add_zen(int zen);
	void get_hit(int dammage);
	Attack *attack();
	int is_attack();

};

#endif