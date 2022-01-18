#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct elementsInfo {
	int start_index;
	int last_index;
	int element_sum;

	elementsInfo() {
		start_index = -1;
		last_index = -1;
		element_sum = 0;
	};

};


void ElementsMaxSum(const vector<int>& numbers, int& start_index, int& last_index);
void SumRecursion(const vector<int>& numbers, const int& start_index, const int& end_index, const int& min_sum, int& result);
int Sum() {
	vector<int> input_numbers;
	int input_count, numbers_count, current_number, increment, result;
	long double min_sum, numbers_sum, position_sum;
	cin >> input_count;

	while (input_count--) {
		cin >> numbers_count >> min_sum;

		while (numbers_count--) {
			cin >> current_number;
			input_numbers.push_back(current_number);
		}

		SumRecursion(input_numbers, 1, input_numbers.size(), min_sum, result);

		for (int i = 0; i < input_numbers.size(); i++) {
			increment = (i + 1) * result;
			input_numbers[i] = input_numbers[i] + increment;
		}

		int start_index;
		int last_index;
		ElementsMaxSum(input_numbers, start_index, last_index);

		vector<int> new_numbers;

		for (int i = start_index; i <= last_index; i++) {
			// Slice of the numbers, where their sum is the greatest.
			new_numbers.push_back(input_numbers[i]);
		}

		SumRecursion(new_numbers, start_index + 1, last_index + 1, min_sum, result);

		cout << result << endl;
	}

	return 0;
}

void SumRecursion(const vector<int>& numbers, const int& start_index, const int& end_index, const int& min_sum, int& result) {
	int numbers_sum = 0;
	int position_sum = 0;

	for (int i = start_index; i <= end_index; i++) {
		position_sum += i;
	}

	for (int i = 0; i < numbers.size(); i++) {
		numbers_sum += numbers[i];
	}

	// Using
	// min_sum = position_sum * result + numbers_sum
	result = ceil((min_sum - numbers_sum) / position_sum);
}

void ElementsMaxSum(const vector<int>& numbers, int& start_index, int& last_index) {
	vector<elementsInfo> elements;
	elementsInfo element_info = elementsInfo();
	vector<int> elements_sums;
	int current_element;
	int sum = 0;
	int positive_sum = 0;
	int negative_sum = 0;
	bool has_positive_numbers = false;

	for (int i = 0; i < numbers.size(); i++) {
		current_element = numbers[i];
		// Skip negative numbers at the input start.
		if (sum == 0 && current_element <= 0) {
			negative_sum += current_element; // Saves the negative sum in case there are no positive numbers in the input.
			continue;
		}
		// Adds the current input to the sum, when the negative numbers sum are less than the positive numbers sum.
		sum += current_element;

		if (current_element > 0) {
			if (element_info.start_index == -1) {
				element_info.start_index = i;
			}

			has_positive_numbers = true;
			positive_sum = sum;
		}

		if (current_element < 0 && positive_sum != 0) {
			element_info.last_index = i - 1;
			element_info.element_sum = positive_sum;
			elements.push_back(element_info);
			element_info = elementsInfo();
			//elements_sums.push_back(positive_sum);
			positive_sum = 0;
		}

		if (sum < 0) {
			sum = 0;
		}
	}

	if (has_positive_numbers) {
		// Sum value is zero when there are only negative numbers.
		//elements_sums.push_back(sum);
		element_info.last_index = numbers.size() - 1;
		element_info.element_sum = sum;
		elements.push_back(element_info);
	}

	elements_sums.push_back(negative_sum);

	cout << *max_element(elements_sums.begin(), elements_sums.end());

	//*max_element(elements.begin(), elements.end());

	int current_sum;
	int max_sum = 0;

	for (int i = 0; i < elements.size(); i++) {
		current_sum = elements[i].element_sum;

		if (current_sum >= max_sum) {
			max_sum = current_sum;
			start_index = elements[i].start_index;
			last_index = elements[i].last_index;
		}
	}
}
