// Problem: 
//
// Given two numbers represented as strings, return multiplication of the numbers as a string.
//
// Note:
// The numbers can be arbitrarily large and are non-negative.
// Converting the input string to integer is NOT allowed.
// You should NOT use internal library such as BigInteger.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        
        for (int i = 0; i < m; ++i) num1[i] -= '0';
        for (int i = 0; i < n; ++i) num2[i] -= '0';
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int mul[m + n];
        memset(mul, 0, sizeof(mul));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mul[i + j] += num1[i] * num2[j];
            }
        }
        for (int i = 0; i < m + n - 1; ++i) {
            mul[i + 1] += mul[i] / 10;
            mul[i] %= 10;
        }
        
        int p = m + n - 1;
        while (mul[p] == 0) --p;
        
        string ans;
        while (p >= 0) {
            ans += mul[p--] + '0';
        }
        if (ans.size() == 0) ans = "0";
        return ans;
    }
};

int main() {
    return 0;
}
