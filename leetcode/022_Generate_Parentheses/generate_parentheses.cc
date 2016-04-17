// Problem:
//
// Given n pairs of parentheses,
// write a function to generate all combinations of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// "((()))", "(()())", "(())()", "()(())", "()()()"
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        char parentheses[(n << 1) | 1];
        parentheses[n << 1] = '\0';
        dfs(ans, parentheses, n, n, 0);

        return ans;
    }

private:
    void dfs(vector<string>& ans, char* parentheses, int left, int right, int pos) {
        if (left == 0) {
            while (right-- > 0) { parentheses[pos++] = ')'; }
            ans.push_back(parentheses);
            return;
        }

        parentheses[pos] = '(';
        dfs(ans, parentheses, left - 1, right, pos + 1);

        if (left < right) {
            parentheses[pos] = ')';
            dfs(ans, parentheses, left, right - 1, pos + 1);
        }
    }
};

int main() {
    Solution sol;
    vector<string> ans;

    ans = sol.generateParenthesis(3);
    for (auto parentheses : ans) {
        cout << parentheses << endl;
    }

    return 0;
}
