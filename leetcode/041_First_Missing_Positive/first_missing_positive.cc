// Problem: 
//
// Given an unsorted integer array, find the first missing positive integer.
//
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
//
// Your algorithm should run in O(n) time and uses constant space.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;

        for (size_t k = 0; k < nums.size(); ++k) {
            --nums[k];
        }

        for (size_t k = 0; k < nums.size(); ++k) {
            int j = nums[k];
            while (0 <= j && j < nums.size() && nums[j] != j) {
                int t = nums[j];
                nums[j] = j;
                j = t;
            }
        }

        for (size_t k = 0; k < nums.size(); ++k) {
            if (nums[k] != k) {
                return k + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    vector<vector<int>> vect;
    vect.push_back(vector<int>({1, 2, 0}));
    vect.push_back(vector<int>({3, 4, -1, 1}));

    Solution sol;
    for (size_t i = 0; i < vect.size(); ++i) {
        for (size_t j = 0; j < vect[i].size(); ++j) {
            cout << vect[i][j] << " ";
        }
        cout << "-> " << sol.firstMissingPositive(vect[i]) << endl;
    }

    return 0;
}
