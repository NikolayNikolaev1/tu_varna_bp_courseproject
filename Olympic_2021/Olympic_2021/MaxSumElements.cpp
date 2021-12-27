#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int MaxSumElements() {
	vector<int> elements_sums;
	int elements_count, current_element;
	int sum = 0;
	int positive_sum = 0;
	int negative_sum = 0;
	bool has_positive_numbers = false;
	cin >> elements_count;

	while (elements_count--) {
		cin >> current_element;
		// Skip negative numbers at the input start.
		if (sum == 0) {
			negative_sum += current_element; // Saves the negative sum in case there are no positive numbers in the input.

			if (current_element <= 0) {
				continue;
			}
		}
		// Adds the current input to the sum, when the negative numbers sum are less than the positive numbers sum.
		sum += current_element;

		if (current_element > 0) {
			has_positive_numbers = true;
			positive_sum = sum;
		}

		if (current_element < 0 && positive_sum != 0) {
			elements_sums.push_back(positive_sum);
			positive_sum = 0;
		}

		if (sum < 0) {
			sum = 0;
		}
	}

	if (has_positive_numbers) {
		// Sum value is zero when there are only negative numbers.
		elements_sums.push_back(sum);
	}

	elements_sums.push_back(negative_sum);

	cout << *max_element(elements_sums.begin(), elements_sums.end());

	return 0;
}
