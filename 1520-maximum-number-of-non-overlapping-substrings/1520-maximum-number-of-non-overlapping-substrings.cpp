#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26, 1e9), r(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }
        
        vector<pair<int, int>> v;
        for (int i = 0; i < 26; ++i) {
            if (l[i] == 1e9) continue;
            int right = r[i];
            bool ok = true;
            for (int j = l[i]; j <= right; ++j) {
                if (l[s[j] - 'a'] < l[i]) { 
                    ok = false; 
                    break; 
                }
                right = max(right, r[s[j] - 'a']);
            }
            if (ok) v.push_back({right, l[i]});
        }
        
        sort(v.begin(), v.end());
        vector<string> ans;
        int last = -1;
        for (auto [right, left] : v) {
            if (left > last) {
                ans.push_back(s.substr(left, right - left + 1));
                last = right;
            }
        }
        
        return ans;
    }
};