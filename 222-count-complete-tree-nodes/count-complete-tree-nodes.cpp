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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<TreeNode* > q;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            ans += n;

            for(int i = 0; i < n; i++) {
                TreeNode* curNode = q.front(); q.pop();
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
        }
        return ans;
    }
};