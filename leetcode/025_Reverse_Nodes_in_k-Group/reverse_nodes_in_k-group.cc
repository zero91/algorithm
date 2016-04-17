// Problem:
//
// Given a linked list,
// reverse the nodes of a linked list k at a time and return its modified list.
//
// If the number of nodes is not a multiple of k then left-out nodes in the end
// should remain as it is.
//
// You may not alter the values in the nodes, only nodes itself may be changed.
//
// Only constant memory is allowed.
//
// For example,
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* ktail = NULL;
        ListNode* khead = NULL;

        ListNode* tail = NULL;
        ListNode* ans = NULL;
        ListNode* pre = NULL;
        ListNode* next = NULL;

        while (true) {
            khead = tail == NULL ? head : tail->next;
            ktail = khead;
            for (int i = 1; i < k; ++i) {
                if (ktail == NULL) break;
                ktail = ktail->next;
            }
            if (ktail == NULL) break;

            pre = khead;
            for (ListNode *node = khead->next; node != ktail; ) {
                next = node->next;
                node->next = pre;
                pre = node;
                node = next;
            }

            khead->next = ktail->next;
            ktail->next = pre;

            if (ans == NULL) {
                ans = ktail;
            } else {
                tail->next = ktail;
            }
            tail = khead;
        }
        return ans == NULL ? head : ans;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* pre = head;
    for (int i = 2; i <= 9; ++i) {
        pre->next = new ListNode(i);
        pre = pre->next;
    }

    Solution sol;
    ListNode* ans = sol.reverseKGroup(head, 2);
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}
