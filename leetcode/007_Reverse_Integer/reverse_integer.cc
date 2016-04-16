// Problem:
//
// Reverse digits of an integer.
// 
// Example1: x = 123, return 321
// Example2: x = -123, return -321
//
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int negative = x < 0 ? -1 : 1;
        long long rx = 0;

        x = abs(x);
        while (x != 0) {
            rx = rx * 10 + x % 10;
            x /= 10;
        }

        if (rx > INT_MAX || rx < INT_MIN) {
            return 0;
        }
        return negative * rx;
    }
};

int main() {
    Solution sol;

    cout << sol.reverse(-2147483648) << endl;
    cout << sol.reverse(-43829233) << endl;
    cout << sol.reverse(1000) << endl;
    cout << sol.reverse(-1000) << endl;

    return 0;
}
