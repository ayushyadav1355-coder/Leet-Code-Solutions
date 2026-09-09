#include <algorithm>

using namespace std;

class Solution {
public:
    int countCommas(int n) {
        int commas = 0;
        long long threshold = 1000;

        while (n >= threshold) {
            commas += (n - threshold + 1);
            threshold *= 1000;
        }

        return commas;
    }
};