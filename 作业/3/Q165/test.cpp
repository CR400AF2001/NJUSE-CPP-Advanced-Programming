#include <iostream>
using namespace std;

class myString {
	char head[100];

public:
	myString(char* Head) {
		int i = 0;
		while (Head[i] != '\0') {
			head[i] = Head[i];
			i++;
		}
		head[i] = '\0';
	}

	void Reverse() {
		int len = 0;
		while (head[len] != '\0') {
			len++;
		}
		for (int i = 0; i < len; ++i) {
			if (i >= len - i - 1) {
				break;
			}
			char temp = head[i];
			head[i] = head[len - i - 1];
			head[len - i - 1] = temp;
		}
	}

	void Print() {
		int i = 0;
		while (head[i] != '\0') {
			cout << head[i];
			i++;
		}
	}
};

int main() {
	char input[100];
	cin.getline(input, 100);
	myString a = myString(input);
	a.Reverse();
	a.Print();
	return 0;
}