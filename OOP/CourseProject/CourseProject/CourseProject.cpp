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

	const int RGB() const {
		// Sums and returns the RGB numbers.
		return this->red + this->green + this->blue;
	}

	void SetColors(const int& red, const int& green, const int& blue) {
		// Sets RGB colors using the validation setters.
		this->SetRed(red);
		this->SetGreen(green);
		this->SetBlue(blue);
	}

	ostream& Output(ostream& stream) const {
		// Returns output info of the current color RGB.
		return stream << "RGB: (" << this->red << ", " << this->green << ", " << this->blue << ")" << endl;
	}

	friend bool operator==(const CColor& first_color, const CColor& second_color) {
		return first_color.RGB() == second_color.RGB();
	}

	friend bool operator<(const CColor& first_color, const CColor& second_color) {
		return first_color.RGB() < second_color.RGB();
	}

	friend ostream& operator<<(ostream& stream, const CColor& color) {
		return color.Output(stream);
	}

private:
	// Setters.
	void SetRed(const int& red) {
		if (red < MIN_COLOR_NUMBER || red > MAX_COLOR_NUMBER) {
			throw INVALID_COLOR_NUMBER_ERROR_MESSAGE;
		}

		this->red = red;
	}

	void SetGreen(const int& green) {
		if (green < MIN_COLOR_NUMBER || green > MAX_COLOR_NUMBER) {
			throw INVALID_COLOR_NUMBER_ERROR_MESSAGE;
		}

		this->green = green;
	}

	void SetBlue(const int& blue) {
		if (blue < MIN_COLOR_NUMBER || blue > MAX_COLOR_NUMBER) {
			throw INVALID_COLOR_NUMBER_ERROR_MESSAGE;
		}

		this->blue = blue;
	}
};

class CColorPoint : public CColor {
private:
	int x_coordinate;
	int y_coordinate;

public:
	CColorPoint()
		: CColor() {
		this->SetCoordinateX(0);
		this->SetCoordianteY(0);
	}

	CColorPoint(const int& x, const int& y, const CColor& color)
		: CColor(color) {
		this->SetCoordinateX(x);
		this->SetCoordianteY(y);
	}

	ostream& Output(ostream& stream) const {
		CColor::Output(stream);
		return stream << "X: " << this->x_coordinate << " Y: " << this->y_coordinate << endl;
	}

	friend ostream& operator<<(ostream& stream, const CColorPoint& color_point) {
		return color_point.Output(stream);
	}

private:
	// Setters.
	void SetCoordinateX(const int& x) {
		this->x_coordinate = x;
	}

	void SetCoordianteY(const int& y) {
		this->y_coordinate = y;
	}
};

int main() {
	try {
		CColor color = CColor(16, 1, 1);
	}
	catch (const string error) {
		cout << error << endl;
	}

	return 0;
}