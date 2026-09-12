#include <vector>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int total = 0;
        for (int num = 100; num < 1000; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            count[d1]--;
            count[d2]--;
            count[d3]--;

            if (count[d1] >= 0 && count[d2] >= 0 && count[d3] >= 0) {
                total++;
            }

            count[d1]++;
            count[d2]++;
            count[d3]++;
        }

        return total;
    }
};