#pragma once
#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>

class location{
	std::pair<int, int> xy;
public:
	

	location(); 
	location(int set_x, int set_y);

	void set_x(int set_x);
	void set_y(int set_y);
	void set_xy(int set_x, int set_y);
	int get_x();
	int get_y();
	std::pair<int, int> get_xy();

};

#endif