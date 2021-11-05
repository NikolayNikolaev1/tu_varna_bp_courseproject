#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <vector>
#define CONTROL_DIGIT_ALGORITHM_DIVIDER 11
#define EGN_LENGTH 10
#define MAX_PEOPLE_IN_CITY 9

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
	CAddress home_address;

public:
	CPerson()
		: CPerson("default", Gender::unknown, "0000000000", CAddress()) { }

	CPerson(const string& name, const Gender& gender)
		: CPerson(name, gender, "0000000000", CAddress()) { }

	CPerson(const string& name, const string& egn)
		: CPerson(name, Gender::unknown, egn, CAddress()) { }

	CPerson(const string& name, const Gender& gender, const string& egn)
		: CPerson(name, gender, egn, CAddress()) { }

	CPerson(const string& name, const Gender& gender, const string& egn, const CAddress& address) {
		SetName(name);
		SetGender(gender);
		SetEGN(egn);
		SetHomeAddress(address);
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

	const CAddress GetHomeAddress() const {
		return this->home_address;
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

	void SetHomeAddress(const CAddress& address) {
		this->home_address = address;
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

	friend bool operator<(const CPerson& first_person, const CPerson& second_person) {
		return first_person.egn < second_person.egn;
	}

	friend bool operator==(const CPerson& first_person, const CPerson& secondd_person) {
		return first_person.egn == secondd_person.egn;
	}

	istream& Input(istream& from_stream) {
		string egn, name;
		from_stream >> name >> egn;

		CPerson try_person(name, egn);
		*this = try_person;

		return from_stream;
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

	static int Compare(const void* first_object, const void* second_object) {
		// Compare people by EGN, then by name.
		return !((*(CPerson*)first_object) == (*(CPerson*)second_object)) ?
			((*(CPerson*)first_object) < (*(CPerson*)second_object) ? -1 : 1) :
			((*(CPerson*)first_object).name > (*(CPerson*)second_object).name);
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

class CCity {
private:
	string name;
	vector<CPerson> people;

public:
	CCity(const string& file_name) {
		this->CreateCityFromFile(file_name);
	}

	void GetDuplicates(vector<CPerson>& duplicates) const {
		// Get all people with duplicated EGN in vector.
		CPerson first_person = this->people[0];
		CPerson current_person;
		bool is_duplicate = false;

		for (int i = 1; i < people.size(); i++) {
			current_person = this->people[i];
			if (first_person == current_person) {
				// Adds first duplicate person to vector.
				duplicates.push_back(first_person);
				is_duplicate = true;
			}
			else if (is_duplicate) {
				// Adds the second duplicate person to vector from the previous loop if the next one isn't duplicate too.
				duplicates.push_back(first_person);
				is_duplicate = false;
			}

			first_person = current_person;
		}
	}

	void RemoveDuplicate() {
		// Remove all duplicated people from vector.
		vector<CPerson> duplicates;
		this->GetDuplicates(duplicates);
		this->RemovePeople(duplicates);
	}

	void RemovePeople(vector<CPerson> remove_people) {
		// Remove all people from the given person vector.
		for (int i = 0; i < this->people.size(); i++) {
			for (int j = 0; j < remove_people.size(); j++) {
				if (this->people[i] == remove_people[j]) {
					this->people.erase(this->people.begin() + i);
					remove_people.erase(remove_people.begin() + j);
					i = 0; // start from the beginning to not skip a person.
					break;
				}
			}
		}
	}

	istream& Input(istream& from_stream) {
		string person_info, person_name, person_egn;

		from_stream >> this->name;

		while (from_stream >> person_info) {
			// Splits person_info by space into 2 string - egn and name.
			this->SplitPersonInfo(person_info, person_name, person_egn);

			CPerson person = CPerson(person_name, person_egn);

			if (this->people.size() < MAX_PEOPLE_IN_CITY) {
				// Does not add more people to the array in case there are more than the maximum value in city.
				this->people.push_back(person);
			}
		}

		return from_stream;
	}

	ostream& Output(ostream& to_stream) const {
		to_stream << "Name: " << this->name << endl
			<< "People: " << endl;

		for (int i = 0; i < this->people.size(); i++) {
			CPerson current_person = this->people[i];
			to_stream << i + 1 << ". EGN: " << current_person.GetEGN() << " Name: " << current_person.GetName() << endl;
		}

		return to_stream;
	}

	friend ostream& operator<<(ostream& to_stream, const CCity& city) {
		return city.Output(to_stream);
	}

	friend istream& operator>>(istream& from_stream, CCity& city) {
		return city.Input(from_stream);
	}

private:
	void CreateCityFromFile(string file_name) {
		// Creates a city from given file that contains city name and person egn and name.
		string line;
		string person_name, person_egn;
		ifstream file(file_name);
		int is_first_line = true;

		while (getline(file, line)) {
			if (is_first_line) {
				// First line is city name.
				this->name = line;
				is_first_line = false;
				continue;
			}

			// Next lines are person EGN and name.
			if (this->people.size() < MAX_PEOPLE_IN_CITY) {
				// Creates the first 9 people and adds it to people array.
				this->SplitPersonInfo(line, person_name, person_egn);
				CPerson person = CPerson(person_name, person_egn);

				this->people.push_back(person);
			}
		}

		this->SortPeople();
	}

	void SplitPersonInfo(const string& person_info, string& person_name, string& person_egn) const {
		// Splits given info string by space.
		person_egn = person_info.substr(0, person_info.find(" "));
		person_name = person_info.substr(person_info.find(" ") + 1);
	}

	void SortPeople() {
		// Sort people vector by EGN, then by name;
		qsort(&people[0], MAX_PEOPLE_IN_CITY, sizeof(CPerson), CPerson::Compare);
	}
};

class CStudent : public CPerson {
private:
	string faculty_number;
	CAddress address;
	double grade;

public:
	CStudent()
		: CPerson() {
		this->SetFacultyNumber("N/A");
		this->SetGrade(0.0);
		this->SetAddress(CAddress());
	}

	CStudent(const string& name, const string& egn, const CAddress& address)
		: CPerson(name, egn) {
		this->SetAddress(address);
		this->SetFacultyNumber("N/A");
		this->SetGrade(0.0);
	}

	CStudent(const string& faculty_number, const double& grade)
		: CPerson() {
		this->SetFacultyNumber(faculty_number);
		this->SetGrade(grade);
	}

	CStudent(const string& name, const string& egn, const string& faculty_number, const CAddress& address)
		: CPerson(name, egn) {
		this->SetFacultyNumber(faculty_number);
		this->SetAddress(address);
		this->SetGrade(0.0);
	}

	CStudent(const string& name, const string& egn, const string& faculty_number, const double& grade, const CAddress& address)
		: CPerson(name, egn) {
		this->SetFacultyNumber(faculty_number);
		this->SetAddress(address);
		this->SetGrade(grade);
	}

	CStudent(const CStudent& student)
		: CStudent(student.GetName(), student.GetEGN(), student.faculty_number, student.grade, student.address) { }

	// Getters
	const string GetFacultyNumber() const {
		return this->faculty_number;
	}

	const CAddress GetAddress() const {
		return this->address;
	}

	const double GetGrade() const {
		return this->grade;
	}

	// Setters
	void SetFacultyNumber(const string& faculty_number) {
		this->faculty_number = faculty_number;
	}

	void SetAddress(const CAddress& address) {
		this->address = address;
	}

	void SetGrade(const double& grade) {
		this->grade = grade;
	}

	istream& Input(istream& from_stream) {
		string fac_num;
		double grade;

		from_stream >> fac_num;
		from_stream >> grade;

		*this = CStudent(fac_num, grade);

		return from_stream;
	}

	ostream& Output(ostream& to_stream) const {
		// Returns output info of the current person, his address and faculty number.
		CPerson::Output(to_stream);
		this->address.Output(to_stream);

		return to_stream << "Faculty Number: " << this->faculty_number << endl
			<< "Grade: " << this->grade << endl;
	}

	friend ostream& operator<<(ostream& to_stream, const CStudent& student) {
		return student.Output(to_stream);
	}

	friend istream& operator>>(istream& from_stream, CStudent& student) {
		return student.Input(from_stream);
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

class CStudentBook {
private:
	CStudent student;
	list<string> subjects;
	list<int> points;

public:
	CStudentBook(const CStudent& student) {
		this->student = student;
	}

	CStudentBook(const string& file_name) {
		this->CreateStudentBookFromFile(file_name);
	}

	void addPoints(const string& subject, const int& points) {
		// Adds given points to the given subject.
		int subject_index = 0;
		auto current_subject = this->subjects.begin();
		auto current_points = this->points.begin();

		for (int i = 0; i < this->subjects.size(); i++) {
			if (subject == *current_subject) {
				advance(current_points, i);
				*current_points += points;
				break;
			}
		}
	}

	int getMaxPoints() const {
		// Returns max points
		int max_points = 0;
		auto current_points = this->points.begin();

		for (int i = 0; i < this->points.size(); i++) {
			if (max_points < *current_points) {
				max_points = *current_points;
			}

			advance(current_points, 1);
		}

		return max_points;
	}

	int getMinPoints() const {
		// Returns min points;
		int min_points = 100;
		auto current_points = this->points.begin();

		for (int i = 0; i < this->points.size(); i++) {
			if (min_points > *current_points) {
				min_points = *current_points;
			}

			advance(current_points, 1);
		}

		return min_points;
	}

	ostream& Output(ostream& to_stream) const {
		to_stream << "Faculty Number: " << this->student.GetFacultyNumber() << " - "
			<< "Grade: " << this->student.GetGrade() << endl;

		auto current_subject = this->subjects.begin();
		auto current_points = this->points.begin();

		for (int i = 0; i < this->subjects.size(); i++) {
			advance(current_subject, i);
			advance(current_points, i);

			to_stream << "Subject: " << *current_subject << " - "
				<< "Points: " << *current_points << endl;

			current_subject = this->subjects.begin();
			current_points = this->points.begin();
		}

		return to_stream;
	}

	friend ostream& operator<<(ostream& to_stream, const CStudentBook& student_book) {
		return student_book.Output(to_stream);
	}

private:
	void CreateStudentBookFromFile(string file_name) {
		// Creates a studnt book from given file that contains faculty number, grade, subject and points.
		string line;
		string faculty_number, subject_name;
		double grade;
		int subject_points;
		ifstream file(file_name);
		int is_first_line = true;

		while (getline(file, line)) {
			if (is_first_line) {
				// First line is student faculty number and grade.
				this->SplitStudentInfo(line, faculty_number, grade);
				this->student.SetFacultyNumber(faculty_number);
				this->student.SetGrade(grade);

				is_first_line = false;
				continue;
			}

			// Next lines are subject name and subject points.
			this->SplitSubjectInfo(line, subject_name, subject_points);
			this->subjects.push_back(subject_name);
			this->points.push_back(subject_points);
		}
	}


	void SplitStudentInfo(const string& student_info, string& faculty_number, double& grade) const {
		// Splits given student info string by space.
		faculty_number = student_info.substr(0, student_info.find(" "));
		grade = stod(student_info.substr(student_info.find(" ") + 1));
	}

	void SplitSubjectInfo(const string& subject_info, string& subject_name, int& subject_points) const {
		// Split given subject info by space.
		subject_name = subject_info.substr(0, subject_info.find(" "));
		subject_points = stoi(subject_info.substr(subject_info.find(" ") + 1));
	}
};

class CCar {
private:
	int power;
	string model;
	string register_number;
	string owner;

public:
	static string city_code;
	static map<string, string> city_code_name_map;
	static multimap<string, string> city_name_code_multimap;

	CCar() :CCar(0, "N/A", "N/A", "N/A") { }

	CCar(const int& power, const string& model, const string& register_number, const string& owner) {
		this->SetPower(power);
		this->SetModel(model);
		this->SetRegisterNumber(register_number);
		this->SetOwner(owner);
	}

	CCar(const CCar& car)
		: CCar(car.power, car.model, car.register_number, car.owner) { }

	static string GetCityCode(string register_number) {

	}

	friend bool operator==(const CCar& first_car, const CCar& second_car) {
		return first_car.owner == second_car.owner;
	}

	friend bool operator<(const CCar& first_car, const CCar& second_car) {
		return first_car.register_number < second_car.register_number;
	}

	friend ostream& operator<<(ostream& to_stream, const CCar& car) {
		return car.Output(to_stream);
	}

	friend istream& operator>>(istream& from_stream, CCar& car) {
		return car.Input(from_stream);
	}

private:
	// Getters
	const int GetPower() const {
		return this->power;
	}

	const string GetModel() const {
		return this->model;
	}

	const string GetRegisterNumber() const {
		return this->register_number;
	}

	const string GetOwner() const {
		return this->owner;
	}

	// Setters
	void SetPower(const int& power) {
		this->power = power;
	}

	void SetModel(const string& model) {
		this->model = model;
	}

	void SetRegisterNumber(const string& register_number) {
		this->register_number = register_number;
	}

	void SetOwner(const string& owner) {
		this->owner = owner;
	}

	istream& Input(istream& from_stream) {
		int power;
		string model, reg_num, owner;

		from_stream >> power >> model >> reg_num >> owner;

		*this = CCar(power, model, reg_num, owner);

		return from_stream;
	}

	ostream& Output(ostream& to_stream) const {
		return to_stream << "Power: " << this->power << endl
			<< "Model: " << this->model << endl
			<< "Register Number: " << this->register_number << endl
			<< "Owner: " << this->owner << endl;
	}
};

void OutputStudentsInFile(CStudent* students[]);
int main() {
	/*CAddress address = CAddress("Test street", "1000", "Sofia");
	CStudent* default_student = new CStudent();
	CStudent* first_student = new CStudent("Test Tester", "7552010005", "26003311", address);
	CStudent* second_student = new CStudent("Tester", "8032056031", "26003312", address);

	CStudent* students[3] = { default_student, first_student, second_student };

	OutputStudentsInFile(students);

	delete default_student, first_student, second_student, students;*/
	/*CCity city = CCity("CityPeopleList.txt");
	vector<CPerson> duplicate_people;
	city.GetDuplicates(duplicate_people);

	cout << "Duplicate: " << endl;
	for (int i = 0; i < duplicate_people.size(); i++) {
		cout << i + 1 << ". " << duplicate_people[i];
	}

	cout << "People Remod." << endl;
	city.RemoveDuplicate();
	cout << city;*/

	CStudentBook student_book = CStudentBook("StudentBookList.txt");
	cout << student_book;
	cout << student_book.getMinPoints() << endl;
	cout << student_book.getMaxPoints() << endl;
	student_book.addPoints("OOP1", 20);
	cout << student_book;


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