#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dp(k, 0);
        for (int x : nums) {
            vector<long long> ndp(k, 0);
            int rem = x % k;
            for (int i = 0; i < k; ++i) {
                ndp[(i * rem) % k] += dp[i];
            }
            ndp[rem]++;
            for (int i = 0; i < k; ++i) {
                ans[i] += (dp[i] = ndp[i]);
            }
        }
        return ans;
    }
};