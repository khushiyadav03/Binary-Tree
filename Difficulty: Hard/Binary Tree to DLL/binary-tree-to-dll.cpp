/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
    void inorder(Node* root, vector<Node*>& nodes){
        if(!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
    
    Node* bToDLL(Node* root) {
        if(!root) return NULL;
        
        vector<Node*> nodes;
        inorder(root, nodes);
        
        for(int i = 0; i<nodes.size(); i++){
            nodes[i]->left = (i == 0) ? NULL : nodes[i-1];
            nodes[i]->right = (i == nodes.size() - 1) ? NULL : nodes[i + 1];
        }
        
        return nodes[0];
    }
};