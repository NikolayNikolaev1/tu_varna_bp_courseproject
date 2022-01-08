#include <iostream>

using namespace std;

void LeastCommonMultiple(const int first_num, const int second_num, int& lcm);
int EgyptionFractions() {
	int input_count, current_input, lcm, result;
	cin >> input_count;

	while (input_count--) {
		cin >> current_input;

		for (int i = current_input + 1; i < current_input * 2; i++) {
			lcm = i; // the second number is always bigger than the first number for the lcm function.
			LeastCommonMultiple(current_input, i, lcm);

			result = lcm / current_input - lcm / i;

			if (lcm % result == 0) {
				cout << i << " " << lcm / result << endl;	
			}
		}
	}

	return 0;
}

void LeastCommonMultiple(const int first_num, const int second_num, int& lcm) {
	for (int i = second_num; i < second_num * 2; i++) {
		if (i % first_num == 0 && i % second_num == 0) {
			lcm = i;
			return;
		}
	}

	lcm = first_num * second_num;
}
