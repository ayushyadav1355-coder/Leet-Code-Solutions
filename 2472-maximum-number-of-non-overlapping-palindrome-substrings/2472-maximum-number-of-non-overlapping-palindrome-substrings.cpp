#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            dp[i + 1] = max(dp[i + 1], dp[i]);

            if (i + k <= n && isPalindrome(s, i, i + k - 1)) {
                dp[i + k] = max(dp[i + k], dp[i] + 1);
            }

            if (i + k + 1 <= n && isPalindrome(s, i, i + k)) {
                dp[i + k + 1] = max(dp[i + k + 1], dp[i] + 1);
            }
        }

        return dp[n];
    }
};