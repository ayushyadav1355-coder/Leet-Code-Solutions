#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i) {
            sum += nums[i];
        }
        
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};