#include <cmath>
#include <iostream>

using namespace std;

int Mod4() {
	int input_count;
	cin >> input_count;

	long number, power, result;
	int mod;

	int test;

	while (input_count--) {
		cin >> number >> power >> mod;

		if (number % mod == 0) {
			result = 0;
			cout << result << endl;
			continue;
		}

		number = number % mod;

		for (int i = 1; i < mod; i++) {
			if (pow(number, i) == 1) {
				test = i;
				break;
			}
		}





	}

	return 0;
}

