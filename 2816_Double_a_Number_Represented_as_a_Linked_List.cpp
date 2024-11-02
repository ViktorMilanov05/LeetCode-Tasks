#include <iostream>
#include <algorithm>

/*You are given the head of a non-empty linked list representing a 
non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* reverse(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while (curr) {
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

ListNode* doubleIt(ListNode* head) {
	head = reverse(head);
	ListNode* curr = head;
	int doubleVal = head->val * 2;
	head->val = doubleVal % 10;
	int reminder = doubleVal / 10;
	while (curr->next) {
		curr = curr->next;
		doubleVal = curr->val * 2 + reminder;
		curr->val = doubleVal % 10;
		reminder = doubleVal / 10;
	}
	if (reminder > 0) {
		ListNode* last = new ListNode(reminder, nullptr);
		curr->next = last;
	}
	head = reverse(head);
	return head;
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
	head->next = new ListNode(8);
	head->next->next = new ListNode(9);

	head = doubleIt(head);

	std::cout << "Doubled List: ";
	printList(head);

	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}
