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
    int ans = 0;
    int sum(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            ans += root->left->val;
        }
        sum(root->left);
        sum(root->right);
        return ans;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root);
    }
};