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

	const char* INVALID_COLOR_NUMBER_ERROR_MESSAGE = "Color RGB numbers must be between 0 and 15!";

public:
	static constexpr const char* INPUT_RGB_COLOR_POINT_MESSAGE = "Enter RGB color for point #";

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

	ostream& Output(ostream& output_stream) const {
		output_stream << "(X:" << this->x_coordinate << "; Y:" << this->y_coordinate << ") ";
		
		return CColor::Output(output_stream);;
	}

	friend ostream& operator<<(ostream& output_stream, const CColorPoint& color_point) {
		return color_point.Output(output_stream);
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
// Using vector of CColor pointers to prevent object slicing when pushing CColorPoint objects.
typedef vector<CColor*> polygon;

void CreatePolygon(polygon& polygon, const int& angles_count);
void OutputPolygon(const polygon& polygon);

int main() {
	int polygon_angles_count;
	polygon polygon;

	cout << "Enter polygon angles count: ";
	cin >> polygon_angles_count;

	CreatePolygon(polygon, polygon_angles_count);
	OutputPolygon(polygon);

	return 0;
}

CColorPoint* CreateColorPoint(const CColor& color) {
	// Create CColorPoint pointer from user input x and y values.
	int x, y;

	cout << "Enter coordinate for X value: ";
	cin >> x;
	cout << "Enter coordinate for Y value: ";
	cin >> y;

	CColorPoint* color_point = new CColorPoint(x, y, color);

	return color_point;
}

void CreateColor(CColor& color) {
	int red, green, blue;

	cout << "Enter integer between 0 and 15 for red: ";
	cin >> red;
	cout << "Enter integer between 0 and 15 for blue: ";
	cin >> green;
	cout << "Enter integer between 0 and 15 for green: ";
	cin >> blue;

	color.SetColors(red, green, blue);

}

void CreatePolygon(polygon& polygon, const int& angles_count) {
	CColor color;
	CColorPoint* color_point = new CColorPoint();

	for (int i = 1; i <= angles_count; i++) {
		try {
			cout << CColor::INPUT_RGB_COLOR_POINT_MESSAGE << i << endl;
			CreateColor(color);

			cout << "Enter coordinates for point #" << i << endl;
			color_point = CreateColorPoint(color);

			polygon.push_back(color_point);
		}
		catch (const char* error) {
			/* Expected error is when atttemting to create a CColor class from input with incorrect
			* RGB color property values from input. Valid red, gren and blue values are between 0 and 15.
			* After the catch block prints the error message, the for iterator goes down by 1
			* until CColor class is created with valid RGB values. */
			cout << error << endl;
			i--;
		}
	}
}

void OutputPolygon(const polygon& polygon) {
	// Outputs polygon colored points in the console.
	cout << "Polygon Points:" << endl;

	for (int i = 0; i < polygon.size(); i++) {
		cout << "Point #" << i + 1 << ": ";
		((CColorPoint*)polygon[i])->Output(cout);
	}
}
