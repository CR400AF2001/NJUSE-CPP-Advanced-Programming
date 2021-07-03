#include <iostream>
using namespace std;

int main() {
	int n, theta;
	cin >> n >> theta;
	theta = theta % 360;
	int** a = new int* [n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	switch (theta) {
		case 0:
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 90:
			for (int j = 0; j < n; ++j) {
				for (int i = n - 1; i >= 0; --i) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 180:
			for (int i = n - 1; i >= 0; --i) {
				for (int j = n - 1; j >= 0; --j) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 270:
			for (int j = n - 1; j >= 0; --j) {
				for (int i = 0; i < n; ++i) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			break;
	}
	return 0;
}