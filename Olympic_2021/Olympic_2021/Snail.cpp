#include <iostream>

using namespace std;

int Snail() {
	int meters_up_per_day;
	int meters_down_per_night;
	int rod_length;
	int days;

	while (cin >> meters_up_per_day >> meters_down_per_night >> rod_length) {
		days = (int)((rod_length - meters_down_per_night - 1) / (meters_up_per_day - meters_down_per_night)) + 1;
		cout << days << endl;
	}

	return 0;
}
