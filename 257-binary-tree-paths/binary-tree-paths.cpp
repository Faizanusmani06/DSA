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
    void solve(TreeNode* root, string path, vector<string> &ans) {
        if(!root) return;

        if(!root->left && !root->right) {
            path = path + "->" + to_string(root->val);
            ans.push_back(path);
        }
        solve(root->left, path + "->" + to_string(root->val), ans);
        solve(root->right, path + "->" + to_string(root->val), ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {""};
        vector<string> ans;
        string path = to_string(root->val);
        if(!root->left && !root->right) {
            ans.push_back(path);
            return ans;
        }
        solve(root->left, path, ans);
        solve(root->right, path, ans);
        return ans;
    }
};