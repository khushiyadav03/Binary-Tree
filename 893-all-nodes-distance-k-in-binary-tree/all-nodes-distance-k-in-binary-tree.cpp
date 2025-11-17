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
public:
    vector<int> ans;

    void addDown(TreeNode* root, int dist){
        if(!root || dist < 0) return;
        if(dist == 0){
            ans.push_back(root->val);
            return;
        }

        addDown(root->left, dist -1);
        addDown(root->right, dist -1);
    }

    int dfs(TreeNode* root, TreeNode* target, int k){
        if(!root) return -1;

        // found target->add downwards nodes
        if(root == target) {
            addDown(root, k);
            return 0;
        }

        // left subtree check
        int left = dfs(root->left, target, k);
        if(left != -1){
            // root is at distance left + 1 from target
            if(left + 1 == k) ans.push_back(root->val);
            else addDown(root->right, k - left - 2);

            return left + 1;
        }

        // right subtree check
        int right = dfs(root->right, target, k);
        if(right != -1){
            if(right + 1 == k) ans.push_back(root->val);
            else addDown(root->left, k - right - 2);

            return right + 1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return ans;
    }
};