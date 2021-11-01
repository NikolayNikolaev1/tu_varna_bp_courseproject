#include <iostream>
#include <string>
#define MAX_COLOR_NUMBER 15
#define MIN_COLOR_NUMBER 0

using namespace std;

class CColor {
private:
	int red;
	int green;
	int blue;

	const string INVALID_COLOR_NUMBER_ERROR_MESSAGE = "Color RGB numbers must be between 0 and 15.";

public:
	CColor() : CColor(0, 0, 0) { }

	CColor(const CColor& color)
		: CColor(color.red, color.green, color.blue) { }

	CColor(const int& red, const int& green, const int& blue) {
		this->SetRed(red);
		this->SetGreen(green);
		this->SetBlue(blue);
	}

	void GetColor(int& red, int& green, int& blue) const {
		red = this->red;
		green = this->green;
		blue = this->blue;
	}

	void SetColors(const int& red, const int& green, const int& blue) {
		// Sets RGB colors using the validation setters.
		this->SetRed(red);
		this->SetGreen(green);
		this->SetBlue(blue);
	}

	ostream& Output(ostream& stream) const {
		// Returns output info of the current color RGB.
		return stream << "RGB: (" << this->red << ", " << this->green << ", " << this->blue << ")";
	}

	friend bool operator==(const CColor& first_color, const CColor& second_color) {
		return first_color.GetColorSum() == second_color.GetColorSum();
	}

	friend bool operator<(const CColor& first_color, const CColor& second_color) {
		return first_color.GetColorSum() < second_color.GetColorSum();
	}

	friend ostream& operator<<(ostream& stream, const CColor& color) {
		return color.Output(stream);
	}

private:
	// Setters.
	void SetRed(const int& red) {
		if (red < MIN_COLOR_NUMBER || red > MAX_COLOR_NUMBER) {
			cout << INVALID_COLOR_NUMBER_ERROR_MESSAGE;
			return;
		}

		this->red = red;
	}

	void SetGreen(const int& green) {
		if (green < MIN_COLOR_NUMBER || green > MAX_COLOR_NUMBER) {
			cout << INVALID_COLOR_NUMBER_ERROR_MESSAGE;
			return;
		}

		this->green = green;
	}

	void SetBlue(const int& blue) {
		if (blue < MIN_COLOR_NUMBER || blue > MAX_COLOR_NUMBER) {
			cout << INVALID_COLOR_NUMBER_ERROR_MESSAGE;
			return;
		}

		this->blue = blue;
	}

	int GetColorSum() const {
		// Sums and returns the RGB numbers.
		return this->red + this->green + this->blue;
	}
};

int main() {
	return 0;
}