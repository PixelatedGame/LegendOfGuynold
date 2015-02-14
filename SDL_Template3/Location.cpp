#include "Location.h"

location::location(){
	set_xy(0, 0);
}

location::location(int set_x, int set_y){
	set_xy(set_x, set_y);
}

void location::set_x(int set_x){
	xy.first = set_x;
}

void location::set_y(int set_y){ 
	xy.second = set_y; 
}

void location::set_xy(int set_x, int set_y) {
	xy.first = set_x; 
	xy.second = set_y; 
}

int location::get_x() {
	return xy.first;
}
int location::get_y() {
	return xy.second; 
}
std::pair<int, int> location::get_xy() {
	return xy;
}