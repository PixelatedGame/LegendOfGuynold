#include "attack.h"
#include "globals.h"


Attack::Attack(int x_location, int y_location, int x_speed, int y_speed, int couse_dammadge, std::string attack_file) : \
Sprite(x_location-10, y_location-10, 20, 20, attack_file) {
	ax = x_speed;
	ay = y_speed;
	dammage = couse_dammadge;
	this->move(ax, ay);
	rect = { x_location, y_location, 200, 200 };
	texture = loadTexture(resPath + "attack.png", renderer);
}

void Attack::render(){
	move(ax, ay);
	renderTexture(texture, renderer, rect, NULL);
}
