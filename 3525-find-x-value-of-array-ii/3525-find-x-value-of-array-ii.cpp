#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int total;
        int count[5];
        Node() {
            total = 1;
            memset(count, 0, sizeof(count));
        }
    };

    Node merge(const Node& l, const Node& r, int k) {
        Node res;
        res.total = (l.total * r.total) % k;
        for (int i = 0; i < k; ++i) res.count[i] = l.count[i];
        for (int i = 0; i < k; ++i) {
            if (r.count[i]) {
                res.count[(l.total * i) % k] += r.count[i];
            }
        }
        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums, int k, vector<Node>& tree) {
        if (start == end) {
            tree[node].total = nums[start] % k;
            tree[node].count[nums[start] % k] = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, nums, k, tree);
        build(2 * node + 1, mid + 1, end, nums, k, tree);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], k);
    }

    void update(int node, int start, int end, int idx, int val, int k, vector<Node>& tree) {
        if (start == end) {
            tree[node].total = val % k;
            memset(tree[node].count, 0, sizeof(tree[node].count));
            tree[node].count[val % k] = 1;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val, k, tree);
        else update(2 * node + 1, mid + 1, end, idx, val, k, tree);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], k);
    }

    Node query(int node, int start, int end, int l, int r, int k, const vector<Node>& tree) {
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        if (r <= mid) return query(2 * node, start, mid, l, r, k, tree);
        if (l > mid) return query(2 * node + 1, mid + 1, end, l, r, k, tree);
        return merge(query(2 * node, start, mid, l, r, k, tree), 
                     query(2 * node + 1, mid + 1, end, l, r, k, tree), k);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<Node> tree(4 * n);
        build(1, 0, n - 1, nums, k, tree);

        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1], k, tree);
            ans.push_back(query(1, 0, n - 1, q[2], n - 1, k, tree).count[q[3]]);
        }
        return ans;
    }
};