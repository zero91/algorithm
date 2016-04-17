// Problem:
//
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
//
// The brackets must close in the correct order,
// "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(const string& str) {
        stack<char> s;

        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                s.push(str[i]);
            } else {
                if (s.size() == 0 || (s.top() == '(' && str[i] != ')')
                                  || (s.top() == '[' && str[i] != ']')
                                  || (s.top() == '{' && str[i] != '}')) {
                    return false;
                }
                s.pop();
            }
        }
        return s.size() == 0;
    }
};

int main() {
    Solution sol;

    cout << sol.isValid("()") << endl;

    return 0;
}
