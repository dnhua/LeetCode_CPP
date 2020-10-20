/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
	struct ListNode *next;
};
#define NULL 0

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *slow, *fast, *slowPrev;
	slow = head;
	fast = head;
	slowPrev = NULL;
	int cnt = 0;
	while (++cnt != n) {
		fast = fast->next;
	}

	while (fast->next != NULL) {
		fast = fast->next;
		slowPrev = slow;
		slow = slow->next;
	} 
	if (slowPrev == NULL) {
		head = head->next;
	}
	else {
		slowPrev->next = slow->next;
	}
	return head;
}