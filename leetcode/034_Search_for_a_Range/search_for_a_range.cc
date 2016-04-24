// Problem: 
//
// Given a sorted array of integers,
// find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target); 
        auto right = upper_bound(nums.begin(), nums.end(), target);

        vector<int> ans(2, -1);

        if (left < nums.end() && *left == target) {
            ans[0] = left - nums.begin();
            ans[1] = right - nums.begin() - 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}

