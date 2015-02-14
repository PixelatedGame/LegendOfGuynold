#include "gui.h"
#include "globals.h"

gui::gui(Entity *hero){
	rect_zen_logo = { 50, DISPLAY_HEIGHT - 50, 50, 50 };
	rect_live_logo = { DISPLAY_WIDTH - 250, DISPLAY_HEIGHT - 50, 50, 50 };
	rect_zen_bar = { 50, DISPLAY_HEIGHT - 30, 200, 15 };
	rect_live_bar = { DISPLAY_WIDTH - 250, DISPLAY_HEIGHT - 30, 200, 15 };
	rect_zen = { 80, DISPLAY_HEIGHT - 27, 80, 5 };
	rect_live = { DISPLAY_WIDTH - 220, DISPLAY_HEIGHT - 27, 100, 5 };

	current_hero = hero;
	
	texture_live_bar = loadTexture(resPath + "bar_live.png", renderer);
	texture_zen_bar = loadTexture(resPath + "bar_zen.png", renderer);

	texture_zen = loadTexture(resPath + "state_zen.png", renderer);
	texture_live = loadTexture(resPath + "state_live.png", renderer);
	texture_zen_logo = loadTexture(resPath + "logo_zen.png", renderer);
	texture_live_logo = loadTexture(resPath + "logo_live.png", renderer);
}

void gui::render(){
	renderTexture(texture_zen_bar, renderer, rect_zen_bar, NULL);
	renderTexture(texture_live_bar, renderer, rect_live_bar, NULL);

	renderTexture(texture_zen, renderer, rect_zen, NULL);
	renderTexture(texture_live, renderer, rect_live, NULL);
	renderTexture(texture_zen_logo, renderer, rect_zen_logo, NULL);
	renderTexture(texture_live_logo, renderer, rect_live_logo, NULL);

}