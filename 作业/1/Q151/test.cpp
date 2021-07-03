#include <iostream>
#include <string>
using namespace std;

int main() {
	string input = "";
	int charNum = 0;
	int wordNum = 0;
	int lineNum = 0;
	while (getline(cin, input)) {
		int length = input.length();
		bool isWord = false;
		for (int i = 0; i < length; ++i) {
			if (input[i] == ' ') {
				charNum++;
				if (isWord) {
					wordNum++;
					isWord = false;
				}
			}
			else {
				charNum++;
				isWord = true;
			}
		}
		charNum++;
		lineNum++;
		if (isWord) {
			wordNum++;
			isWord = false;
		}
	}
	cout << charNum << " " << wordNum << " " << lineNum << endl;
	return 0;
}