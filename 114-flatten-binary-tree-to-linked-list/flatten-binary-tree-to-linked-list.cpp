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
// class Solution {
// public:
//     TreeNode* prev = nullptr;
//     void flatten(TreeNode* root) {
//         if(root == nullptr) return;

//         flatten(root->right);
//         flatten(root->left);

//         root->right = prev;
//         root->left = nullptr;

//         prev = root;
//     }
// };

class Solution {

  public:
    void flatten(TreeNode* root) {
        TreeNode* curNode = root;

        while(curNode != nullptr) {

            if(curNode->left) {
                TreeNode* prev = curNode->left;
                while(prev->right) prev = prev->right;

                prev->right = curNode->right;
                curNode->right = curNode->left;
                curNode->left = nullptr;
            }
            curNode = curNode->right;
        }
    }
};