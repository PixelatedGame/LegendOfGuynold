#include "gui.h"
#include "globals.h"

gui::gui(Entity *hero){
	rect_zen_logo = { DISPLAY_WIDTH - 250, DISPLAY_HEIGHT - 50, 50, 50 };
	rect_live_logo = { 50, DISPLAY_HEIGHT - 50, 50, 50 };
	rect_zen_bar = { DISPLAY_WIDTH - 250, DISPLAY_HEIGHT - 30, 200, 15 };
	rect_live_bar = { 50, DISPLAY_HEIGHT - 30, 200, 15 };

	rect_zen = { 80, DISPLAY_HEIGHT - 27, 22, 5 };
	rect_live = { DISPLAY_WIDTH - 220, DISPLAY_HEIGHT - 27, 21, 5 };

	current_hero = hero;
	
	texture_live_bar = loadTexture(resPath + "bar_live.png", renderer);
	texture_zen_bar = loadTexture(resPath + "bar_zen.png", renderer);

	texture_zen = loadTexture(resPath + "state_zen.png", renderer);
	texture_live = loadTexture(resPath + "state_live.png", renderer);
	texture_zen_logo = loadTexture(resPath + "logo_zen.png", renderer);
	texture_live_logo = loadTexture(resPath + "logo_live.png", renderer);
}

void gui::render(){
	rect_zen = { DISPLAY_WIDTH - 220, DISPLAY_HEIGHT - 27, calculate_zen(), 5 };
	rect_live = { 80, DISPLAY_HEIGHT - 27, calculate_live(), 5 };

	renderTexture(texture_zen_bar, renderer, rect_zen_bar, NULL);
	renderTexture(texture_live_bar, renderer, rect_live_bar, NULL);

	renderTexture(texture_zen, renderer, rect_zen, NULL);
	renderTexture(texture_live, renderer, rect_live, NULL);
	renderTexture(texture_zen_logo, renderer, rect_zen_logo, NULL);
	renderTexture(texture_live_logo, renderer, rect_live_logo, NULL);

	current_hero->add_live(1);
	current_hero->add_zen(1);

}

int gui::calculate_live(){
	return MIN_BAR + (current_hero->get_live() * (MAX_BAR - MIN_BAR)/100);
}

int gui::calculate_zen(){
	return MIN_BAR + (current_hero->get_zen() * (MAX_BAR - MIN_BAR)/100);
}