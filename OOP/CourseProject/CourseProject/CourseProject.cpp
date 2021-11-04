#include <iostream>
#include <string>
#include <vector>
#define DEFAULT_NUMBER 0
#define MAX_COLOR_NUMBER 15
#define MIN_COLOR_NUMBER 0

using namespace std;

class CColor {
private:
	int red;
	int green;
	int blue;

	const char* INPUT_RGB_COLOR_MESSAGE = "Enter integer between 0 and 15 for ";
	const char* INVALID_COLOR_NUMBER_ERROR_MESSAGE = "Color RGB numbers must be between 0 and 15!";
	static constexpr const char* test = "test"; // TODO

public:
	CColor() : CColor(DEFAULT_NUMBER, DEFAULT_NUMBER, DEFAULT_NUMBER) { }

	CColor(const int& red, const int& green, const int& blue) {
		this->SetRed(red);
		this->SetGreen(green);
		this->SetBlue(blue);
	}

	CColor(const CColor& color)
		: CColor(color.red, color.green, color.blue) { }

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

	istream& Input(istream& input_stream) {
		// Reads RGB inputs from stream and sets them in the color properties.
		int red, green, blue;

		cout << INPUT_RGB_COLOR_MESSAGE << "red: ";
		input_stream >> red;
		cout << INPUT_RGB_COLOR_MESSAGE << "blue: ";
		input_stream >> green;
		cout << INPUT_RGB_COLOR_MESSAGE << "green: ";
		input_stream >> blue;

		this->SetColors(red, green, blue);

		return input_stream;
	}

	ostream& Output(ostream& output_stream) const {
		// Returns output info of the current color RGB.
		return output_stream << "RGB: (" << this->red << ", " << this->green << ", " << this->blue << ")" << endl;
	}

	friend bool operator==(const CColor& first_color, const CColor& second_color) {
		return first_color.RGB() == second_color.RGB();
	}

	friend bool operator<(const CColor& first_color, const CColor& second_color) {
		return first_color.RGB() < second_color.RGB();
	}

	friend ostream& operator<<(ostream& output_stream, const CColor& color) {
		return color.Output(output_stream);
	}

	friend istream& operator>>(istream& input_stream, CColor& color) {
		return color.Input(input_stream);
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
	CColorPoint() : CColor() {
		this->SetCoordinateX(DEFAULT_NUMBER);
		this->SetCoordianteY(DEFAULT_NUMBER);
	}

	CColorPoint(const int& x, const int& y, const CColor& color)
		: CColor(color) {
		this->SetCoordinateX(x);
		this->SetCoordianteY(y);
	}

	CColorPoint(const CColorPoint& color_point) 
		: x_coordinate(color_point.x_coordinate), y_coordinate(color_point.y_coordinate) { }

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

typedef vector<CColorPoint> polygon;

void CreateColor(CColor& color);
void CreateColorPoint(CColorPoint& color_point, const CColor& color);

int main() {
	int polygon_angles_count;
	CColor color;
	CColorPoint color_point;
	polygon polygon;

	cout << "How many angles does the polygon have: ";
	cin >> polygon_angles_count;

	for (int i = 1; i <= polygon_angles_count; i++) {
		try {
			cout << "Enter RGB color for point #" << i << endl;
			cin >> color;
			cout << "Enter coordinates for point #" << i << endl;
		}
		catch (const char* error) {
			/* Expected error is when atttemting to create a CColor class from input with incorrect
			* RGB color property values from input. Valid red, gren and blue values are between 0 and 15.
			* After the catch block prints the error message, the for iterator goes down by 1
			* until CColor class is created with valid RGB values. */
			cout << error << endl;
			i--;
		}

		//CreateColor(color);
		CreateColorPoint(color_point, color);
		polygon.push_back(color_point);
	}

	return 0;
}

void CreateColor(CColor& color) {
	cin >> color;
}

void CreateColorPoint(CColorPoint& color_point, const CColor& color) {
	int x, y;

	cout << "Enter coordinate for X value: ";
	cin >> x;
	cout << "Enter coordinate for Y value: ";
	cin >> y;

	color_point = CColorPoint(x, y, color);
}