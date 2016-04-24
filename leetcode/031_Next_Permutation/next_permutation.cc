// Problem: 
//
// Implement next permutation,
// which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible,
// it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place, do not allocate extra memory.
//
// Here are some examples.
// Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 →1,3,2
// 3,2,1 →1,2,3
// 1,1,5 →1,5,1
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int reverse_idx = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
            reverse_idx = i;
        }

        if (reverse_idx > 0) {
            for (int i = nums.size() - 1; i >= 0; --i) {
                if (nums[i] > nums[reverse_idx - 1]) {
                    swap(nums[i], nums[reverse_idx - 1]);
                    break;
                }
            }
        }
        int left = reverse_idx;
        int right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            ++left, --right;
        }
    }
};

int main() {

    return 0;
}
