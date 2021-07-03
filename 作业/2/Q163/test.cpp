#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	cpp::ListNode* head = cpp::ListNode::construct();
	cpp::ListNode* quick = head;
	cpp::ListNode* slow = head;
	bool cycle = false;
	bool start = true;
	while (quick != NULL) {
		if (!start && quick == slow) {
			cycle = true;
			break;
		}
		start = false;
		slow = slow->next;
		quick = quick->next;
		if (quick != NULL) {
			quick = quick->next;
		}
	}
	if (cycle) {
		cpp::ListNode* temp = slow->next;
		int length = 1;
		while (temp != slow) {
			length++;
			temp = temp->next;
		}
		cout << length << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}