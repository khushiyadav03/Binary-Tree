// User function Template for C++

class Solution {
  public:
    void preorder(Node* root, vector<Node*>& nodes){
        if(!root) return;
        
        nodes.push_back(root);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
    
    void flatten(Node *root) {
        // code here
        if(!root) return;
        
        vector<Node*> nodes;
        preorder(root, nodes);
        
        for(int i = 0; i<nodes.size() - 1; i++){
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i+1];
        }
        
        nodes.back()->left = NULL;
        nodes.back()->right = NULL;
    }
};