#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int m, p, s, len;
        char pc, sc;
    };
    
    Node merge(const Node& l, const Node& r) {
        return {
            max({l.m, r.m, l.sc == r.pc ? l.s + r.p : 0}),
            l.p == l.len && l.sc == r.pc ? l.len + r.p : l.p,
            r.s == r.len && l.sc == r.pc ? r.len + l.s : r.s,
            l.len + r.len,
            l.pc,
            r.sc
        };
    }
    
    void build(int node, int start, int end, const string& s, vector<Node>& tree) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, s, tree);
        build(2 * node + 1, mid + 1, end, s, tree);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
    void update(int node, int start, int end, int idx, char val, vector<Node>& tree) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, val, val};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val, tree);
        else update(2 * node + 1, mid + 1, end, idx, val, tree);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size(), k = queryIndices.size();
        vector<Node> tree(4 * n);
        build(1, 0, n - 1, s, tree);
        
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i], tree);
            ans[i] = tree[1].m;
        }
        return ans;
    }
};