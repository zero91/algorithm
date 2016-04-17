// Problem:
//
// Given an array S of n integers, find three integers in S such that the sum is closest
// to a given number, target. Return the sum of the three integers. You may assume that
// each input would have exactly one solution.
//
// For example, given array S = {-1 2 1 -4}, and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ans;
        int ans_min = INT_MAX;

        int left, right, t;
        for (size_t k = 0; k < nums.size(); ++k) {
            left = k + 1;
            right = nums.size() - 1;

            while (left < right) {
                t = nums[k] + nums[left] + nums[right] - target;

                if (ans_min > abs(t)) {
                    ans_min = abs(t);
                    ans = t + target;
                }

                if (ans_min == 0) return ans;
                if (t < 0) ++left;
                else --right;
            }
        }
        return ans;
    }
};

int main() {
    int arr[] = {-1, 2, 1, -4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution sol;

    cout << sol.threeSumClosest(nums, 1) << endl;

    return 0;
}
