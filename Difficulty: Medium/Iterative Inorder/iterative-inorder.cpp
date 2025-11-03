class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        if (!root) return ans; // handle empty tree
        
        while (root) {
            if (!root->left) {
                ans.push_back(root->data);
                root = root->right;
            } else {
                Node* curr = root->left;

                // find rightmost node in left subtree
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }

                // if thread not created, make one
                if (curr->right == NULL) {
                    curr->right = root;  
                    root = root->left;
                }
                // if thread already exists, remove it
                else {
                    curr->right = NULL;  
                    ans.push_back(root->data);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};
