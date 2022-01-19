#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Stick {
private:
	double first_point_x_coordinate;
	double first_point_y_coordinate;
	double second_point_x_coordinate;
	double second_point_y_coordinate;

public:
	Stick() : Stick(0, 0, 0, 0) { }

	Stick(const double& first_x, const double& first_y, const double& second_x, const double& second_y) {
		this->first_point_x_coordinate = first_x;
		this->first_point_y_coordinate = first_y;
		this->second_point_x_coordinate = second_x;
		this->second_point_y_coordinate = second_y;
	}

	const bool CanIntersect(const Stick& other_stick) const {
		bool is_first_point_clockwise = 
			this->IsPointClockwiseFromStick(other_stick.first_point_x_coordinate, other_stick.first_point_y_coordinate);
		bool is_second_point_clockwise = 
			this->IsPointClockwiseFromStick(other_stick.second_point_x_coordinate, other_stick.second_point_y_coordinate);

		// If both points are clockwise or anticlockwise from current stick, there can not be intersection with given stick.
		return !((is_first_point_clockwise && is_second_point_clockwise) ||
			(!is_first_point_clockwise && !is_second_point_clockwise));
	}

private:
	friend istream& operator>>(istream& from_stream, Stick& stick) {
		return stick.Input(from_stream);
	}

	istream& Input(istream& from_stream) {
		double first_x, first_y, second_x, second_y;
		from_stream >> first_x >> first_y >> second_x >> second_y;

		*this = Stick(first_x, first_y, second_x, second_y);

		return from_stream;
	}

	const bool IsPointClockwiseFromStick(const double& third_point_x_coordinate, const double& third_point_y_coordinate) const {
		// Using Cross Product Formula with third point.
		return (this->second_point_x_coordinate - third_point_x_coordinate) * (this->first_point_y_coordinate - third_point_y_coordinate)
			- (this->first_point_x_coordinate - third_point_x_coordinate) * (this->second_point_y_coordinate - third_point_y_coordinate) > 0;
	}
};

void PlayGame(int& sticks_count);
int Mikado() {
	int sticks_count;
	cin >> sticks_count;

	while (sticks_count != 0) {
		PlayGame(sticks_count);
		cin >> sticks_count;
	}

	return 0;
}

void PlayGame(int& sticks_count) {
	const int sticks_last_index = sticks_count - 1;

	Stick stick, current_stick, other_stick;
	vector<Stick> sticks;
	vector<int> free_sticks_indices;
	int current_index;
	bool has_intersection;

	while (sticks_count--) {
		cin >> stick;
		sticks.push_back(stick);
	}

	for (int i = sticks_last_index; i >= 0; i--) {
		current_index = i + 1;

		if (i == sticks_last_index) {
			// Last thrown stick is always free.
			free_sticks_indices.push_back(current_index);
			continue;
		}

		current_stick = sticks[i];
		has_intersection = false;

		for (int j = sticks_last_index; j > i; j--) {
			other_stick = sticks[j];

			if (current_stick.CanIntersect(other_stick) &&
				other_stick.CanIntersect(current_stick)) {
				has_intersection = true;
				break;
			}
		}

		if (!has_intersection) {
			free_sticks_indices.push_back(current_index);
		}
	}

	stringstream strstream;
	reverse(free_sticks_indices.begin(), free_sticks_indices.end());
	copy(free_sticks_indices.begin(), free_sticks_indices.end(), ostream_iterator<int>(strstream, ", "));
	// Remove last delimeter.
	string output = strstream.str();
	output.resize(output.size() - 2);
	cout << output.c_str() << "." << endl;
}