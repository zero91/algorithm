// Problem:
//
// Given an integer, convert it to a roman numeral.
//
// Input is guaranteed to be within the range from 1 to 3999.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }

    string intToRoman2(int num) {
        const string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC",
                                "C", "CD", "D", "CM", "M"};
        const int integer[] =  { 1,    4,   5,    9,   10,  40,   50,  90,
                                100, 400, 500, 900,  1000};

        string ans;
        for (size_t i = sizeof(integer) / sizeof(integer[0]); i > 0; --i) {
            while (num >= integer[i - 1]) {
                ans += roman[i - 1];
                num -= integer[i - 1];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.intToRoman(12) << endl;

    return 0;
}
