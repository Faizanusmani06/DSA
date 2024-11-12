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
private:
    void mapping(TreeNode* root, map<int, int>& mp) {
        if (root == nullptr)
            return;
        mapping(root->left, mp);
        mp[root->val]++;
        mapping(root->right, mp);
    }
    bool find(TreeNode* root, map<int, int>& mp, int k, bool flag) {
        if (!root)
            return false;

        if(!flag && 2*root->val == k) return false;
        else if(flag && 2*root->val == k) flag = true;
        else if (mp.find(k - root->val) != mp.end())
            return true;

        return find(root->left, mp, k, flag) || find(root->right, mp, k, flag);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if(!root->left && !root->right) {
            return false;
        }
        map<int, int> mp;

        mapping(root, mp);
        bool flag = 2*root->val == k;
        return find(root, mp, k, flag);
    }
};