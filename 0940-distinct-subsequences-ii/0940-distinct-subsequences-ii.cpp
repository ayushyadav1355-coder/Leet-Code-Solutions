#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        vector<long long> last_end(26, 0);

        for (char c : s) {
            int idx = c - 'a';
            long long total_previous = 0;
            for (int i = 0; i < 26; ++i) {
                total_previous = (total_previous + last_end[i]) % MOD;
            }
            last_end[idx] = (total_previous + 1) % MOD;
        }

        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + last_end[i]) % MOD;
        }

        return total;
    }
};