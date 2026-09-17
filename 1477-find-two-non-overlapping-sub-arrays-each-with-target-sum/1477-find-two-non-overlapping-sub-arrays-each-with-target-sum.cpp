#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, 1e9);
        int ans = 1e9, sum = 0, l = 0;

        for (int r = 0; r < n; ++r) {
            sum += arr[r];
            while (sum > target) {
                sum -= arr[l++];
            }
            if (sum == target) {
                int len = r - l + 1;
                if (l > 0 && min_len[l - 1] != 1e9) {
                    ans = min(ans, len + min_len[l - 1]);
                }
                min_len[r] = len;
            }
            if (r > 0) {
                min_len[r] = min(min_len[r], min_len[r - 1]);
            }
        }

        return ans > 1e8 ? -1 : ans;
    }
};