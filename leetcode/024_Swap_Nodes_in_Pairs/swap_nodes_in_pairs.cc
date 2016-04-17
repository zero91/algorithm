// Problem:
//
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space.
// You may not modify the values in the list, only nodes itself can be changed.
//
#include <iostream>


using namespace std;

#ifdef LOCAL
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* tail = head;
        head = head->next;
        tail->next = head->next;
        head->next = tail;

        ListNode* left = NULL;
        ListNode* right = NULL;
        while (tail->next != NULL && tail->next->next != NULL) {
            left = tail->next;
            right = tail->next->next;

            left->next = right->next;
            right->next = left;
            tail->next = right;
            tail = left;
        }
        return head;
    }
};

int main() {

    return 0;
}
