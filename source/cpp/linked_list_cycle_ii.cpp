#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode  *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return NULL;
    }
    ListNode *fast = head, *slow = head;
    do{
        if (fast == NULL || fast->next == NULL) {
	    return NULL;
	}
        slow = slow->next;
	fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while (fast != slow) {
        slow = slow->next;
	fast = fast->next;
    }
    return slow;
}
