#include <fstream>
#include <iostream>
#include <string>
#define CONTROL_DIGIT_ALGORITHM_DIVIDER 11
#define EGN_LENGTH 10

using namespace std;

enum Gender {
	male,
	female,
	unknown
};

class CAddress {
private:
	string street;
	string zip_code;
	string city;

public:
	CAddress()
		: CAddress("Default Street", "N/A", "Defautl City") { }

	CAddress(const string& street, const string& zip_code, const string& city) {
		this->street = street;
		this->zip_code = zip_code;
		this->city = city;
	}

	CAddress(const CAddress& address)
		: CAddress(address.street, address.zip_code, address.city) { }

	// Getters
	const string GetStreet() const {
		return this->street;
	}

	const string GetZipCode() const {
		return this->zip_code;
	}

	const string GetCity() const {
		return this->city;
	}

	ostream& Output(ostream& to_stream) const {
		// Returns output info of the current address.
		return to_stream << "Street Name: " << this->street << endl
			<< "ZIP Code: " << this->zip_code << endl
			<< "City Name: " << this->city << endl;
	}

	friend ostream& operator<<(ostream& to_stream, const CAddress& address) {
		return address.Output(to_stream);
	}
};

class CPerson {
private:
	string name;
	Gender gender;
	string egn;

public:
	CPerson()
		: CPerson("default", Gender::unknown, "0000000000") { }

	CPerson(const string& name, const Gender& gender)
		: CPerson(name, gender, "0000000000") { }

	CPerson(const string& name, const string& egn)
		: CPerson(name, Gender::unknown, egn) { }

	CPerson(const string& name, const Gender& gender, const string& egn) {
		SetName(name);
		SetGender(gender);
		SetEGN(egn);
	}

	// Getters
	const string GetName() const {
		return this->name;
	}

	const Gender GetGender() const {
		return this->gender;
	}

	const string GetEGN() const {
		return this->egn;
	}

	// Setters
	void SetName(const string& name) {
		this->name = name;
	}

	void SetGender(const Gender& gender) {
		this->gender = gender;
	}

	void SetEGN(const string& egn) {
		if (!this->IsValidEGN(egn)) {
			// EGN Validation using algorithm.
			cout << "EGN is not valid!" << endl;
			return;
		}

		this->egn = egn;
	}

	const string GenderToString() const {
		// Converts the gender enum to a string value and returns it.
		switch (this->gender) {
		case Gender::male:
			return "male";
		case Gender::female:
			return "female";
		default:
			return "unknown";
		}
	}

	ostream& Output(ostream& to_stream) const {
		// Returns output info of the current person.
		return to_stream << "Name: " << this->name << endl
			<< "Gender: " << this->GenderToString() << endl
			<< "EGN: " << this->egn << endl;
	}

	friend ostream& operator<<(ostream& to_stream, const CPerson& person) {
		return person.Output(to_stream);
	}

	const Gender StringToGender(const string& str_gender) const {
		// Converts the given string to a Gender enum and returns it.
		if (str_gender == "male") {
			return Gender::male;
		}

		if (str_gender == "female") {
			return Gender::female;
		}

		return Gender::unknown;
	}

protected:
	int GetAge() const {
		// Get current age based on October 1st 2021.
		int birth_year, birth_month, birth_day, age;

		this->GetYMD(this->egn, birth_year, birth_month, birth_day);

		age = 2021 - birth_year;

		if (birth_month > 10 || 
			(birth_month = 10 && birth_day >= 1))
		{
			age++;
		}

		return age;
	}

	void GetYMD(const string& egn, int& year, int& month, int& day) const {
		// Calculates the year, month and day of birth from the egn using algorithm.
		year = atoi(egn.substr(0, 2).data());// atoit - converts string to int
		month = atoi(egn.substr(2, 2).data());
		day = atoi(egn.substr(4, 2).data());

		if (month <= 12) {
			year += 1900;
		}
		else if (month <= 32) {
			// People born in the 1800s have 20 added to their month.
			year += 1800;
			month -= 20;
		}
		else {
			// People born in the 2000s have 40 added in theyr month.
			year += 2000;
			month -= 40;
		}
	}

