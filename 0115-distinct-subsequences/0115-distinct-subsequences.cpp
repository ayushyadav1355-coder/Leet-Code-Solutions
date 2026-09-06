#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n) return 0;

        // dp[j] stores the number of subsequences of s prefix matching t[0..j-1]
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = min(i + 1, n); j >= 1; --j) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};