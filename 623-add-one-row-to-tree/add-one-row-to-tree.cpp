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
    TreeNode* add(TreeNode* root, int val, int depth, int curr) {
        if(!root) return nullptr;

        if(curr == depth - 1) {
            TreeNode* leftSubTree = root->left;
            TreeNode* rightSubTree = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftSubTree;
            root->right->right = rightSubTree;

            return root;
        }

        add(root->left, val, depth, curr + 1);
        add(root->right, val, depth, curr + 1);

        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        return add(root, val, depth, 1);
    }
};