#include <iostream>
using namespace std;

bool strcmp(char* s1, const char* s2) {
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0') {
		if (s1[i] != s2[i]) {
			return false;
		}
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0') {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	int capacity = 0;
	int size = 0;
	cin >> n;
	int* a = new int[capacity];
	for (int i = 0; i < n; ++i) {
		char* command = new char[30];
		cin >> command;
		int x = 0;
		cout << endl;
		if (strcmp(command, "add")) {
			cin >> x;
			if (capacity == 0) {
				capacity = 10;
				a = new int[capacity];
			}
			else {
				if (size == capacity) {
					capacity = capacity + int(capacity / 2);
					int* temp = new int[capacity];
					for (int j = 0; j < size; ++j) {
						temp[j] = a[j];
					}
					delete a;
					a = temp;
				}
			}
			a[size] = x;
			size++;
		}
		else if (strcmp(command, "remove")) {
			cin >> x;
			for (int j = 0; j < size; ++j) {
				if (a[j] == x) {
					for (int k = j + 1; k < size; ++k) {
						a[k - 1] = a[k];
					}
					size--;
					break;
				}
			}
		}
		else if (strcmp(command, "get")) {
			cin >> x;
			if (x >= size || x < 0) {
				cout << -1 << endl;
			}
			else {
				cout << a[x] << endl;
			}
		}
		else if (strcmp(command, "getSize")) {
			cout << size << endl;
		}
		else if (strcmp(command, "getCapacity")) {
			cout << capacity << endl;
		}
	}
	return 0;
}