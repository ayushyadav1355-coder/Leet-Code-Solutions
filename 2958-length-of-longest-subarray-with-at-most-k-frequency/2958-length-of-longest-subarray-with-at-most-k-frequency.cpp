#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int ans = 0, l = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            count[nums[r]]++;
            while (count[nums[r]] > k) {
                count[nums[l++]]--;
            }
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};