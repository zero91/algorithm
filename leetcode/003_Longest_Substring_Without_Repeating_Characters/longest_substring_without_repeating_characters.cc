#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pre[256];
        for (size_t k = 0; k < sizeof(pre) / sizeof(pre[0]); ++k) {
            pre[k] = -1;
        }

        int max_length = 0;
        int begin = 0;
        for (size_t k = 0; k < s.size(); ++k) {
            begin = max(begin, pre[s[k]] + 1);
            pre[s[k]] = k;
            max_length = max(max_length, static_cast<int>(k - begin + 1));
        }
        return max_length;
    }
};

int main() {
    Solution sol;

    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sol.lengthOfLongestSubstring("aab") << endl;
    cout << sol.lengthOfLongestSubstring("dvdf") << endl;
    cout << sol.lengthOfLongestSubstring("eee") << endl;

    return 0;
}
