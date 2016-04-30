// Problem:
//
// Given an array of strings, group anagrams together.
//
// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:
//
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:
// For the return value, each inner list's elements must follow the lexicographic order.
// All inputs will be in lower-case.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapper;

        for (auto it = strs.begin(); it != strs.end(); ++it) {
            string t = *it;
            sort(t.begin(), t.end());
            mapper[t].push_back(*it);
        }

        vector<vector<string>> ans;
        for (auto it = mapper.begin(); it != mapper.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            ans.push_back(it->second);
        }
        return ans;
    }
};

int main() {
    return 0;
}
