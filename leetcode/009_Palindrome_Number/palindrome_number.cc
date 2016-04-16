//
// Prolblem: Determine whether an integer is a palindrome. Do this without extra space.
//
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int right = 0;
        for (int t = x; t > 0; t /= 100) {
            right = right * 10 + x % 10;
            x /= 10;
        }
        if (x < right) x = x * 10 + right % 10;
        return x == right;
    }
};

int main() {
    return 0;
}
