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
    TreeNode* buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inMap) {
        if(postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inLeft = inMap[root->val] - inStart;

        root->left = buildTree(inorder, inStart, inStart + inLeft-1, postorder, postStart, postStart + inLeft - 1, inMap);
        root->right = buildTree(inorder, inStart + inLeft + 1, inEnd, postorder, postStart + inLeft, postEnd - 1, inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return nullptr;
        
        map<int, int> inMap;

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);

        return root;
    }
};