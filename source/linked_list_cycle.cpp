#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return false;
    }
    ListNode *fast = head, *slow = head;
    do{
        if (fast == NULL || fast->next == NULL) {
	    return false;
	}
        slow = slow->next;
	fast = fast->next->next;
    } while (slow != fast);
    return true;
}
