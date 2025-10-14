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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> S1; // L to R
        stack<TreeNode*> S2; // R to L
        vector<vector<int>> ans;

        if (!root) return ans; // null check added
        S1.push(root);

        while (!S1.empty() || !S2.empty()) {

            // process stack S1 (L → R)
            if (!S1.empty()) {
                vector<int> level; // store current level
                while (!S1.empty()) {
                    TreeNode* temp = S1.top();
                    S1.pop();
                    level.push_back(temp->val); // corrected from ans.push

                    // order matters for zigzag
                    if (temp->left) S2.push(temp->left);
                    if (temp->right) S2.push(temp->right);
                }
                ans.push_back(level);
            }

            // process stack S2 (R → L)
            else {
                vector<int> level;
                while (!S2.empty()) {
                    TreeNode* temp = S2.top();
                    S2.pop();
                    level.push_back(temp->val);

                    // reverse order for this level
                    if (temp->right) S1.push(temp->right);
                    if (temp->left) S1.push(temp->left);
                }
                ans.push_back(level);
            }
        }
        return ans;
    }
};
