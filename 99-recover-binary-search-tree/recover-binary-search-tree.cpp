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
    TreeNode *ptr1, *ptr2, *prev;
    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);
        if (prev)
            cout << prev->val << " ";
        cout << root->val << endl;
        if (prev && prev->val >= root->val) {

            if (!ptr1)
                ptr1 = prev;
            ptr2 = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        ptr1 = ptr2 = prev = nullptr;

        inorder(root);

        if (ptr1 && ptr2)
            swap(ptr1->val, ptr2->val);
    }
};