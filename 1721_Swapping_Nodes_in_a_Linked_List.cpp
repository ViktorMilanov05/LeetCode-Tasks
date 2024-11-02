#include <iostream>
#include <algorithm>

/*You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of 
the kth node from the beginning and the kth node from the end 
(the list is 1-indexed).*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* swapNodes(ListNode* head, int k) {
	ListNode* curr = head;
	ListNode* firstSwap = nullptr;
	ListNode* firstSwapTemp = nullptr;
	int ind = 1;
	while (curr && ind != k) {
		curr = curr->next;
		ind++;
	}
	if (curr) {
		firstSwap = firstSwapTemp = curr;
		curr = head;
		while (firstSwapTemp->next) {
			curr = curr->next;
			firstSwapTemp = firstSwapTemp->next;
		}
		int temp = firstSwap->val;
		firstSwap->val = curr->val;
		curr->val = temp;
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
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	head = swapNodes(head, 2);

	std::cout << "Doubled List: ";
	printList(head);

	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}
