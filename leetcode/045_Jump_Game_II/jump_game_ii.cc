// Problem:
//
// Given an array of non-negative integers,
// you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// For example:
// Given array A = [2,3,1,1,4]
//
// The minimum number of jumps to reach the last index is 2.
// (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note:
//You can assume that you can always reach the last index.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int pos = 0;
        int step = nums[0];
        int reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (pos + 1 >= nums.size()) {
                return i;
            }

            reach = 0;
            for (int j = 1; j <= step; ++j) {
                reach = max(reach, nums[pos + j] - (step - j));
            }
            pos += step;
            step = reach;
        }
        return nums.size() - 1;
    }
};

int main() {
    vector<int> nums({2,3,1,1,4});
    Solution sol;

    cout << sol.jump(nums) << endl;

    return 0;
}
