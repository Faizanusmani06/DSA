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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        int ans = 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();
            int minInd = q.front().second;
            int first, last;    
            for(int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();

                int cur_ind = it.second - minInd;

                if(i == 0) first = cur_ind;
                if(i == size-1) last = cur_ind;

                if(it.first->left) q.push({it.first->left, (long long)2*cur_ind + 1});
                if(it.first->right) q.push({it.first->right, (long long )2*cur_ind + 2});
            }
            
            ans = max(ans, last - first + 1);
            
        }

        return ans;
    }
};