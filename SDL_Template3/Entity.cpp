#include "Entity.h"

Entity::Entity(int x_location, int y_location, int live, int zen, std::string entity_file) : \
Sprite(x_location, y_location, 32, 48, entity_file) {
	init(live, zen);
}


Entity::Entity(location where_starts, int live, int zen, std::string entity_file) : \
Sprite(where_starts.get_x(), where_starts.get_y(), 32, 48, entity_file) {
	
	init(live, zen);
	

}

void Entity::init(int live, int zen){

	current_lives = live;
	current_zen = zen;

}

int Entity::get_live() {
	return current_lives;
}
int Entity::get_zen() {
	return current_zen; 
}

void Entity::add_live(int live){
	current_lives += live;
	if (current_lives > MAX_BAR)
		current_lives = MAX_BAR;
}

void Entity::add_zen(int zen){
	current_zen += zen;
	if (current_zen > MAX_BAR)
		current_zen = MAX_BAR;
}

void Entity::get_hit(int dammage){
	current_lives -= dammage;
}

int Entity::is_attack(){
	if (current_zen < 10)
		return 0;
	else
		if (current_zen < 100){
			current_zen -= 10;
			return 1;
		}
		else{
			current_zen = 0;
			return 2;
		}
}

Attack *Entity::attack(){
	Attack * new_attack=NULL;
	switch (is_attack())
	{
	case 0:
		new_attack= NULL;
	case 1:
		
	case 2:
		new_attack = new Attack(rect.x,rect.y);
		break;
	}
	return new_attack;
}