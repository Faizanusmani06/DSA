/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, int ans, int &depth) {
        if(!root) return;
        if(!root->left && !root->right) {
            depth = min(depth, ans);
            return;
        }

        solve(root->left, ans+1, depth);
        solve(root->right, ans+1, depth);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = INT_MAX;
        solve(root, 1, depth);
        return depth;
        
    }
};