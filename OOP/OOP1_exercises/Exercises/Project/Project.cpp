#include <iostream>
#define MAX_NAME_LENGTH 255

using namespace std;

enum  Gender {
	male,
	female,
	unknown
};

struct CPerson {
	char name[MAX_NAME_LENGTH];
	Gender gender;

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
};

const char* GenderToString(const Gender gender);

int main() {
	CPerson* default_person = new CPerson();
	cout << default_person->name << " " << GenderToString(default_person->gender) << endl;

	CPerson* person = new CPerson("tester", Gender::male);
	cout << person->name << " " << GenderToString(person->gender);

	delete default_person;
	delete person;

	return 0;
}

const char* GenderToString(const Gender gender) {
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