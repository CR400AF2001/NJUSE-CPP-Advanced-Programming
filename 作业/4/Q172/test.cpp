#include <iostream>

using namespace std;

class Rational {
public:
	long long up;
	long long down;

	Rational() {
		up = 1;
		down = 1;
	}

	Rational(int a, int b) {
		up = a;
		down = b;
		reduce();
	}

	void reduce() {
		int max = 1;
		if (down < 0) {
			up = -up;
			down = -down;
		}
		if (abs(up) >= abs(down)) {
			max = abs(down);
		}
		else {
			max = abs(up);
		}
		for (int i = max; i > 1; --i) {
			if (up % i == 0 && down % i == 0) {
				up /= i;
				down /= i;
			}
		}
	}


	Rational operator - () {
		Rational temp;
		temp.up = -up;
		temp.down = down;
		return temp;
	}

	Rational& operator = (const Rational& x) {
		up = x.up;
		down = x.down;
		this->reduce();
		return *this;
	}

	Rational& operator ++ () {
		up += down;
		this->reduce();
		return *this;
	}

	Rational& operator -- () {
		up -= down;
		this->reduce();
		return *this;
	}

	Rational operator ++ (int) {
		Rational temp = *this;
		up += down;
		this->reduce();
		return temp;
	}

	Rational operator -- (int) {
		Rational temp = *this;
		up -= down;
		this->reduce();
		return temp;
	}

	friend Rational operator + (Rational& x1, Rational& x2);
	friend Rational operator - (Rational& x1, Rational& x2);
	friend Rational operator * (Rational& x1, Rational& x2);
	friend Rational operator / (Rational& x1, Rational& x2);
	friend bool operator < (Rational& x1, Rational& x2);
	friend bool operator <= (Rational& x1, Rational& x2);
	friend bool operator > (Rational& x1, Rational& x2);
	friend bool operator >= (Rational& x1, Rational& x2);
	friend istream& operator >> (istream& cin, Rational& x);
	friend ostream& operator << (ostream& cout, Rational& x);
};

Rational operator + (Rational& x1, Rational& x2) {
	Rational temp;
	temp.up = x1.up * x2.down + x1.down * x2.up;
	temp.down = x1.down * x2.down;
	temp.reduce();
	return temp;
}

Rational operator - (Rational& x1, Rational& x2) {
	Rational temp;
	temp.up = x1.up * x2.down - x1.down * x2.up;
	temp.down = x1.down * x2.down;
	temp.reduce();
	return temp;
}

Rational operator * (Rational& x1, Rational& x2) {
	Rational temp;
	temp.up = x1.up * x2.up;
	temp.down = x1.down * x2.down;
	temp.reduce();
	return temp;
}

Rational operator / (Rational& x1, Rational& x2) {
	Rational temp;
	temp.up = x1.up * x2.down;
	temp.down = x1.down * x2.up;
	temp.reduce();
	return temp;
}

bool operator < (Rational& x1, Rational& x2) {
	if (x1.up * x1.down < 0 && x2.up * x2.down < 0) {
		if (x1.up * x2.down <= x1.down * x2.up) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (x1.up * x2.down < x1.down * x2.up) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool operator <= (Rational& x1, Rational& x2) {
	if (x1.up * x1.down < 0 && x2.up * x2.down < 0) {
		if (x1.up * x2.down < x1.down * x2.up) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (x1.up * x2.down <= x1.down * x2.up) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool operator > (Rational& x1, Rational& x2) {
	if (x1.up * x1.down < 0 && x2.up * x2.down < 0) {
		if (x1.up * x2.down >= x1.down * x2.up) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (x1.up * x2.down > x1.down * x2.up) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool operator >= (Rational& x1, Rational& x2) {
	if (x1.up * x1.down < 0 && x2.up * x2.down < 0) {
		if (x1.up * x2.down > x1.down * x2.up) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (x1.up * x2.down >= x1.down * x2.up) {
			return true;
		}
		else {
			return false;
		}
	}
}

istream& operator >> (istream& cin, Rational& x) {
	cin >> x.up >> x.down;
	return cin;
}

ostream& operator << (ostream& cout, Rational& x) {
	if (x.up % x.down == 0) {
		cout << x.up / x.down;
	}
	else {
		cout << x.up << '/' << x.down;
	}
	return cout;
}


int main() {
	Rational a, b;
	cin >> a;
	cin >> b;
	Rational c;
	c = a + b;
	cout << c << endl;
	c = a - b;
	cout << c << endl;
	c = a * b;
	cout << c << endl;
	c = a / b;
	cout << c << endl;
	c = -a;
	cout << c << endl;
	cout << ++a << endl;
	cout << --a << endl;
	c = a++;
	cout << c << endl;
	c = a--;
	cout << c << endl;
	if (a < b) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (a <= b) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (a > b) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (a >= b) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}