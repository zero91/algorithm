// Problem:
// 
// Given an array of integers, return indices of the two numbers such that they add up
// to a specific target.
//
// You may assume that each input would have exactly one solution
// 
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> target_elements; 
        vector<int> ans;

        for (size_t k = 0; k < nums.size(); ++k) {
            if (target_elements.find(target - nums[k]) == target_elements.end()) {
                target_elements[nums[k]] = k;
            } else {
                ans.push_back(target_elements[target - nums[k]]);
                ans.push_back(k);
                return ans;
            }
        }
        return ans;
    }
};

class Solution_2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, size_t> > vect;
        vector<int> ans;

        for (size_t k = 0; k < nums.size(); ++k) {
            vect.push_back(make_pair(nums[k], k));
        }
        sort(vect.begin(), vect.end());

        size_t i = 0;
        size_t j = vect.size();

        while (i + 1 < j) {
            if (vect[i].first + vect[j - 1].first == target) {
                ans.push_back(vect[i].second);
                ans.push_back(vect[j - 1].second);
                break;
            } else if (vect[i].first + vect[j - 1].first > target) {
                --j;
            } else {
                ++i;
            }
        }
        return ans;
    }
};

int main() {
    int arr[] = {2, 7, 11, 15};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    Solution sol;
    vector<int> ans = sol.twoSum(nums, 9);

    for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
