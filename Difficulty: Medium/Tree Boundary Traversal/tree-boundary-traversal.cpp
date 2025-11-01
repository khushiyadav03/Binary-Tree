/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void LeftSub(Node* root, vector<int>& ans) {
        if (!root || (!root->left && !root->right)) return;
        
        ans.push_back(root->data);
        if (root->left)
            LeftSub(root->left, ans);
        else
            LeftSub(root->right, ans);
    }
    
    void Leaf(Node* root, vector<int>& ans) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        
        Leaf(root->left, ans);
        Leaf(root->right, ans);
    }
    
    void RightSub(Node* root, vector<int>& ans) {
        if (!root || (!root->left && !root->right)) return;
        
        if (root->right)
            RightSub(root->right, ans);
        else
            RightSub(root->left, ans);
        
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;
        
        ans.push_back(root->data);
        
        LeftSub(root->left, ans);
        Leaf(root->left, ans);
        Leaf(root->right, ans);
        RightSub(root->right, ans);
        
        return ans;
    }
};
