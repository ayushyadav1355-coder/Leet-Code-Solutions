#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        int odd_count = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 != 0) {
                odd_count++;
                odd_char = i;
            }
        }

        if (odd_count > 1) {
            return "";
        }

        int half_len = n / 2;
        vector<int> half_cnt(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_cnt[i] = cnt[i] / 2;
        }

        auto construct_palindrome = [&](const string& first_half) {
            string second_half = first_half;
            reverse(second_half.begin(), second_half.end());
            if (n % 2 != 0) {
                return first_half + (char)('a' + odd_char) + second_half;
            }
            return first_half + second_half;
        };

        bool can_match_prefix = true;
        vector<int> cur_half = half_cnt;
        for (int i = 0; i < half_len; ++i) {
            int char_idx = target[i] - 'a';
            if (cur_half[char_idx] > 0) {
                cur_half[char_idx]--;
            } else {
                can_match_prefix = false;
                break;
            }
        }

        if (can_match_prefix) {
            string candidate = construct_palindrome(target.substr(0, half_len));
            if (candidate > target) {
                return candidate;
            }
        }

        for (int i = half_len - 1; i >= 0; --i) {
            vector<int> available = half_cnt;
            bool prefix_ok = true;
            for (int j = 0; j < i; ++j) {
                int char_idx = target[j] - 'a';
                if (available[char_idx] > 0) {
                    available[char_idx]--;
                } else {
                    prefix_ok = false;
                    break;
                }
            }

            if (!prefix_ok) continue;

            int target_char = target[i] - 'a';
            int next_char = -1;
            for (int c = target_char + 1; c < 26; ++c) {
                if (available[c] > 0) {
                    next_char = c;
                    break;
                }
            }

            if (next_char != -1) {
                string first_half = target.substr(0, i);
                first_half += (char)('a' + next_char);
                available[next_char]--;

                for (int c = 0; c < 26; ++c) {
                    while (available[c] > 0) {
                        first_half += (char)('a' + c);
                        available[c]--;
                    }
                }

                return construct_palindrome(first_half);
            }
        }

        return "";
    }
};