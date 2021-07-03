#include <iostream>
using namespace std;

int main() {
	char a[65];
	int n;
	cin >> a >> n;
	int length = 0;
	while (a[length] != '\0') {
		length++;
	}
	if (n == 1) {
		for (int i = 0; i < length; ++i) {
			cout << a[i];
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (i < length) {
				if (i == 0 || i == n - 1) {
					int temp = i;
					while (temp < length) {
						cout << a[temp];
						temp += 2 * (n - 1);
					}
				}
				else {
					cout << a[i];
					int temp = 2 * (n - 1);
					while (temp - i < length) {
						cout << a[temp - i];
						if (temp + i < length) {
							cout << a[temp + i];
						}
						temp += 2 * (n - 1);
					}
				}
			}
		}
	}
	return 0;
}