// Problem:
//
// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// 
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *pre = NULL;

        int left = 0;
        int right = 0;
        int remain = 0;
        while (l1 != NULL || l2 != NULL || remain > 0) {
            left = (l1 == NULL) ? 0 : l1->val;
            right = (l2 == NULL) ? 0 : l2->val;

            if (pre == NULL) {
                pre = head;
                pre->val = (left + right + remain) % 10;
            } else {
                pre->next = new ListNode((left + right + remain) % 10);
                pre = pre->next;
            }
            remain = (left + right + remain) / 10;

            l1 = (l1 == NULL) ? NULL : l1->next;
            l2 = (l2 == NULL) ? NULL : l2->next;
        }
        return head;
    }
};

int main() {
    Solution sol;

    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode(5);

    ListNode *ans = sol.addTwoNumbers(l1, l2);
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
