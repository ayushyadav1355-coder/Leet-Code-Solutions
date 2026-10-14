#include <string>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9 * num) {
            return "";
        }
        
        int q = sum / 9;
        int r = sum % 9;
        
        string ans = "";
        ans.reserve(num);
        
        ans.append(q, '9');
        if (r > 0) {
            ans.push_back('0' + r);
        }
        
        int zeros = num - q - (r > 0 ? 1 : 0);
        ans.append(zeros, '0');
        
        return ans;
    }
};