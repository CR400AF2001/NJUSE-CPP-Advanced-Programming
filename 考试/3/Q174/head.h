#pragma once
using namespace std;


class server {
public:
	int id;
	int weight;

	server() {
		id = 0;
		weight = 1;
	}

	server(int myid) {
		id = myid;
		weight = 1;
	}
};

class docker {
public:
	server* a;

	docker(int n) {
		a = new server[n];
		for (int i = 0; i < n; ++i) {
			a[i].id = i + 1;
		}
	}

	void type1(string* request, int m, int n) {
		if (n == 1) {
			for (int i = 0; i < m; ++i) {
				cout << request[i] << " " << 1 << endl;
			}
		}
		else {
			for (int i = 0; i < m; ++i) {
				cout << request[i] << " " << (i % n) + 1 << endl;
			}
		}
	}

	void type2(string* request, int m, int n) {
		int reverse = 0;
		int index = 1;
		if (n == 1) {
			for (int i = 0; i < m; ++i) {
				cout << request[i] << " " << 1 << endl;
			}
		}
		else {
			for (int i = 0; i < m; ++i) {
				if (reverse == 0) {
					cout << request[i] << " " << index << endl;
					index++;
					if (index == n + 1) {
						reverse = 1;
						index -= 2;
					}
				}
				else if (reverse == 1) {
					cout << request[i] << " " << index << endl;
					index--;
					if (index == 0) {
						reverse = 0;
						index += 2;
					}
				}
			}
		}
	}

	void type3(string* request, int m, int n) {
		int flag = 1;
		int sing = 1;
		int doub = 2;
		if (n == 1) {
			for (int i = 0; i < m; ++i) {
				cout << request[i] << " " << 1 << endl;
			}
		}
		else {
			for (int i = 0; i < m; ++i) {
				if (flag == 1) {
					cout << request[i] << " " << sing << endl;
					sing += 2;
					if (sing > n) {
						sing = 1;
						flag = 2;
					}
				}
				else {
					cout << request[i] << " " << doub << endl;
					doub += 2;
					if (doub > n) {
						doub = 2;
						flag = 1;
					}
				}
			}
		}
	}

	void type4(string* request, int m, int n) {
		int index = 1;
		int temp = 0;
		if (n == 1) {
			for (int i = 0; i < m; ++i) {
				cout << request[i] << " " << 1 << endl;
			}
		}
		else {
			for (int i = 0; i < m; ++i) {
				cout << request[i] << " " << index << endl;
				temp++;
				if (temp == a[index - 1].weight) {
					temp = 0;
					index++;
					if (index == n + 1) {
						index = 1;
					}
				}
			}
		}
	}
};