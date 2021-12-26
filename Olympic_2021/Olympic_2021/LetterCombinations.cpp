#include <iostream>

using namespace std;
const char FIRST_CAPITAL_LETTER_ASCII = 65; // 'A'

void printNext(int start_index, int end_index, int skip_index);
int Combinations() {
	int letters_count, combinations_count;
	cin >> letters_count >> combinations_count;

	// First letters.
	for (int i = 0; i <= letters_count - combinations_count; i++) {
		printNext(i, combinations_count + i, -1);
	}

	return 0;
}

void printNext(int start_index, int end_index, int skip_index) {
	for (int i = start_index; i < end_index; i++) {
		if (i == skip_index) {
			end_index++;
			continue;
		}

		cout << char(FIRST_CAPITAL_LETTER_ASCII + i);
	}

	cout << endl;

	printNext(start_index, end_index++, skip_index++);
}