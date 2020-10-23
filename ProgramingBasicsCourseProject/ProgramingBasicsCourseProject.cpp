#include <iostream>
#include<windows.h> // Cyrillic output.

using namespace std;

const int MAX_ARRAY_ELEMENTS = 30;

void options();
int get_length_of_input_numbers(double numbers[]);
double get_average(double numbers[], int numbersCount);
double get_product(double numbers[], int numbersCount);
double get_zeros_count(double numbers[], int numbersCount);
void display_result(double numbers[], int numbersCount, double average, double product, double zerosCount);

void main()
{
	double numbers[MAX_ARRAY_ELEMENTS], numbersCount = 0, average = 0, product = 0, zerosCount = 0;

	options();
	char selectedOption;
	cin >> selectedOption;

	while (selectedOption != '0')
	{
		switch (selectedOption)
		{
		case '1':
			cout << "Избрано: Въвеждане на числа." << endl;
			numbersCount = get_length_of_input_numbers(numbers);
			break;
		case '2':
			cout << "Избрано: Изчисляване на средно-аритметично на отрицателни числа в зададен интервал." << endl;
			average = get_average(numbers, numbersCount);
			break;
		case '3':
			cout << "Избрано: Изчисляване на произведението на различните от нула числа и броя на нулевите числа." << endl;
			product = get_product(numbers, numbersCount);
			zerosCount = get_zeros_count(numbers, numbersCount);
			break;
		case '4':
			cout << "Избрано: Извеждане на резултатите от съответното изчисляване, както и на въведените числа." << endl;
			display_result(numbers, numbersCount, average, product, zerosCount);
			break;
		}

		options();
		cin >> selectedOption;
	}

	cout << "Избрано: Изход от програма.";
}

int get_length_of_input_numbers(double numbers[])
{
	double count;

	cout << "Изберете брой на реални числа за въвеждане ( до 30 числа): ";
	cin >> count;

	do
	{
		if (count > 30)
		{
			cout << "Избраният брой реални числа надвишава 30!" << endl;
			cout << "Изберете брой на реални числа за въвеждане ( до 30 числа): ";
			cin >> count;
		}
	} while (count > 30);

	cout << "Въведете вашите " << count << " реални числа:" << endl;

	for (int i = 0; i < count; i++)
	{
		double currentNumber;
		cin >> currentNumber;
		numbers[i] = currentNumber;
	}


	return count;
}

double get_average(double numbers[], int numbersCount)
{
	int minNumber, maxNumber;

	cout << "Задайте минимален интервал: ";
	cin >> minNumber;
	cout << "Задайте максимален интервал: ";
	cin >> maxNumber;

	while (minNumber > maxNumber)
	{
		cout << "Минималният интервал не може да бъде по-голям от максималния интервал!" << endl;
		cout << "Задайте минимален интервал: ";
		cin >> minNumber;
		cout << "Задайте максимален интервал: ";
		cin >> maxNumber;

	}

	double average = 0;
	int counter = 0;

	for (int i = 0; i < numbersCount; i++)
	{
		double currentNumber = numbers[i];

		if (currentNumber < 0 && currentNumber >= minNumber && currentNumber <= maxNumber)
		{
			average += currentNumber;
			counter++;
		}
	}

	cout << "Средното-аритметично на отрицателните числа в зададения интервал [" << minNumber << ", " << maxNumber << "] е: " << average / counter << endl;

	return average / counter;
}

double get_product(double numbers[], int numbersCount)
{
	double product = 1;
	bool hasOnlyZeros = true;

	for (int i = 0; i < numbersCount; i++)
	{
		double currentNumber = numbers[i];

		if (currentNumber != 0)
		{
			product *= currentNumber;
			hasOnlyZeros = false;
		}
	}

	hasOnlyZeros ? cout << "Няма числа различни от 0."  << endl 
		: cout << "Произведението на числата различни от нула е: " << product << endl;

	return product;
}

double get_zeros_count(double numbers[], int numbersCount)
{
	int zerosCounter = 0;

	for (int i = 0; i < numbersCount; i++)
	{
		double currentNumber = numbers[i];

		if (currentNumber == 0)
		{
			zerosCounter++;
		}
	}

	cout << "Броя нули е: " << zerosCounter << endl;

	return zerosCounter;
}

void display_result(double numbers[], int numbersCount, double average, double product, double zerosCount)
{
	cout << "Въведени числа: ";

	for (int i = 0; i < numbersCount; i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;

	if (average != 0)
	cout << "Средно-аритметично на отрицателните числа: " << average << endl;
	if (product != 0)
	{
		cout << "Произведението на числата различни от нула: " << product << endl;
		cout << "Броя на нули: " << zerosCount << endl;
	}
}

void options()
{
	SetConsoleOutputCP(1251); // Cyrillic output.
	SetConsoleCP(1251); // Cyrillic output.
	cout << "Изберете номер от менюто на желаната от вас функция:" << endl;
	cout << "1. Въвеждане на реални числа." << endl;
	cout << "2. Изчисляване на средно-аритметично от отрицателни числа в зададен интервал." << endl;
	cout << "3. Изчисляване на произведението на различните от нула числа и броя на нулевите числа." << endl;
	cout << "4. Извеждане на екран на резултатите от съответното изчисляване, както и на въведените числа." << endl;
	cout << "0. Изход от програмата" << endl;
	cout << "Избор на функция: ";
}
