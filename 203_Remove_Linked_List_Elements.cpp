#include <iostream>
#include <algorithm>

/*Given the head of a linked list and an integer val, remove all the nodes 
of the linked list that has Node.val == val, and return the new head.*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* removeElements(ListNode* head, int val) {
	ListNode* curr = head;
	ListNode* prev = nullptr;
	while (curr) {
		ListNode* next = curr->next;
		if (curr->val == val) {
			if (prev) {
				prev->next = next;
			}
			else {
				head = next;
			}
			delete curr;
			curr = next;
		}
		else {
			prev = curr;
			curr = next;
		}
	}
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
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(6);
	head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next->next = new ListNode(6);

	head = removeElements(head, 6);

	std::cout << "Doubled List: ";
	printList(head);

	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}
