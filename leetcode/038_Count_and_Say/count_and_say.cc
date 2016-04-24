// Problem: 
//
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.
//
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        ostringstream out;

        string ans = "1";
        for (int i = 1; i < n; ++i) {
            out.str("");

            int cnt = 1;
            for (int j = 1; j < ans.size(); ++j) {
                if (ans[j] == ans[j - 1]) {
                    ++cnt;
                } else {
                    out << cnt << ans[j - 1];
                    cnt = 1;
                }
            }
            out << cnt << ans[ans.size() - 1];
            ans = out.str();
        }

        return ans;
    }
};

int main() {
    Solution sol;

    for (int i = 1; i < 10; ++i) {
        cout << sol.countAndSay(i) << endl;
    }
    return 0;
}
