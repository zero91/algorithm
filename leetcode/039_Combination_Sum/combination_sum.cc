// Problem: 
//
// Given a set of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// The same repeated number may be chosen from C unlimited number of times.
//
// Note:
// All numbers (including target) will be positive integers.
//
// Elements in a combination (a1, a2, … , ak) must be in non-descending order.
// (ie, a1 ≤ a2 ≤ … ≤ ak).
//
// The solution set must not contain duplicate combinations.
//
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
//
// [7] 
// [2, 2, 3] 
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        sort(candidates.begin(), candidates.end());
        search(ans, candidates, comb, 0, target);
        return ans;
    }

private:
    void search(vector<vector<int>>& ans,
                const vector<int>& candidates,
                vector<int>& comb,
                int pos,
                int target) {

        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (target < 0 || pos >= candidates.size()) return;

        for (int i = 0; i * candidates[pos] <= target; ++i) {
            if (i > 0) comb.push_back(candidates[pos]);
            search(ans, candidates, comb, pos + 1, target - i * candidates[pos]);
        }
        for (int i = 1; i * candidates[pos] <= target; ++i) comb.pop_back();
    }
};

int main() {

    return 0;
}
