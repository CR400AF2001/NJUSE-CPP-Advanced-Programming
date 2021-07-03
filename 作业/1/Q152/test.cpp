#include <iostream>
using namespace std;

int main() {
	int n;
	int result = 0;
	while (cin >> n) {
		result = n ^ result;
	}
	cout << result << endl;
	return 0;
}