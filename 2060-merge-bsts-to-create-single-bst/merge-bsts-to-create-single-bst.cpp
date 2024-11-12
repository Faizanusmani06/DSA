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
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode, unordered_map<int, TreeNode*> &mp) {
        if(root == nullptr) return true;
        if(minNode && root->val <= minNode->val) return false;
        if(maxNode && root->val >= maxNode->val) return false;
        if(!root->left && !root->right && mp.count(root->val)) {
            const int val = root->val;
            root->left = mp[val]->left;
            root->right = mp[val]->right;
            mp.erase(val);
        }

        return isValid(root->left, minNode, root, mp) && isValid(root->right, root, maxNode, mp);
    }
   
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp; // val -> root;
        unordered_map<int, int> freq; 

        for(auto tree: trees) {
            mp[tree->val] = tree;
            ++freq[tree->val];

            if(tree->left) ++freq[tree->left->val];
            if(tree->right) ++freq[tree->right->val];
        }

        for(auto tree: trees) {
            if(freq[tree->val] == 1) {
                if(isValid(tree, nullptr, nullptr, mp) && mp.size() <= 1) return tree;
                return nullptr;
            }
        }

        return nullptr;

    }
};