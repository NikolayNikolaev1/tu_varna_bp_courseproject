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
			cout << "�������: ��������� �� �����." << endl;
			numbersCount = get_length_of_input_numbers(numbers);
			break;
		case '2':
			cout << "�������: ����������� �� ������-����������� �� ����������� ����� � ������� ��������." << endl;
			average = get_average(numbers, numbersCount);
			break;
		case '3':
			cout << "�������: ����������� �� �������������� �� ���������� �� ���� ����� � ���� �� �������� �����." << endl;
			product = get_product(numbers, numbersCount);
			zerosCount = get_zeros_count(numbers, numbersCount);
			break;
		case '4':
			cout << "�������: ��������� �� ����������� �� ����������� �����������, ����� � �� ���������� �����." << endl;
			display_result(numbers, numbersCount, average, product, zerosCount);
			break;
		}

		options();
		cin >> selectedOption;
	}

	cout << "�������: ����� �� ��������.";
}

int get_length_of_input_numbers(double numbers[])
{
	double count;

	cout << "�������� ���� �� ������ ����� �� ��������� ( �� 30 �����): ";
	cin >> count;

	do
	{
		if (count > 30)
		{
			cout << "��������� ���� ������ ����� ��������� 30!" << endl;
			cout << "�������� ���� �� ������ ����� �� ��������� ( �� 30 �����): ";
			cin >> count;
		}
	} while (count > 30);

	cout << "�������� ������ " << count << " ������ �����:" << endl;

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

	cout << "������� ��������� ��������: ";
	cin >> minNumber;
	cout << "������� ���������� ��������: ";
	cin >> maxNumber;

	while (minNumber > maxNumber)
	{
		cout << "����������� �������� �� ���� �� ���� ��-����� �� ����������� ��������!" << endl;
		cout << "������� ��������� ��������: ";
		cin >> minNumber;
		cout << "������� ���������� ��������: ";
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

	cout << "��������-����������� �� ������������� ����� � ��������� �������� [" << minNumber << ", " << maxNumber << "] �: " << average / counter << endl;

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

	hasOnlyZeros ? cout << "���� ����� �������� �� 0."  << endl 
		: cout << "�������������� �� ������� �������� �� ���� �: " << product << endl;

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

	cout << "���� ���� �: " << zerosCounter << endl;

	return zerosCounter;
}

void display_result(double numbers[], int numbersCount, double average, double product, double zerosCount)
{
	cout << "�������� �����: ";

	for (int i = 0; i < numbersCount; i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;

	if (average != 0)
	cout << "������-����������� �� ������������� �����: " << average << endl;
	if (product != 0)
	{
		cout << "�������������� �� ������� �������� �� ����: " << product << endl;
		cout << "���� �� ����: " << zerosCount << endl;
	}
}

void options()
{
	SetConsoleOutputCP(1251); // Cyrillic output.
	SetConsoleCP(1251); // Cyrillic output.
	cout << "�������� ����� �� ������ �� �������� �� ��� �������:" << endl;
	cout << "1. ��������� �� ������ �����." << endl;
	cout << "2. ����������� �� ������-����������� �� ����������� ����� � ������� ��������." << endl;
	cout << "3. ����������� �� �������������� �� ���������� �� ���� ����� � ���� �� �������� �����." << endl;
	cout << "4. ��������� �� ����� �� ����������� �� ����������� �����������, ����� � �� ���������� �����." << endl;
	cout << "0. ����� �� ����������" << endl;
	cout << "����� �� �������: ";
}
