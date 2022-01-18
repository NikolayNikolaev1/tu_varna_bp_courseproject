#include <iostream>

using namespace std;

int Game20() {
	int input_count, ships_count;
	// Ship variables:
	int current_ship_x_coordinate;
	int current_ship_y_coordinate;
	int current_ship_projectile_x_coordinate;
	int current_ship_projectile_y_coordinate;
	int current_ship_projectile_expand_units;
	// Target points variables:
	int first_point_x_coordinate;
	int first_point_y_coordinate;
	int second_point_x_coordinate;
	int second_point_y_coordinate;

	cin >> input_count;

	while (input_count--) {
		cin >> ships_count;

		while (ships_count--) {
			cin >> current_ship_x_coordinate
				>> current_ship_y_coordinate
				>> current_ship_projectile_x_coordinate
				>> current_ship_projectile_y_coordinate
				>> current_ship_projectile_expand_units;
		}

		cin >> first_point_x_coordinate
			>> first_point_y_coordinate
			>> second_point_x_coordinate
			>> second_point_y_coordinate;
	}

	return 0;
}

