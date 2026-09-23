#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        
        int max_len = -1, sum = 0, l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum > target && l <= r) {
                sum -= nums[l++];
            }
            if (sum == target) {
                max_len = max(max_len, r - l + 1);
            }
        }
        
        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};