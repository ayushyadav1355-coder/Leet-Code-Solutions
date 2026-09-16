
#include <vector>

using namespace std;

class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long long num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % 1000000007;
            den = (den * (i + 1)) % 1000000007;
        }
        return (num * modInverse(den)) % 1000000007;
    }

public:
    int numberOfSets(int n, int k) {
        return nCr(n + k - 1, 2 * k);
    }
};