// Problem:
//
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
// (you may want to display this pattern in a fixed font for better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
// 
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int num_rows) {
        if (num_rows <= 1) return s;
        
        int N = s.size();
        int L = 2 * num_rows - 2;

        string ans = "";
        for (int i = 0; i < N; i += L) {
            ans += s[i];
        }
        
        for (int i = 1; i < num_rows - 1; ++i) {
            for (int j = i; j < N; j += L) {
                ans += s[j];
                if ((j - i) + (L - i) < N) ans += s[(j - i) + (L - i)];
            }
        }
        
        for (int i = num_rows - 1; i < N; i += L) {
            ans += s[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.convert("PAYPALISHIRING", 3) << endl;

    return 0;
}
