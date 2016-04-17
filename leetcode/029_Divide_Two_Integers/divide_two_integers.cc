// Problem:
//
// Divide two integers without using multiplication, division and mod operator.
//
// If it is overflow, return MAX_INT.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;

        long long q = dividend;
        long long m = divisor;

        if (q < 0) {
            q = -q;
            sign *= -1;
        }

        if (m < 0) {
            m = -m;
            sign *= -1;
        }

        long long ans = 0;
        long long d = 0;
        while (q >= m) {
            for (d = 1ll; (m << d) <= q; ++d);
            ans |= 1ll << (d - 1);
            q -= (m << (d - 1));
        }

        ans *= sign;
        return (ans > INT_MAX || ans < INT_MIN) ? INT_MAX : ans;
    }
};

int main() {
    Solution sol;

    cout << sol.divide(-2147483648, -1) << endl;
    cout << sol.divide(-1021989372, -82778243) << endl;

    return 0;
}
