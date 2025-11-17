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
    long long maxwidth = 0;
    unordered_map<int, long long> leftmost; // store karega 1stindex at each level

    void dfs(TreeNode* node, int level, long long idx){
        if(!node) return;

        if(!leftmost.count(level)) leftmost[level] = idx;

        long long currwidth = idx - leftmost[level] + 1;
        maxwidth = max(maxwidth, currwidth);

        // normalize index to prevent overflow
        unsigned long long newIdx = idx - leftmost[level];

        // dfs left(2 * idx)
        dfs(node->left, level + 1, newIdx * 2);

        // dfs right(2 * idx + 1)
        dfs(node->right, level + 1,newIdx * 2 + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return (int) maxwidth;
    }
};