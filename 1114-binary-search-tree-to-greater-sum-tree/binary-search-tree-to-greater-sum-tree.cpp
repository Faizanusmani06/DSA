/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, int &p) {
        if(!root) return;
        solve(root->right, p);
        root->val += p;
        p = root->val;
        solve(root->left , p);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root)
            return nullptr;
        int p = 0;
        solve(root, p);
        return root;
    }
};