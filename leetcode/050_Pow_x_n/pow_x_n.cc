// Problem: 
//
// Implement pow(x, n).
//
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        
        double ans, t;
        long long p = n;
        
        if (p < 0) p = -p;
        
        ans = x, t = 1.0;
        while (p > 1) {
            if (p & 1) t *= ans;
            ans *= ans;
            p >>= 1;
        }
        if (n < 0) return 1.0 / (ans * t);
        return ans * t;
    }
};

int main() {
    return 0;
}
