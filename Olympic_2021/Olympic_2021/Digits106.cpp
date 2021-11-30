#include <iostream>
#include <string>

using namespace std;

int Digits106() {
	long input_count, input_length, digit_multiplier, sum;
	cin >> input_count;
	string current_input;

	while (input_count--) {
		cin >> current_input;
		input_length = current_input.length();
		digit_multiplier = input_length - 1;
		sum = 0;

		for (int i = 0; i < input_length; i++) {
			sum += (current_input[i] - '0') * digit_multiplier;
		}

		cout << sum << endl;
	}

	return 0;
}

