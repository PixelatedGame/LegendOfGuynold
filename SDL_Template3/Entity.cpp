#include "Entity.h"


Entity::Entity(location where_starts, int live, int zen, std::string entity_file) : \
Sprite(where_starts.get_x(), where_starts.get_y(), 32, 48, entity_file) {
	
	current_lives = live;
	current_zen = zen;
	
	

}
