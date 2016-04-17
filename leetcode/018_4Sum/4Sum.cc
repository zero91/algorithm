// Problem:
//
// Given an array S of n integers, are there elements a, b, c, and d in S
// such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//
// A solution set is:
//   (-1,  0, 0, 1)
//   (-2, -1, 1, 2)
//   (-2,  0, 0, 2)
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution { // time complexity O(n^3)
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        vector<int> quad(4);

        sort(nums.begin(), nums.end());
        int left, right, sum;
        for (int i = 0; i + 3 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            quad[0] = nums[i];
            for (int j = i + 1; j + 2 < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < target) {
                    continue;
                }

                quad[1] = nums[j];
                for (left = j + 1, right = nums.size() - 1; left < right; ) {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        ans.push_back(quad);

                        do { ++left; } while (left <= right && nums[left] == nums[left - 1]);
                        do { --right; } while (right >= left && nums[right] == nums[right] + 1);

                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
