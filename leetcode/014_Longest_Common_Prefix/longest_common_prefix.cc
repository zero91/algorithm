// Problem:
//
// Write a function to find the longest common prefix string amongst an array of strings.
// 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        
        string ans;
        for (size_t i = 0; i < strs[0].size(); ++i) {
            for (size_t j = 1; j < strs.size(); ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    return 0;
}
