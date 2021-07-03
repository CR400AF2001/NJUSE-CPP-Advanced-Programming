#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void alloc(char* heap, int* valid, int id, int obsize, int size) {
	int accsize = obsize / 8;
	if (obsize % 8 != 0) {
		accsize += 1;
	}
	if (valid[id] == -1) {
		int index = 0;
		while (index < size) {
			int ksize = 0;
			for (int i = 0; i < 4; ++i) {
				ksize += (unsigned char)heap[index + i];
				if (i != 3) {
					ksize << 8;
				}
			}
			if ((ksize << 31) != 0 || (ksize >> 3) < accsize) {
				ksize = (ksize >> 3) * 8;
				index += (ksize + 8);
				continue;
			}
			else {
				valid[id] = index;
				int newsize = (accsize << 3) + 1;
				for (int i = 0; i < 4; ++i) {
					heap[index + i] = (char)(newsize >> 8 * (3 - i)) & 0x0ff;
				}
				index += (4 + accsize * 8);
				for (int i = 0; i < 4; ++i) {
					heap[index + i] = (char)(newsize >> 8 * (3 - i)) & 0x0ff;
				}
				index += 4;
				if (index < size) {
					int leftsize = (ksize >> 3) - 1 - accsize;
					int shift = 8 * (leftsize)+4;
					leftsize <<= 3;
					for (int i = 0; i < 4; ++i) {
						heap[index + i] = (char)(leftsize >> 8 * (3 - i)) & 0x0ff;
						heap[index + shift + i] = (char)(leftsize >> 8 * (3 - i)) & 0x0ff;
					}
				}
				cout << "succeeded to alloc object " << id << endl;
				return;
			}
		}
	}
	cout << "failed to alloc object " << id << endl;
}

void newfree(char* heap, int* valid, int id) {
	if (valid[id] == -1) {
		cout << "invalid memory access" << endl;
	}
	else {
		int obsize = 0;
		for (int i = 0; i < 4; ++i) {
			obsize += (unsigned char)heap[valid[id] + i];
			if (i != 3) {
				obsize << 8;
			}
		}
		obsize >>= 3;
		obsize *= 8;
		heap[valid[id] + 3] = heap[valid[id] + 3] & 0x0f8;
		heap[valid[id] + 7 + obsize] = heap[valid[id] + 3] & 0x0f8;
		valid[id] = -1;
		cout << "succeeded to free object " << id << endl;
	}
}

void show(char* heap, int size) {
	for (int i = 0; i < size / 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			//printf("%x", heap[4 * i + j]);
			int temp = heap[4 * i + j] & 0x0ff;
			if (temp >> 4 == 0) {
				cout << 0;
			}
			cout << noshowbase << hex << temp;
		}
		cout << endl;
	}
}


int main() {
	int size = 0, num = 0;
	int n = 0;
	cin >> size >> num;
	cin >> n;
	char* heap = new char[size];
	int* valid = new int[num + 1];
	for (int i = 0; i < num + 1; ++i) {
		valid[i] = -1;
	}
	int head = (size - 8) / 8;
	head = head << 3;
	for (int j = 0; j < 4; ++j) {
		heap[j] = (char)((head >> (8 * (3 - j))) & 0x0ff);
		heap[size - 4 + j] = ((head >> (8 * (3 - j))) & 0x0ff);
	}
	for (int j = 4; j < size - 4; ++j) {
		heap[j] = 0x0df;
	}
	for (int i = 0; i < n; ++i) {
		string command;
		cin >> command;
		int id, obsize;
		switch (command[0]) {
			case 'A':
				cin >> id >> obsize;
				alloc(heap, valid, id, obsize, size);
				break;
			case 'F':
				cin >> id;
				newfree(heap, valid, id);
				break;
			case 'S':
				show(heap, size);
				break;
		}
	}
	return 0;
}