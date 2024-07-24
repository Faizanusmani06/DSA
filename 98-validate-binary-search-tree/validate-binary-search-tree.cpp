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
private:
    bool isValid(TreeNode* root, long long minVal, long long maxVal) {
        if(!root) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int x = -1e12, y = 1e12;

        return isValid(root, x, y);
        
    }
};