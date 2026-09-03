#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        for (int x : nums1) {
            if (x % 2 != 0) {
                min_odd = min(min_odd, x);
            }
        }

        // If no odd exists, everything is even, so we can keep nums2 = nums1
        if (min_odd == INT_MAX) {
            return true;
        }

        // To make everything odd, every even number x must satisfy x - y >= 1 
        // with some odd number y. The best candidate is the minimum odd number.
        for (int x : nums1) {
            if (x % 2 == 0 && x < min_odd) {
                return false;
            }
        }

        return true;
    }
};