#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        struct Element {
            int val;
            int digit_sum;
            int orig_idx;
        };
        
        vector<Element> arr(n);
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            int temp = nums[i];
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            arr[i] = {nums[i], sum, i};
        }
        
        sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.digit_sum != b.digit_sum) {
                return a.digit_sum < b.digit_sum;
            }
            return a.val < b.val;
        });
        
        int swaps = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].orig_idx == i) {
                continue;
            }
            
            int cycle_size = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].orig_idx;
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += cycle_size - 1;
            }
        }
        
        return swaps;
    }
};
