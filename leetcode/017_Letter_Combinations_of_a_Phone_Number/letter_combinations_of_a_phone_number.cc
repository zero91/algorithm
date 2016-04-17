// Problem: 
//
// Given a digit string, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below.
//
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
// Note:
// Although the above answer is in lexicographical order,
// your answer could be in any order you want.
// 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(const string& digits) {
        vector<string> ans;
        if (digits.size() == 0) {
            return ans;
        }

        char comb[digits.size() + 1];
        comb[digits.size()] = '\0';
        dfs(ans, digits, comb, 0);
        return ans;
    }

private:
    void dfs(vector<string>& ans, const string& digits, char* comb, int pos) {
        if (pos == digits.size()) {
            ans.push_back(comb);
            return;
        }

        for (const char* p = _m_mapping[digits[pos] - '2']; *p != '\0'; ++p) {
            comb[pos] = *p;
            dfs(ans, digits, comb, pos + 1);
        }
    }

private:
    const char* _m_mapping[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main() {
    Solution sol;
    string digits = "";

    vector<string> ans = sol.letterCombinations(digits);
    for (size_t k = 0; k < ans.size(); ++k) {
        cout << ans[k] << endl;
    }
    return 0;
}
