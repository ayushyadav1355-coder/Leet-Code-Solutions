#include <vector>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) return false;
        
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        
        int max_bal = (m + n) / 2;
        
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(max_bal + 1, false)));
        
        dp[0][0][1] = true; 
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int bal = 0; bal <= max_bal; ++bal) {
                    if (!dp[r][c][bal]) continue;
                    
                    if (c + 1 < n) {
                        int next_bal = bal + (grid[r][c + 1] == '(' ? 1 : -1);
                        if (next_bal >= 0 && next_bal <= max_bal) {
                            dp[r][c + 1][next_bal] = true;
                        }
                    }
                    
                    if (r + 1 < m) {
                        int next_bal = bal + (grid[r + 1][c] == '(' ? 1 : -1);
                        if (next_bal >= 0 && next_bal <= max_bal) {
                            dp[r + 1][c][next_bal] = true;
                        }
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1][0];
    }
};