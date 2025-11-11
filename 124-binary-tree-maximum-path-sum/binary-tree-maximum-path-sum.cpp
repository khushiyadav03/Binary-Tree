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
    int maxSum = INT_MIN;

    int solve(TreeNode* root){
        if(!root) return 0;

        // left and right ka max path nikal lo
        int left = solve(root->left);
        int right = solve(root->right);

        // negative sum ignore karo
        left = max(0, left);
        right = max(0, right);

        // curr node ke through max path
        int curr = root->val + left + right;

        maxSum = max(maxSum, curr);

        // parent ko ek hi side ka sum return karo
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};