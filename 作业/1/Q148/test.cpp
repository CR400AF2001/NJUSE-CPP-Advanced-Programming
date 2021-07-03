#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == -2147483648) {
		cout << -1 << endl;
		return 0;
	}
	int sign = 0;
	if (n > 0) {
		sign = 1;
	}
	else {
		sign = -1;
		n *= -1;
	}
	int result = 0;
	while (n > 0) {
		result = result * 10 + (n % 10);
		n /= 10;
	}
	if (result < 0) {
		cout << -1 << endl;
	}
	else {
		cout << (sign * result) << endl;
	}
	return 0;
}