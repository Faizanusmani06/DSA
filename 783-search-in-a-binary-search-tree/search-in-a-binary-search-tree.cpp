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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        TreeNode* left, *right;
        if(root->val == val) return root;
        else if(root->val < val) left = searchBST(root->right, val);
        else right = searchBST(root->left, val);

        if(left != nullptr) return left;
        if(right != nullptr) return right;
        return nullptr;

    }
};