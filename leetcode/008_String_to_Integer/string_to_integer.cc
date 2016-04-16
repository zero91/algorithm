// Problem:
//
// Implement atoi to convert a string to an integer.
//
// Hint: Carefully consider all possible input cases.
// If you want a challenge, please do not see below and ask yourself
// what are the possible input cases.
//
// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
// You are responsible to gather all the input requirements up front.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        int negetive = 1;

        size_t k = 0;
        while (k < str.size() && isspace(str[k])) {
            ++k;
        }
        if (k < str.size() && (str[k] == '-' || str[k] == '+')) {
            if (str[k] == '-') {
                negetive = -1;
            }
            ++k;
        }

        while (k < str.size() && isdigit(str[k])) {
            ans = ans * 10 + str[k] - '0';
            if (negetive * ans > INT_MAX) return INT_MAX;
            if (negetive * ans < INT_MIN) return INT_MIN;
            ++k;
        }
        return ans * negetive;
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("1234") << endl;
    cout << sol.myAtoi("2147483648") << endl;
    cout << sol.myAtoi("-2147483648") << endl;
    cout << sol.myAtoi("-2147483647") << endl;
    cout << sol.myAtoi("-32147483647") << endl;
    cout << sol.myAtoi("-a2147483647") << endl;

    return 0;
}
