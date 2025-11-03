/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        Node* curr = root;
        
        while (curr) {
            if (curr->left == NULL) {
                ans.push_back(curr->data);  // Visit the node
                curr = curr->right;
            } 
            else {
                Node* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                
                if (prev->right == NULL) {
                    ans.push_back(curr->data);  // Visit before making the link (preorder)
                    prev->right = curr;  // Make thread
                    curr = curr->left;
                } 
                else {
                    prev->right = NULL;  // Remove thread
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};
