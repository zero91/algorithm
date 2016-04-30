// Problem:
//
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
//
// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        vector<int> lmax(height.size(), height[0]);
        vector<int> rmax(height.size(), height[height.size() - 1]);

        for (int i = 1; i < height.size(); ++i) {
            lmax[i] = max(height[i], lmax[i - 1]);
        }

        for (int i = height.size() - 2; i >= 0; --i) {
            rmax[i] = max(height[i], rmax[i + 1]);
        }

        int ans = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            ans += max(0, min(lmax[i - 1], rmax[i + 1]) - height[i]);
        }
        return ans;
    }
};

class Solution_Stack {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            int pre_height = 0;
            while (!s.empty() && height[s.top()] <= height[i]) {
                ans += (i - s.top() - 1) * (height[s.top()] - pre_height);
                pre_height = height[s.top()];
                s.pop();
            }

            if (!s.empty()) {
                ans += (i - s.top() - 1) * (height[i] - pre_height);
            }
            s.push(i);
        }
        return ans;
    }
};

int main() {
    vector<int> height({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    Solution sol;
    //Solution_Easy sol;

    cout << sol.trap(height) << endl;

    return 0;
}
