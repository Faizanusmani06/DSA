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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {{}};
        // map: vertical -> map: level -> set of unique nodes in sorted order(multiset)
        map<int, map<int, multiset<int>>> mp;

        // queue(node-> (vertical, level));
        queue<pair<TreeNode*, pair<int, int>>>q;

        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* curNode = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mp[x][y].insert(curNode->val);

            if(curNode->left) q.push({curNode->left, {x-1, y+1}});
            if(curNode->right) q.push({curNode->right, {x+1, y+1}});
        }

         vector<vector<int>> ans;

         for(auto p: mp) {
            vector<int> col;
            for(auto v: p.second) {
                col.insert(col.end(), v.second.begin(), v.second.end());
            }
            ans.push_back(col);
         }

         return ans;
    }
};