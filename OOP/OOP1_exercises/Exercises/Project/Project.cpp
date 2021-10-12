#include <iostream>
#define MAX_NAME_LENGTH 255
#define EGN_LENGTH 11
#define CONTROL_DIGIT_ALGORITHM_DIVIDER 11

using namespace std;

enum  Gender {
	male,
	female,
	unknown
};

struct CPerson {
	char name[MAX_NAME_LENGTH];
	Gender gender;
	char egn[EGN_LENGTH];

	CPerson() {
		SetName("default");
		SetGender(Gender::unknown);
	}

	CPerson(const char* str_name, const Gender enum_gender) {
		SetName(str_name);
		SetGender(enum_gender);
	}

	// Getters
	const char* GetName() const {
		return name;
	}

	const Gender GetGender() const {
		return gender;
	}

	// Setters
	void SetName(const char* str_name) {
		strcpy_s(name, str_name); //copy string
	}

	void SetGender(const Gender enum_gender) {
		gender = enum_gender;
	}

	void SetEGN(const char* str_egn) {
		strcpy_s(egn, str_egn); //copy string
	}

	bool IsValidEGN() const {
		if (sizeof(egn) != 11) {
			// Valid EGN size is always 10 digits.
			return false;
		}

		char genderDigit = egn[8];

		if (genderDigit % 2 == 0 && gender == Gender::female ||
			genderDigit % 2 == 1 && gender == Gender::male) {
			// Valid EGN has even number for male and odd number for female as its 9th digit.
			return false;
		}

		if (CharToInt(egn[9]) != GetControlDigit()) {
			// Valid EGN has a Control Digit as the last digit, that is calculated with a algorithm.
			return false;
		}

		return true;
	}

	const char* GenderToString() const {
		// Converts teh given gender enum to a string value and returns it.
		switch (gender) {
		case Gender::male:
			return "male";
		case Gender::female:
			return "female";
		default:
			return "unknown";
		}
	}

	int GetControlDigit() const {
		// Algorithm returns the Control Digit, which is the last digit of the EGN.
		int sum = 0;

		for (int i = 0; i < sizeof(egn) - 2; i++) {
			// Get the sum of the multiplication of each digit with its position weight.
			sum += CharToInt(egn[i]) * GetEgnPositionWeight(i);
		}

		// The control digit is the sum modul of 11, when it is less than 10, else it is 0.
		if (sum % CONTROL_DIGIT_ALGORITHM_DIVIDER <= 9) {
			return sum % CONTROL_DIGIT_ALGORITHM_DIVIDER;
		}

		return 0;
	}

	int CharToInt(char digit) const {
		return (int)digit - '0';
	}

	int GetEgnPositionWeight(int egn_position) const {
		// Returns egn weight based on the egn digit position.
		switch (egn_position) {
		case 0:
			return 2;
		case 1:
			return 4;
		case 2:
			return 8;
		case 3:
			return 5;
		case 4:
			return 10;
		case 5:
			return 9;
		case 6:
			return 7;
		case 7:
			return 3;
		case 8:
			return 6;
			break;
		}
	}
};

int main() {
	CPerson* default_person = new CPerson();
	cout << default_person->name << " " << default_person->GenderToString() << endl;
	delete default_person;

	CPerson* person = new CPerson("tester", Gender::male);
	cout << person->name << " " << person->GenderToString() << endl;

	person->SetEGN("7552010005");
	cout << person->IsValidEGN();

	delete person;

	return 0;
}