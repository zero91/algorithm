// Problem:
//
// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ListNodeCmp {
public:
    bool operator()(const ListNode* left, const ListNode* right) {
        return left->val > right->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> q;

        for (auto l : lists) {
            if (l != NULL) {
                q.push(l);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        ListNode* t = NULL;
        while (!q.empty()) {
            t = q.top();

            if (head == NULL) {
                head = t;
                tail = t;
            } else {
                tail->next = t;
                tail = tail->next;
            }
            q.pop();
            if (t->next != NULL) {
                q.push(t->next);
            }
        }
        return head;
    }
};

int main() {

    return 0;
}
