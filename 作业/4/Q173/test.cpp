#include <iostream>

using namespace std;

template <class T>
class mylist {
public:
	T* reallist;
	int size;

	mylist() {
		size = 0;
	}
	
	mylist(int n) {
		size = n;
		reallist = new T[size];
	}

	void reverse() {
		for (int i = 0; i < size / 2; ++i) {
			T temp = reallist[i];
			reallist[i] = reallist[size - 1 - i];
			reallist[size - 1 - i] = temp;
		}
	}

	void sort() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size - 1 - i; ++j) {
				if (reallist[j] > reallist[j + 1]) {
					T temp = reallist[j];
					reallist[j] = reallist[j + 1];
					reallist[j + 1] = temp;
				}
			}
		}
	}

	void print() {
		for (int i = 0; i < size; ++i) {
			if (i != 0) {
				cout << " ";
			}
			cout << reallist[i];
		}
		cout << endl;
	}

	int binarysearch(T a) {
		int times = 0;
		int low = 0;
		int high = size - 1;
		while (low <= high) {
			times++;
			int mid = low + (high - low) / 2;
			if (reallist[mid] == a) {
				break;
			}
			else if (reallist[mid] > a) {
				high = mid - 1;
			}
			else if (reallist[mid] < a) {
				low = mid + 1;
			}
		}
		return times;
	}
};

int main() {
	int n;
	char t;
	cin >> n >> t;
	if (t == 'i') {
		int temp;
		mylist<int> alist(n);
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			alist.reallist[i] = temp;
		}
		int target;
		cin >> target;
		alist.reverse();
		alist.print();
		alist.sort();
		alist.print();
		cout << alist.binarysearch(target) << endl;
	}
	else if (t == 'd') {
		double temp;
		mylist<double> alist(n);
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			alist.reallist[i] = temp;
		}
		double target;
		cin >> target;
		alist.reverse();
		alist.print();
		alist.sort();
		alist.print();
		cout << alist.binarysearch(target) << endl;
	}
	else if (t == 'c') {
		char temp;
		mylist<char> alist(n);
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			alist.reallist[i] = temp;
		}
		char target;
		cin >> target;
		alist.reverse();
		alist.print();
		alist.sort();
		alist.print();
		cout << alist.binarysearch(target) << endl;
	}
	return 0;
}