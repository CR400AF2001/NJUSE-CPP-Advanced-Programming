#include <iostream>
#include <fstream>
using namespace std;

int main() {
	string fileName;
	cin >> fileName;
	ifstream fin("C:\\Users\\丁云翔\\Desktop\\C++高程\\作业\\1\\Q149\\" + fileName, ios_base::binary);
	if (!fin.is_open()) {
		cout << "FILE NOT FOUND" << endl;
		return 0;
	}
	fin.seekg(0, fin.end);
	int length = fin.tellg();
	fin.seekg(0, fin.beg);
	char* buffer = new char[length];
	fin.read(buffer, length);
	fin.close();
	int j = 0;
	string result = "";
	char word[4];
	while (j + 3 <= length) {
		int temp = (buffer[j] << 16) + (buffer[j + 1] << 8) + buffer[j + 2];
		word[0] = 0x3F & (temp >> 18);
		word[1] = 0x3F & (temp >> 12);
		word[2] = 0x3F & (temp >> 6);
		word[3] = 0x3F & temp;
		for (int i = 0; i < 4; ++i) {
			if (word[i] <= 25) {
				result += ('A' + word[i]);
			}
			else if (word[i] <= 51) {
				result += ('a' + word[i] - 26);
			}
			else if (word[i] <= 61) {
				result += ('0' + word[i] - 52);
			}
			else if (word[i] == 62) {
				result += '+';
			}
			else if (word[i] == 63) {
				result += '/';
			}
		}
		j += 3;
	}
	if (j + 1 == length) {
		int temp = buffer[j];
		word[0] = 0x3F & (temp >> 2);
		word[1] = 0x3F & (temp << 4);
		for (int i = 0; i < 2; ++i) {
			if (word[i] <= 25) {
				result += ('A' + word[i]);
			}
			else if (word[i] <= 51) {
				result += ('a' + word[i] - 26);
			}
			else if (word[i] <= 61) {
				result += ('0' + word[i] - 52);
			}
			else if (word[i] == 62) {
				result += '+';
			}
			else if (word[i] == 63) {
				result += '/';
			}
		}
		result += "==";
	}
	else if (j + 2 == length) {
		int temp = (buffer[j] << 8) + buffer[j + 1];
		word[0] = 0x3F & (temp >> 10);
		word[1] = 0x3F & (temp >> 4);
		word[2] = 0x3F & (temp << 2);
		for (int i = 0; i < 3; ++i) {
			if (word[i] <= 25) {
				result += ('A' + word[i]);
			}
			else if (word[i] <= 51) {
				result += ('a' + word[i] - 26);
			}
			else if (word[i] <= 61) {
				result += ('0' + word[i] - 52);
			}
			else if (word[i] == 62) {
				result += '+';
			}
			else if (word[i] == 63) {
				result += '/';
			}
		}
		result += "=";
	}
	cout << result << endl;
	return 0;
}