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
    void preOrder(TreeNode* root, vector<int>& preorder) {
        if (root == nullptr)
            return;
        preOrder(root->left, preorder);
        preorder.push_back(root->val);

        preOrder(root->right, preorder);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> preorder;

        preOrder(root, preorder);

        int diff = INT_MAX;

        for (int i = 0; i < preorder.size() - 1; i++) {

            diff = min(diff, abs(preorder[i] - preorder[i + 1]));
        }

        return diff;
    }
};