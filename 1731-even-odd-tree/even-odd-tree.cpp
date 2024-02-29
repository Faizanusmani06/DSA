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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        
        queue<TreeNode*> q;

        bool flag = true; // true->even level (value should be odd and strictly increasing )

        q.push(root);

        while(!q.empty()) {
            int x = q.size();

            int prev = flag ? INT_MIN : INT_MAX;

            for(int i = 0; i < x; i++) {
                TreeNode* Node = q.front();
                q.pop();

                if(flag) {
                    if(Node->val%2 == 0 || Node->val <= prev) return false;
                }else {
                    if(Node->val%2 != 0 || Node->val >= prev) return false;
                }

                if(Node->left) q.push(Node->left);
                if(Node->right) q.push(Node->right);

                prev = Node->val;
            }

            flag = !flag;
        }
        return true;
    }
};