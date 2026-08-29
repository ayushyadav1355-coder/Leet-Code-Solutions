#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }

        sort(sorted_nums.begin(), sorted_nums.end());

        vector<int> ans(n);
        int i = 0;
        while (i < n) {
            int j = i;
            vector<int> indices = {sorted_nums[i].second};
            while (j + 1 < n && sorted_nums[j + 1].first - sorted_nums[j].first <= limit) {
                j++;
                indices.push_back(sorted_nums[j].second);
            }

            sort(indices.begin(), indices.end());

            for (int k = 0; k < indices.size(); ++k) {
                ans[indices[k]] = sorted_nums[i + k].first;
            }

            i = j + 1;
        }

        return ans;
    }
};