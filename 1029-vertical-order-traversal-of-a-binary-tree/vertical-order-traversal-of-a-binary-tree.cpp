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
        vector<vector<int>> ans;

        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto it = q.front(); q.pop();

            TreeNode* curNode = it.first;
            int v = it.second.first;
            int h = it.second.second;

            mp[v][h].insert(curNode->val);

            if(curNode->left) {
                q.push({curNode->left, {v-1, h+1}});
            }
            if(curNode->right) {
                q.push({curNode->right, {v+1, h+1}});
            }
        }

        for(auto p : mp) {
            vector<int> temp;
            for(auto q: p.second) {
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};