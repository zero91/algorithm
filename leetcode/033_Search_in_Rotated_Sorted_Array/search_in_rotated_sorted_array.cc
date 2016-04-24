// Problem:
//
// Suppose a sorted array is rotated at some pivot unknown to you before hand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// You are given a target value to search.
// If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }

            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

class Solution_INIT {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        int left_bound = nums.size() - 1;
        if (nums[0] > nums[nums.size() - 1]) {
            while (left + 1 < right) {
                mid = left + (right - left) / 2;
                if (nums[mid] > nums[left]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            left_bound = left;
        }

        if (nums[0] > target) {
            return binary_search(nums, left_bound + 1, nums.size() - 1, target);
        }
        return binary_search(nums, 0, left_bound, target);
    }
private:
    int binary_search(vector<int>& nums, int left, int right, int target) {
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    //vector<int> nums({4, 5, 6, 7, 0, 1, 2}); int target = 1;
    //vector<int> nums({1, 3, 5}); int target = 1;
    //vector<int> nums({3, 5, 1}); int target = 3;
    vector<int> nums({3, 1}); int target = 1;
    Solution sol;

    cout << sol.search(nums, target) << endl;

    return 0;
}
