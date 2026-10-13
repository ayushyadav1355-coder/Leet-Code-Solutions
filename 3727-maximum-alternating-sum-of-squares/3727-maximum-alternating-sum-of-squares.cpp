#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; ++i) {
            sq[i] = (long long)nums[i] * nums[i];
        }
        sort(sq.rbegin(), sq.rend());
        
        long long score = 0;
        int add_count = (n + 1) / 2;
        
        for (int i = 0; i < add_count; ++i) {
            score += sq[i];
        }
        for (int i = add_count; i < n; ++i) {
            score -= sq[i];
        }
        
        return score;
    }
};