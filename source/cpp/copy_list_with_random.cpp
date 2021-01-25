struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *copy, *p;
    if (head == NULL) return head;
    for (p=head; p!=NULL; p=p->next) {
        copy = new RandomListNode(p->label);
	copy->next = p->next;
	p->next = copy;
	p = p->next;
    }
    for (p=head; p!=NULL; p=copy->next) {
        copy = p->next;
	copy->random = (p->random != NULL ? p->random : NULL);
    }
    for (p=head,head=copy=p->next; p!= NULL; ) {
        p->next = copy->next;
	p = p->next;
	copy->next = p != NULL ? p->next : NULL;
	copy = copy->next;
    }
    return head;
}
