// Problem:
//
// Given a string S, find the longest palindromic substring in S.
// You may assume that the maximum length of S is 1000, and there
// exists one unique longest palindromic substring.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution { // manachers algorithm, time complexity O(n)
public:
    string longestPalindrome(string s) {
        string ss;
        for (size_t k = 0; k < s.size(); ++k) {
            ss.push_back('#');
            ss.push_back(s[k]);
        }
        ss.push_back('#');

        vector<int> p(ss.size(), 0);
        int mp = 0;
        int mr = 0;
        for (size_t k = 1; k < ss.size(); ++k) {
            if (k <= mr) {
                if (p[2 * mp - k] < mr - k) {
                    p[k] = p[2 * mp - k];
                } else {
                    p[k] = mr - k;
                }
            }

            while (k >= p[k] && k + p[k] < ss.size() && ss[k - p[k]] == ss[k + p[k]]) {
                ++p[k];
            }

            if (k + p[k] > mr) {
                mr = k + p[k];
                mp = k;
            }
        }
        int pos = max_element(p.begin(), p.end()) - p.begin();
        string ans;
        for (int k = pos - p[pos] + 2; k < pos + p[pos]; k += 2) {
            ans += ss[k];
        }
        return ans;
    }
};

class Solution_O2 {
public:
    string longestPalindrome(string s) {
        string ans = "";

        int left, right;
        for (int k = 0; k < s.size(); ++k) {
            left = k - 1;
            right = k + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left, ++right;
            }
            if (ans.size() < right - left - 1) {
                ans = s.substr(left + 1, right - left - 1);
            }

            left = k;
            right = k + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left, ++right;
            }
            if (ans.size() < right - left - 1) {
                ans = s.substr(left + 1, right - left - 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    Solution_O2 sol_o2;

    cout << sol.longestPalindrome("abcxxcba") << "\t"
         << sol_o2.longestPalindrome("abcxxcba") << endl;

    cout << sol.longestPalindrome("abcxycba") << "\t"
         << sol_o2.longestPalindrome("abcxycba") << endl;

    cout << sol.longestPalindrome("abcdeffedcba") << "\t"
         << sol_o2.longestPalindrome("abcdeffedcba") << endl;

    cout << sol.longestPalindrome("abcdefedcba") << "\t"
         << sol_o2.longestPalindrome("abcdefedcba") << endl;

    return 0;
}
