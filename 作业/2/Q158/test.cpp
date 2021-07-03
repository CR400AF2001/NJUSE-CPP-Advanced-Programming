#include <iostream>
using namespace std;

int main() {
	char** a = new char* [9];
	for (int i = 0; i < 9; ++i) {
		a[i] = new char[9];
		for (int j = 0; j < 9; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 9; ++i) {
		bool present[10] = { false };
		for (int j = 0; j < 9; ++j) {
			if (a[i][j] != '.') {
				if (present[int(a[i][j] - '0')] == false) {
					present[int(a[i][j] - '0')] = true;
				}
				else {
					cout << "false" << endl;
					return 0;
				}
			}
		}
	}
	for (int j = 0; j < 9; ++j) {
		bool present[10] = { false };
		for (int i = 0; i < 9; ++i) {
			if (a[i][j] != '.') {
				if (present[int(a[i][j] - '0')] == false) {
					present[int(a[i][j] - '0')] = true;
				}
				else {
					cout << "false" << endl;
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			bool present[10] = { false };
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					if (a[i * 3 + k][j * 3 + l] != '.') {
						if (present[int(a[i * 3 + k][j * 3 + l] - '0')] == false) {
							present[int(a[i * 3 + k][j * 3 + l] - '0')] = true;
						}
						else {
							cout << "false" << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	cout << "true" << endl;
	return 0;
}