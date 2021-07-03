#include <iostream>
#include <vector>
using namespace std;

class restangle {
public:
	int id;
	int r;
	int g;
	int b;
	double gray;

	restangle(){}

	restangle(int thisid){
		id = thisid;
		r = 0;
		g = 0;
		b = 0;
	}

	virtual void set(int thisr, int thisg, int thisb) {
		r = thisr;
		g = thisg;
		b = thisb;
		gray = r * 0.299 + g * 0.587 + b * 0.114;
	}
};

class normal : public restangle {
public:
	normal(int thisid){
		id = thisid;
		r = 0;
		g = 0;
		b = 0;
	}
};

class Reverse : public restangle {
public:
	Reverse(int thisid) {
		id = thisid;
		r = 0;
		g = 0;
		b = 0;
	}

	void set(int thisr, int thisg, int thisb) {
		r = 255 - thisr;
		g = 255 - thisg;
		b = 255 - thisb;
		gray = r * 0.299 + g * 0.587 + b * 0.114;
	}
};

class single : public restangle {
public:
	single(int thisid) {
		id = thisid;
		r = 0;
		g = 0;
		b = 0;
	}

	void set(int thisr, int thisg, int thisb) {
		r = thisr;
		g = 0;
		b = 0;
		gray = r * 0.299 + g * 0.587 + b * 0.114;
	}
};

class group {
public:
	int id;
	int size;
	restangle* restanglegroup[100];

	group() {}

	group(int thisid) {
		id = thisid;
		size = 0;
	}

	void add(restangle* thisrestangle) {
		restanglegroup[size++] = thisrestangle;
	}

	void set(int thisr, int thisg, int thisb) {
		for (int i = 0; i < size; ++i) {
			restanglegroup[i]->set(thisr, thisg, thisb);
		}
	}
};

int main() {
	int n = 0;
	cin >> n;
	cin.get();
	char input[100];
	restangle* restanglelist[100];
	group* grouplist[100];
	int len = 0;
	int grouplen = 0;
	for (int i = 0; i < n; ++i) {
		cin.getline(input, 100);
		if (input[0] == 'A') {
			if (input[4] == 'n') {
				int j = 12;
				int id = 0;
				while (input[j] != '\0') {
					id = id * 10 + (input[j] - '0');
					j++;
				}
				normal* temp = new normal(id);
				restanglelist[len] = temp;
				len++;
			}
			else if(input[4] == 's') {
				int j = 12;
				int id = 0;
				while (input[j] != '\0') {
					id = id * 10 + (input[j] - '0');
					j++;
				}
				single* temp = new single(id);
				restanglelist[len] = temp;
				len++;
			}
			else if (input[4] == 'r') {
				int j = 13;
				int id = 0;
				while (input[j] != '\0') {
					id = id * 10 + (input[j] - '0');
					j++;
				}
				Reverse* temp = new Reverse(id);
				restanglelist[len] = temp;
				len++;
			}
		}
		else if (input[0] == 'S') {
			if (input[4] == 'P') {
				int j = 5;
				int id = 0;
				while (input[j] != ' ') {
					id = id * 10 + (input[j] - '0');
					j++;
				}
				int r = 0;
				int g = 0;
				int b = 0;
				j++;
				while (input[j] != ' ') {
					r = r * 10 + (input[j] - '0');
					j++;
				}
				j++;
				while (input[j] != ' ') {
					g = g * 10 + (input[j] - '0');
					j++;
				}
				j++;
				while (input[j] != '\0') {
					b = b * 10 + (input[j] - '0');
					j++;
				}
				for (int i = 0; i < len; i++) {
					if (restanglelist[i]->id == id) {
						restanglelist[i]->set(r, g, b);
						break;
					}
				}
			}
			else if (input[4] == 'G') {
				int j = 5;
				int id = 0;
				while (input[j] != ' ') {
					id = id * 10 + (input[j] - '0');
					j++;
				}
				int r = 0;
				int g = 0;
				int b = 0;
				j++;
				while (input[j] != ' ') {
					r = r * 10 + (input[j] - '0');
					j++;
				}
				j++;
				while (input[j] != ' ') {
					g = g * 10 + (input[j] - '0');
					j++;
				}
				j++;
				while (input[j] != '\0') {
					b = b * 10 + (input[j] - '0');
					j++;
				}
				for (int i = 0; i < grouplen; i++) {
					if (grouplist[i]->id == id) {
						grouplist[i]->set(r, g, b);
						break;
					}
				}
			}
		}
		else if (input[0] == 'G') {
			int j = 6;
			int n = 0;
			while (input[j] != ' ') {
				n = n * 10 + (input[j] - '0');
				j++;
			}
			vector<int> numlist(n);
			for (int i = 0; i < n; ++i) {
				j += 2;
				int tempnum = 0;
				while (input[j] != ' ') {
					tempnum = tempnum * 10 + (input[j] - '0');
					j++;
				}
				numlist[i] = tempnum;
			}
			j += 2;
			int groupid = 0;
			while (input[j] != '\0') {
				groupid = groupid * 10 + (input[j] - '0');
				j++;
			}
			group* tempgroup = new group(groupid);
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < len; j++) {
					if (restanglelist[j]->id == numlist[i]) {
						tempgroup->add(restanglelist[j]);
						break;
					}
				}
			}
			grouplist[grouplen++] = tempgroup;
		}
	}
	cin.getline(input, 100);
	if (input[0] == 'N') {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (restanglelist[i]->id > restanglelist[j]->id) {
					restangle *temp = restanglelist[i];
					restanglelist[i] = restanglelist[j];
					restanglelist[j] = temp;
				}
			}
		}
	}
	else if (input[0] == 'G') {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (restanglelist[i]->gray > restanglelist[j]->gray) {
					restangle* temp = restanglelist[i];
					restanglelist[i] = restanglelist[j];
					restanglelist[j] = temp;
				}
				else if (restanglelist[i]->gray == restanglelist[j]->gray && restanglelist[i]->id > restanglelist[j]->id) {
					restangle* temp = restanglelist[i];
					restanglelist[i] = restanglelist[j];
					restanglelist[j] = temp;
				}
			}
		}
	}
	for (int i = 0; i < len; i++) {
		cout << "P" << restanglelist[i]->id << " " << restanglelist[i]->r << " " << restanglelist[i]->g << " " << restanglelist[i]->b;
		if (i != len - 1) {
			cout << endl;
		}
	}
	return 0;
}