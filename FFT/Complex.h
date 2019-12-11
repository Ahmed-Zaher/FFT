class Complex {
public:
	double Re, Im;

	Complex(double _Re = 0, double _Im = 0) : Re(_Re), Im(_Im) {}

	Complex operator+(Complex oth) {
		return Complex(Re + oth.Re, Im + oth.Im);
	}

	Complex operator-(Complex oth) {
		return Complex(Re - oth.Re, Im - oth.Im);
	}

	Complex operator*(Complex oth) {
		return Complex(Re * oth.Re - Im * oth.Im, Re * oth.Im + Im * oth.Re);
	}

	double mag() {
		return sqrt(Re * Re + Im * Im);
	}

	double angle() {
		return atan2(Im, Re) * 180 / PI;
	}

	friend ostream& operator<<(ostream& o, const Complex& c) {
		return o << c.Re << (c.Im > EPS ? " +" : " -") << "j" << fabs(c.Im);
	}

};
