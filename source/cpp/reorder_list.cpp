#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return ;
    }
    //使用快慢指针找到中间节点
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
	fast = fast->next->next;
    }

    //将原来的链表分成两部分
    ListNode *mid = slow->next;
    slow->next = NULL;
    ListNode *last = mid, *pre = NULL;
    while(last) {
        ListNode *next = last->next;
	last->next = pre;
	pre = last;
	last = next;
    }

    while (head && pre) {
        ListNode *next = head->next;
	head->next = pre;
	pre = pre->next;
	head->next->next = next;
	head = next;
    }
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    reorderList(head);
    while (head) {
        cout << head->val << endl;
	head = head->next;
    }
    return 0;
}
