class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        while (root) {
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            } 
            else {
                TreeNode* curr = root->left;

                // find the rightmost node in left subtree
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }

                // left subtree not yet traversed
                if (curr->right == NULL) {
                    ans.push_back(root->val);
                    curr->right = root; 
                    root = root->left;
                } 
                else {
                    curr->right = NULL;  
                    root = root->right;
                }
            }
        }

        return ans;
    }
};
