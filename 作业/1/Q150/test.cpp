#include <iostream>
using namespace std;

int main() {
	int x1, x2, x3, y1, y2, y3;
	char temp;
	cin >> temp >> x1 >> temp >> y1 >> temp
		>> temp >> x2 >> temp >> y2 >> temp
		>> temp >> x3 >> temp >> y3 >> temp;
	if ((x1 - x2) * (y2 - y3) == (x2 - x3) * (y1 - y2)) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}