	const bool IsValidEGN(const string& egn) const {
		if (egn.length() != EGN_LENGTH) {
			// Valid EGN size is always 10 digits.
			return false;
		}

		char genderDigit = egn[8];

		if (genderDigit % 2 == 0 && gender == Gender::female ||
			genderDigit % 2 == 1 && gender == Gender::male) {
			// Valid EGN has even number for male and odd number for female as its 9th digit.
			return false;
		}

		if (!this->IsControlDigitValid(egn)) {
			// Valid EGN has a Control Digit as the last digit, that is calculated with a algorithm.
			return false;
		}

		return true;
	}

private:
	const int CharToInt(char digit) const {
		return (int)digit - '0';
	}

	const int IsControlDigitValid(const string& egn) const {
		// Algorithm returns the Control Digit, which is the last digit of the EGN.
		int sum = 0;
		int control_digit = CharToInt(egn[9]);

		for (int i = 0; i < EGN_LENGTH - 1; i++) {
			// Get the sum of the multiplication of each digit with its position weight.
			sum += CharToInt(egn[i]) * GetEgnPositionWeight(i);
		}

		// The control digit is the sum modul of 11, when it is less than 10, else it is 0.
		if (sum % CONTROL_DIGIT_ALGORITHM_DIVIDER > 9) {
			// Control digit should be 0.
			return control_digit == '0';
		}

		// Control digit should be the sum modul of 11.
		return sum % CONTROL_DIGIT_ALGORITHM_DIVIDER == control_digit;
	}

	const int GetEgnPositionWeight(int egn_position) const {
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
		}
	}
};

class CStudent : public CPerson {
private:
	string faculty_number;
	CAddress address;

public:
	CStudent()
		: CPerson() {
		this->faculty_number = "N/A";
		this->address = CAddress();
	}

	CStudent(const string& name, const string& egn, const CAddress& address)
		: CPerson(name, egn) {
		this->address = address;
	}

	CStudent(const string& name, const string& egn, const string& faculty_number, const CAddress& address)
		: CPerson(name, egn) {
		this->faculty_number = faculty_number;
		this->address = address;
	}

	// Getters
	const string GetFacultyNumber() const {
		return this->faculty_number;
	}

	const CAddress GetAddress() const {
		return this->address;
	}

	ostream& Output(ostream& to_stream) const {
		// Returns output info of the current person, his address and faculty number.
		CPerson::Output(to_stream);
		this->address.Output(to_stream);

		return to_stream << "Faculty Number: " << this->faculty_number << endl;
	}

	friend ostream& operator<<(ostream& to_stream, const CStudent& student) {
		return student.Output(to_stream);
	}

	friend bool operator==(CStudent& first_student, CStudent& second_sudent) {
		return first_student.GetAge() == second_sudent.GetAge();
	}

	friend bool operator!=(CStudent& first_student, CStudent& second_student) {
		return first_student.GetAge() != second_student.GetAge();
	}

	friend bool operator>=(CStudent& first_student, CStudent& second_student) {
		return first_student.GetAge() >= second_student.GetAge();
	}

	friend bool operator<=(CStudent& first_student, CStudent& second_Student) {
		return first_student.GetAge() <= second_Student.GetAge();
	}

	friend void ConsoleInputEGN(CStudent& student) {
		// Set student EGN from input if valid.
		string egn;

		cout << student << "Enter EGN: ";
		cin >> egn;

		if (student.IsValidEGN(egn)) {
			student.SetEGN(egn);
		}
		else {
			cout << "Invalid EGN!" << endl;
		}
	}
};

void OutputStudentsInFile(CStudent* students[]);
int main() {
	CAddress address = CAddress("Test street", "1000", "Sofia");
	CStudent* default_student = new CStudent();
	CStudent* first_student = new CStudent("Test Tester", "7552010005", "26003311", address);
	CStudent* second_student = new CStudent("Tester", "8032056031", "26003312", address);

	CStudent* students[3] = { default_student, first_student, second_student };

	OutputStudentsInFile(students);

	delete default_student, first_student, second_student, students;
	return 0;
}

void OutputStudentsInFile(CStudent* students[]) {
	// Writes the output studetns in a file.
	fstream file("StudentList.txt", ios_base::out);

	for (int i = 0; i < sizeof(students); i++) {
		students[i]->Output(file);
	}

	file.close();
}