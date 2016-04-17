// Problem: 
//
// Given a linked list, remove the nth node from the end of list and return its head.
//
// For example,
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *sentinel = head;
        while (--n > 0) {
            sentinel = sentinel->next;
        }

        ListNode* pre_remove = NULL;
        while (sentinel->next != NULL) {
            sentinel = sentinel->next;
            pre_remove = pre_remove == NULL ? head : pre_remove->next;
        }

        if (pre_remove == NULL) {
            ListNode* ans = head->next;
            delete head;
            return ans;

        } else {
            ListNode* del = pre_remove->next;
            pre_remove->next = pre_remove->next->next;
            delete del;
        }
        return head;
    }
};

int main() {
    return 0;
}
