#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        vector<int> opened;
        
        for (char c : s) {
            if (c == '(') {
                opened.push_back(res.length());
            } else if (c == ')') {
                int start = opened.back();
                opened.pop_back();
                reverse(res.begin() + start, res.end());
            } else {
                res += c;
            }
        }
        
        return res;
    }
};