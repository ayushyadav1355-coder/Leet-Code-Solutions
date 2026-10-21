#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // If the string is already sorted, 0 operations are needed.
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // If length is 2 and it's not sorted, any proper substring has length 1.
        // Sorting a substring of length 1 does nothing, so it's impossible.
        if (n == 2) {
            return -1;
        }

        // Check if 1 operation is enough.
        // 1 operation is enough if we can sort either the prefix s[0...n-2] or the suffix s[1...n-1]
        // and have the entire string become sorted.
        
        // Check sorting prefix s[0...n-2]
        char max_prefix = s[0];
        for (int i = 1; i < n - 1; ++i) {
            max_prefix = max(max_prefix, s[i]);
        }
        if (s[n - 1] >= max_prefix) {
            return 1;
        }

        // Check sorting suffix s[1...n-1]
        char min_suffix = s[1];
        for (int i = 2; i < n; ++i) {
            min_suffix = min(min_suffix, s[i]);
        }
        if (s[0] <= min_suffix) {
            return 1;
        }

        // Check if 3 operations are needed.
        // 3 operations are required if and only if:
        // - s[0] is the strict, unique maximum of the entire string, AND
        // - s[n-1] is the strict, unique minimum of the entire string.
        bool s0_is_unique_max = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] >= s[0]) {
                s0_is_unique_max = false;
                break;
            }
        }

        bool sn1_is_unique_min = true;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] <= s[n - 1]) {
                sn1_is_unique_min = false;
                break;
            }
        }

        if (s0_is_unique_max && sn1_is_unique_min) {
            return 3;
        }

        // In all other cases for n >= 3, 2 operations are always sufficient.
        return 2;
    }
};