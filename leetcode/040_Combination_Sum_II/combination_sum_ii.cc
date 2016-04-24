// Problem:
//
// Given a collection of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// Each number in C may only be used once in the combination.
//
// Note:
// All numbers (including target) will be positive integers.
//
// Elements in a combination (a1, a2, … , ak) must be in non-descending order.
// (ie, a1 ≤ a2 ≤ … ≤ ak).
//
// The solution set must not contain duplicate combinations.
//
// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
//
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6] 
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if (candidates.size() == 0) return ans;

        sort(candidates.begin(), candidates.end());

        vector<pair<int, int>> cand;
        int cnt = 1;
        for (int i = 1; i < candidates.size(); ++i) {
            if (candidates[i] == candidates[i - 1]) {
                ++cnt;
            } else {
                cand.push_back(make_pair(candidates[i - 1], cnt));
                cnt = 1;
            }
        }
        cand.push_back(make_pair(candidates[candidates.size() - 1], cnt));

        vector<int> comb;
        search(ans, cand, comb, 0, target);
        return ans;
    }

private:
    void search(vector<vector<int>>& ans,
                vector<pair<int, int>>& candidates,
                vector<int>& comb,
                int pos,
                int target) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (pos >= candidates.size() || target < 0) return;

        for (int i = 0; i <= candidates[pos].second; ++i) {
            if (i > 0) comb.push_back(candidates[pos].first);
            search(ans, candidates, comb, pos + 1, target - i * candidates[pos].first);
        }

        for (int i = 1; i <= candidates[pos].second; ++i) {
            comb.pop_back();
        }
    }
};

int main() {

    return 0;
}
