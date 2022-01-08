#include <iostream>

using namespace std;

int Sum() {
	int input_count, numbers_count, current_number;
	long min_sum, numbers_sum, current_sum, result = 0;
	cin >> input_count;

	while (input_count--) {
		numbers_sum = 0;
		current_sum = 0;
		cin >> numbers_count >> min_sum;
		long max_output_result = numbers_count * min_sum; // Not correct way of finding the biggest possible result.

		for (int i = 1; i <= numbers_count; i++) {
			current_sum += i;
		}

		while (numbers_count--) {
			cin >> current_number;
			numbers_sum += current_number;
		}

		if (numbers_sum < 0) {
			for (long i = 1; i <= max_output_result; i++) {
				if (min_sum <= current_sum * i + numbers_sum) {
					result = i;
					break;
				}
			}
		}
		else {
			for (long i = 0; i >= max_output_result * -1; i--) {
				if (min_sum > current_sum * i + numbers_sum) {
					result = i + 1;
					break;
				}
			}
		}

		cout << result << endl;
	}

	return 0;
}
