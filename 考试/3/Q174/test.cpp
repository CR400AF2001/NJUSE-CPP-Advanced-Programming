#include <iostream>
#include "head.h"

using namespace std;

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	docker mydocker(n);
	if (s == 4) {
		for (int i = 0; i < n; ++i) {
			int temp;
			cin >> temp;
			mydocker.a[i].weight = temp;
		}
	}
	string* request = new string[m];
	for (int i = 0; i < m; ++i) {
		cin >> request[i];
	}
	if (s == 1) {
		mydocker.type1(request, m, n);
	}
	else if (s == 2) {
		mydocker.type2(request, m, n);
	}
	else if (s == 3) {
		mydocker.type3(request, m, n);
	}
	else if (s == 4) {
		mydocker.type4(request, m, n);
	}
	return 0;
}