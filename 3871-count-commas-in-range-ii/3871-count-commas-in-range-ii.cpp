class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long threshold = 1000;

        while (n >= threshold) {
            commas += (n - threshold + 1);
            if (threshold > n / 1000) break;
            threshold *= 1000;
        }

        return commas;
    }
};