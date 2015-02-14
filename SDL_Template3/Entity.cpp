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