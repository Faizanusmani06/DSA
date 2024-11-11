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
    void inorder(TreeNode* root, int &val , int &cnt, int k) {
        if(!root || cnt >= k) return;

        inorder(root->left, val, cnt, k);
        cnt++;

        if(cnt == k) {
            val = root->val;
            return;
        }

        inorder(root->right, val , cnt, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = INT_MAX;
        int cnt = 0;

        inorder(root, val , cnt, k);

        return val;
    }
};