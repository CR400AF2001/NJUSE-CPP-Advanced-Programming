#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; ++i) {
		a[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	int length = m * n;
	int temp = 0;
	int i = 0;
	while (temp < length) {
		for (int j = i; j < n - i; ++j) {
			cout << a[i][j] << " ";
			temp++;
		}
		if (temp >= length) {
			break;
		}
		for (int j = i + 1; j < m - i; ++j) {
			cout << a[j][n - i - 1] << " ";
			temp++;
		}
		if (temp >= length) {
			break;
		}
		for (int j = n - i - 2; j >= i; --j) {
			cout << a[m - i - 1][j] << " ";
			temp++;
		}
		if (temp >= length) {
			break;
		}
		for (int j = m - i - 2; j > i; --j) {
			cout << a[j][i] << " ";
			temp++;
		}
		i++;
	}
	return 0;
}