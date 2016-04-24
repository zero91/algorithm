// Problem:
//
// Given a sorted array and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
//
// You may assume no duplicates in the array.
//
// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[right] < target ? nums.size() : right;
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, int> > vect;

    vect.push_back(make_pair(vector<int>({1, 3, 5, 6}), 5));
    vect.push_back(make_pair(vector<int>({1, 3, 5, 6}), 2));
    vect.push_back(make_pair(vector<int>({1, 3, 5, 6}), 7));
    vect.push_back(make_pair(vector<int>({1, 3, 5, 6}), 0));
    vect.push_back(make_pair(vector<int>({1, 3, 5, 6}), 6));
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        cout << sol.searchInsert(it->first, it->second) << endl;
    }
    return 0;
}
