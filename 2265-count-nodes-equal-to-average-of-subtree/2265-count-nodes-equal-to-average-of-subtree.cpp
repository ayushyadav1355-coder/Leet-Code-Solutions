#include <utility>

using namespace std;

class Solution {
    int matching_nodes = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int current_sum = root->val + left.first + right.first;
        int current_count = 1 + left.second + right.second;

        if (root->val == current_sum / current_count) {
            matching_nodes++;
        }

        return {current_sum, current_count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matching_nodes = 0;
        dfs(root);
        return matching_nodes;
    }
};