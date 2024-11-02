#include <iostream>
#include <algorithm>

/*Given the head of a linked list and a value x, partition it such 
that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes 
in each of the two partitions.*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* partition(ListNode* head, int x) {
	ListNode before(0);
	ListNode after(0);
	ListNode* beforeCurr = &before;
	ListNode* afterCurr = &after;
	while (head) {
		if (head->val < x) {
			beforeCurr->next = head;
			beforeCurr = beforeCurr->next;
		}
		else {
			afterCurr->next = head;
			afterCurr = afterCurr->next;
		}
		head = head->next;
	}
	afterCurr->next = nullptr;
	beforeCurr->next = after.next;
	return before.next;
}

void printList(ListNode* head) {
	while (head) {
		std::cout << head->val;
		if (head->next) std::cout << " -> ";
		head = head->next;
	}
	std::cout << std::endl;
}

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);

	head = partition(head, 2);

	std::cout << "Doubled List: ";
	printList(head);

	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}
