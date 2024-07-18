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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;

        queue<TreeNode* >q;

        q.push(root);

        bool order = true;
        while(!q.empty()) {
            
            int size = q.size();
            vector<int> level(size, -1);

            for(int i = 0; i < size; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                if(order ) level[i] = curNode->val;
                else level[size-1-i] = curNode->val;

                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }

            order = !order;
            ans.push_back(level);
        }
        return ans;
    }
};