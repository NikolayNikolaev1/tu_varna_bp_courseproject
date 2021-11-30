#include <iostream>

using namespace std;

int Mod4() {
	int input_count;
	cin >> input_count;

	long number, power, result;
	int mod;


	while (input_count--) {
		cin >> number >> power >> mod;

		if (number % mod == 0) {
			result = 0;
		}
	}

	return 0;
}

