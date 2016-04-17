// Problem:
//
// Implement strStr().
//
// Returns the index of the first occurrence of needle in haystack,
// or -1 if needle is not part of haystack.
//
#include <iostream>
#include <string>

using namespace std;

class Solution { // Can also using KMP, but not necessary to
public:
    int strStr(const string& haystack, const string& needle) {
        if (needle.size() == 0) return 0;

        for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
            if (strncmp(haystack.c_str() + i, needle.c_str(), needle.size()) == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}
