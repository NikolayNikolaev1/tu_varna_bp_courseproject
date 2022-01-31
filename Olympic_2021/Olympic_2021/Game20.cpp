#include <iostream>
#include <vector>

using namespace std;

class Projectile {
private:
	int x_coordinate_direction;
	int y_coordinate_direction;
	int radius_expansion;

public:
	Projectile() : Projectile(0, 0, 0) { }

	Projectile(const int& x_coordinate, const int& y_coordinate, const int& radius_expansion) {
		this->x_coordinate_direction = x_coordinate;
		this->y_coordinate_direction = y_coordinate;
		this->radius_expansion = radius_expansion;
	}
};

class Ship {
private:
	int x_coordinate_point;
	int y_coordinate_point;
	Projectile projectile_fired;

public:
	Ship() : Ship(0, 0, Projectile()) { }

	Ship(const int& x_point, const int& y_point, const Projectile& projectile_fired) {
		this->x_coordinate_point = x_point;
		this->y_coordinate_point = y_point;
		this->projectile_fired = projectile_fired;
	}

};


int Game20() {
	vector<Ship> ships;
	Ship current_ship;
	Projectile current_projectile;
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

			current_projectile = Projectile(
				current_ship_projectile_x_coordinate,
				current_ship_projectile_y_coordinate,
				current_ship_projectile_expand_units);

			current_ship = Ship(current_ship_x_coordinate, current_ship_y_coordinate, current_projectile);
			ships.push_back(current_ship);
		}

		cin >> first_point_x_coordinate
			>> first_point_y_coordinate
			>> second_point_x_coordinate
			>> second_point_y_coordinate;
	}

	return 0;
}

