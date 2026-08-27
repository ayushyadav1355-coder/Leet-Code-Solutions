#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> total_cnt(26, 0);
        for (char c : s) {
            total_cnt[c - 'a']++;
        }

        vector<int> pref_cnt(26, 0);
        vector<bool> valid_prefix(n + 1, true);
        for (int i = 0; i < n; ++i) {
            pref_cnt[target[i] - 'a']++;
            if (pref_cnt[target[i] - 'a'] > total_cnt[target[i] - 'a']) {
                for (int j = i + 1; j <= n; ++j) {
                    valid_prefix[j] = false;
                }
                break;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (!valid_prefix[i]) continue;

            vector<int> cur_cnt = total_cnt;
            for (int j = 0; j < i; ++j) {
                cur_cnt[target[j] - 'a']--;
            }

            int next_char = -1;
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (cur_cnt[c] > 0) {
                    next_char = c;
                    break;
                }
            }

            if (next_char != -1) {
                string ans = target.substr(0, i);
                ans += (char)('a' + next_char);
                cur_cnt[next_char]--;

                for (int c = 0; c < 26; ++c) {
                    while (cur_cnt[c] > 0) {
                        ans += (char)('a' + c);
                        cur_cnt[c]--;
                    }
                }
                return ans;
            }
        }

        return "";
    }
};