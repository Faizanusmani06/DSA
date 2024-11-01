/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void map_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == nullptr)
            return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if (currNode->left) {
                mp[currNode->left] = currNode;
                q.push(currNode->left);
            }
            if (currNode->right) {
                mp[currNode->right] = currNode;
                q.push(currNode->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr)
            return {};
        unordered_map<TreeNode*, TreeNode*> parent_track;

        map_parent(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        int distance = 0;
        visited[target] = true;

        queue<TreeNode*> q;
        q.push(target);

        while (!q.empty()) {

            if (distance++ == k)
                break;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if (currNode->left && !visited[currNode->left]) {
                    visited[currNode->left] = true;
                    q.push(currNode->left);
                }
                if (currNode->right && !visited[currNode->right]) {
                    visited[currNode->right] = true;
                    q.push(currNode->right);
                }
                if (parent_track[currNode] &&
                    !visited[parent_track[currNode]]) {
                    visited[parent_track[currNode]] = true;
                    q.push(parent_track[currNode]);
                }
            }
        }

        vector<int> result;

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            result.push_back(currNode->val);
        }

        return result;
    }
};