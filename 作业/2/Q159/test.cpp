#include <iostream>
using namespace std;

struct transaction {
	char name[13];
	int time;
	int amount;
	char city[13];
};

bool strcmp(char* s1, char* s2) {
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
	cin >> n;
	transaction *transactions = new transaction[n];
	for (int i = 0; i < n; ++i) {
		cin >> transactions[i].name >> transactions[i].time >> transactions[i].amount >> transactions[i].city;
	}
	cout << "[";
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (transactions[i].amount > 1000) {
			if (count != 0) {
				cout << ",";
			}
			count++;
			cout << "\"" << transactions[i].name << "," << transactions[i].time << "," << transactions[i].amount << "," << transactions[i].city << "\"";
		}
		else {
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}
				if (strcmp(transactions[i].name, transactions[j].name) && !strcmp(transactions[i].city, transactions[j].city) && abs(transactions[i].time - transactions[j].time) <= 60) {
					if (count != 0) {
						cout << ",";
					}
					count++;
					cout << "\"" << transactions[i].name << "," << transactions[i].time << "," << transactions[i].amount << "," << transactions[i].city << "\"";
					break;
				}
			}
		}
	}
	cout << "]" << endl;
	return 0;
}