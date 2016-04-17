// Problem:
//
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
//
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//
// For example, given array S = {-1 0 1 2 -1 -4},
//
// A solution set is:
//  (-1, 0, 1)
//  (-1, -1, 2)
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;

        int triplet[3];
        int left, right;
        for (size_t k = 0; k < nums.size(); ++k) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            left = k + 1;
            right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[k] == 0) {
                    triplet[0] = nums[k];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    ans.push_back(vector<int>(triplet,
                            triplet + sizeof(triplet) / sizeof(triplet[0])));

                    do { ++left; } while (left <= right && nums[left] == nums[left - 1]);
                    do { --right; } while (right >= left && nums[right] == nums[right + 1]);

                } else if (nums[left] + nums[right] > -nums[k]) {
                    --right;

                } else {
                    ++left;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    //int arr[] = {-1, 0, 1, 2, -1, -4};
    //int arr[] = {-2, 0, 1, 1, 2};
    int arr[] = {-2, 0, 0, 2, 2};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    vector<vector<int> > ans = sol.threeSum(nums);
    for (size_t k = 0; k < ans.size(); ++k) {
        for (size_t i = 0; i < ans[k].size(); ++i) {
            cout << ans[k][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
