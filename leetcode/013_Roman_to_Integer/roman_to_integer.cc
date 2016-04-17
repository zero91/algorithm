// Problem:
//
// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        if (s.find("IV") != -1 || s.find("IX") != -1) { sum -= 2; }
        if (s.find("XL") != -1 || s.find("XC") != -1) { sum -= 20; }
        if (s.find("CD") != -1 || s.find("CM") != -1) { sum -= 200; }
        int len = s.length();
        for (int i = 0; i != len; ++i) {
            switch(s[i]) {
                case 'M': sum += 1000; break;
                case 'D': sum += 500; break;
                case 'C': sum += 100; break;
                case 'L': sum += 50; break;
                case 'X': sum += 10; break;
                case 'V': sum += 5; break;
                case 'I': sum += 1; break;
                default: break;
            }
        }
        return sum;
    }

    int romanToInt2(string s) {
        const string roman[] = {"I", "IV", "V", "IX", "X", "XL",
                                "L", "XC", "C", "CD", "D", "CM", "M"};
        const int integer[] =  { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int ans = 0;
        
        for (size_t i = sizeof(integer) / sizeof(integer[0]); i > 0; --i) {
            while (s.size() >= roman[i - 1].size() && s.substr(0, roman[i - 1].size()) == roman[i - 1]) {
                ans += integer[i - 1];
                s = s.substr(roman[i - 1].size());
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
