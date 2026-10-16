#include <vector>
#include <cstdint>

using namespace std;

class Solution {
    int64_t tree_sq[400005];
    int64_t tree_sum[400005];
    int64_t lazy[400005];
    const int MOD = 1000000007;

    void push_down(int p, int L_len, int R_len) {
        if (lazy[p]) {
            int64_t v = lazy[p];
            
            tree_sq[2*p] = (tree_sq[2*p] + 2 * v % MOD * tree_sum[2*p] % MOD + (int64_t)L_len * (v * v % MOD) % MOD) % MOD;
            tree_sum[2*p] = (tree_sum[2*p] + (int64_t)L_len * v % MOD) % MOD;
            lazy[2*p] = (lazy[2*p] + v) % MOD;
            
            tree_sq[2*p+1] = (tree_sq[2*p+1] + 2 * v % MOD * tree_sum[2*p+1] % MOD + (int64_t)R_len * (v * v % MOD) % MOD) % MOD;
            tree_sum[2*p+1] = (tree_sum[2*p+1] + (int64_t)R_len * v % MOD) % MOD;
            lazy[2*p+1] = (lazy[2*p+1] + v) % MOD;
            
            lazy[p] = 0;
        }
    }

    void update(int p, int node_L, int node_R, int query_L, int query_R) {
        if (query_L <= node_L && node_R <= query_R) {
            int64_t len = node_R - node_L + 1;
            tree_sq[p] = (tree_sq[p] + 2 * tree_sum[p] % MOD + len) % MOD;
            tree_sum[p] = (tree_sum[p] + len) % MOD;
            lazy[p] = (lazy[p] + 1) % MOD;
            return;
        }
        int mid = (node_L + node_R) / 2;
        push_down(p, mid - node_L + 1, node_R - mid);
        if (query_L <= mid) {
            update(2 * p, node_L, mid, query_L, query_R);
        }
        if (query_R > mid) {
            update(2 * p + 1, mid + 1, node_R, query_L, query_R);
        }
        tree_sq[p] = (tree_sq[2*p] + tree_sq[2*p+1]) % MOD;
        tree_sum[p] = (tree_sum[2*p] + tree_sum[2*p+1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= 4 * n; ++i) {
            tree_sq[i] = 0;
            tree_sum[i] = 0;
            lazy[i] = 0;
        }
        
        vector<int> last(100005, -1);
        int64_t total_ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int l = last[nums[i]];
            
            update(1, 0, n - 1, l + 1, i);
            
            total_ans = (total_ans + tree_sq[1]) % MOD;
            last[nums[i]] = i;
        }
        
        return total_ans;
    }
};