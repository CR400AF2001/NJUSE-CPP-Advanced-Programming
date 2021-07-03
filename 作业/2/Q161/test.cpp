#include <iostream>
using namespace std;

int main() {
	char* a = new char[10000];
	char* b = new char[10000];
	char operate;
	cin >> a >> operate >> b;
	int signa = 0;
	int signb = 0;
	if (a[0] == '-') {
		signa = 1;
	}
	if (b[0] == '-') {
		signb = 1;
	}
	int lengtha = 0;
	int lengthb = 0;
	while (a[lengtha] != '\0') {
		lengtha++;
	}
	while (b[lengthb] != '\0') {
		lengthb++;
	}
	bool nage = false;
	if (signa == 1 && signb == 0) {
		if (operate == '+') {
			char* temp = a;
			a = b;
			b = temp;
			int temp1 = lengtha;
			lengtha = lengthb;
			lengthb = temp1;
			int temp2 = signa;
			signa = signb;
			signb = temp2;
			operate = '-';
		}
		else {
			nage = true;
			operate = '+';
		}
	}
	else if (signa == 0 && signb == 1) {
		if (operate == '+') {
			operate = '-';
		}
		else {
			operate = '+';
		}
	}
	else if (signa == 1 && signb == 1) {
		if (operate == '+') {
			nage = true;
		}
		else {
			char* temp = a;
			a = b;
			b = temp;
			int temp1 = lengtha;
			lengtha = lengthb;
			lengthb = temp1;
			int temp2 = signa;
			signa = signb;
			signb = temp2;
		}
	}
	int up = 0;
	bool aend = false;
	bool bend = false;
	if (operate == '+') {
		if (lengtha - signa >= lengthb - signb) {
			for (int i = lengtha - 1; i >= signa; --i) {
				if (i - lengtha + lengthb >= signb) {
					int temp = (a[i] - '0') + (b[i - lengtha + lengthb] - '0') + up;
					if (temp >= 10) {
						up = 1;
						a[i] = (temp - 10) + '0';
					}
					else {
						up = 0;
						a[i] = temp + '0';
					}
				}
				else{
					bend = true;
					if (up == 1) {
						int temp = (a[i] - '0') + up;
						if (temp >= 10) {
							up = 1;
							a[i] = (temp - 10) + '0';
						}
						else {
							up = 0;
							a[i] = temp + '0';
						}
					}
				}
			}
			if (nage) {
				if (up == 1) {
					cout << "-";
				}
				else {
					for (int i = signa; i < lengtha; ++i) {
						if (a[i] == '0') {
							continue;
						}
						cout << "-";
						break;
					}
				}
			}
			if (up == 1) {
				cout << '1';
			}
			bool zero = true;
			for (int i = signa; i < lengtha; ++i) {
				if ((up == 0) && (a[i] == '0') && zero && (i != lengtha - 1)) {
					continue;
				}
				else if ((a[i] != '0') && zero) {
					zero = false;
				}
				cout << a[i];
			}
		}
		else {
			for (int i = lengthb - 1; i >= signb; --i) {
				if (i - lengthb + lengtha >= signa) {
					int temp = (b[i] - '0') + (a[i - lengthb + lengtha] - '0') + up;
					if (temp >= 10) {
						up = 1;
						b[i] = (temp - 10) + '0';
					}
					else {
						up = 0;
						b[i] = temp + '0';
					}
				}
				else {
					aend = true;
					if (up == 1) {
						int temp = (b[i] - '0') + up;
						if (temp >= 10) {
							up = 1;
							b[i] = (temp - 10) + '0';
						}
						else {
							up = 0;
							b[i] = temp + '0';
						}
					}
				}
			}
			if (nage) {
				if (up == 1) {
					cout << "-";
				}
				else {
					for (int i = signb; i < lengthb; ++i) {
						if (b[i] == '0') {
							continue;
						}
						cout << "-";
						break;
					}
				}
			}
			if (up == 1) {
				cout << '1';
			}
			bool zero = true;
			for (int i = signb; i < lengthb; ++i) {
				if ((up == 0) && (b[i] == '0') && zero && (i != lengthb - 1)) {
					continue;
				}
				else if ((b[i] != '0') && zero) {
					zero = false;
				}
				cout << b[i];
			}
		}
	}
	if (operate == '-') {
		if (lengtha - signa >= lengthb - signb) {
			for (int i = lengtha - 1; i >= signa; --i) {
				if (i - lengtha + lengthb >= signb) {
					int temp = (a[i] - '0') - (b[i - lengtha + lengthb] - '0') - up;
					if (temp < 0) {
						up = 1;
						a[i] = (temp + 10) + '0';
					}
					else {
						up = 0;
						a[i] = temp + '0';
					}
				}
				else {
					bend = true;
					if (up == 1) {
						int temp = (a[i] - '0') - up;
						if (temp < 0) {
							up = 1;
							a[i] = (temp + 10) + '0';
						}
						else {
							up = 0;
							a[i] = temp + '0';
						}
					}
				}
			}
			if (nage) {
				for (int i = signa; i < lengtha; ++i) {
					if (a[i] == '0') {
						continue;
					}
					cout << "-";
					break;
				}
			}
			if (up == 1) {
				cout << '-';
				bool active = false;
				for (int i = lengtha - 1; i >= signa; --i) {
					if (!active && a[i] != '0') {
						a[i] = 10 - (a[i] - '0') + '0';
						active = true;
						continue;
					}
					else if (active) {
						a[i] = 10 - (a[i] - '0') - 1 + '0';
					}
				}
			}
			bool zero = true;
			for (int i = signa; i < lengtha; ++i) {
				if (a[i] == '0' && zero && i != lengtha - 1) {
					continue;
				}
				else if ((a[i] != '0' && zero)) {
					zero = false;
				}
				cout << a[i];
			}
		}
		else {
			char* temp = a;
			a = b;
			b = temp;
			int temp1 = lengtha;
			lengtha = lengthb;
			lengthb = temp1;
			int temp2 = signa;
			signa = signb;
			signb = temp2;
			for (int i = lengtha - 1; i >= signa; --i) {
				if (i - lengtha + lengthb >= signb) {
					int temp = (a[i] - '0') - (b[i - lengtha + lengthb] - '0') - up;
					if (temp < 0) {
						up = 1;
						a[i] = (temp + 10) + '0';
					}
					else {
						up = 0;
						a[i] = temp + '0';
					}
				}
				else {
					bend = true;
					if (up == 1) {
						int temp = (a[i] - '0') - up;
						if (temp < 0) {
							up = 1;
							a[i] = (temp + 10) + '0';
						}
						else {
							up = 0;
							a[i] = temp + '0';
						}
					}
				}
			}
			for (int i = signa; i < lengtha; ++i) {
				if (a[i] == '0') {
					continue;
				}
				cout << "-";
				break;
			}
			bool zero = true;
			for (int i = signa; i < lengtha; ++i) {
				if (a[i] == '0' && zero && i != lengtha - 1) {
					continue;
				}
				else if ((a[i] != '0' && zero)) {
					zero = false;
				}
				cout << a[i];
			}
		}
	}
	return 0;
}