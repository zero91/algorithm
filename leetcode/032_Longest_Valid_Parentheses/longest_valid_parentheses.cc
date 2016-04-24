// Problem:
//
// Given a string containing just the characters '(' and ')',
// find the length of the longest valid (well-formed) parentheses substring.
//
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
// Another example is ")()())", where the longest valid parentheses substring is "()()",
// which has length = 4.
//
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(const string& str) {
        stack<int> s;

        int ans = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(' || s.empty() || str[s.top()] == ')') {
                s.push(i);

            } else {
                s.pop();

                if (s.empty()) {
                    ans = max(ans, i + 1);
                } else {
                    ans = max(ans, i - s.top());
                }
            }
        }
        return ans;
    }
};

class Solution_DP {
public:
    int longestValidParentheses(const string& s) {
        int size = s.size();
        int res = 0;

        vector<int> d(size, 0);
        for (int i = 1; i < size; ++i) {
            if (s[i] == ')') {
                int prev = i - 1 - d[i - 1];
                if (prev >= 0 && s[prev] == '(') {
                    d[i] = d[i - 1] + 2;
                    if (prev > 1) {
                        d[i] = d[i] + d[prev - 1];
                    }
                    res = max(res, d[i]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    cout << sol.longestValidParentheses(")()())") << endl;
    cout << sol.longestValidParentheses("") << endl;
    cout << sol.longestValidParentheses("((())") << endl;
    cout << sol.longestValidParentheses("(()()") << endl;
    cout << sol.longestValidParentheses(")()(((())))(") << endl;
    cout << sol.longestValidParentheses("((((((((((") << endl;

    return 0;
}
