/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int find(int* in, int target, int start, int end){
        for(int i = start; i <= end; i++){
            if(in[i] == target) return i;
        }
        return -1;
    }
    
    Node* Tree(int* in, int* post, int instart, int inend, int &index){ 
        if(instart > inend) return NULL;
        
        Node* root = new Node(post[index]);
        int pos = find(in, post[index], instart, inend);
        index--; // move backward in postorder
        
        root->right = Tree(in, post, pos + 1, inend, index);
        root->left = Tree(in, post, instart, pos - 1, index);
        
        return root;
    }
    
    Node* buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        int* in = &inorder[0];
        int* post = &postorder[0];
        int index = n - 1;  // start from last postorder element

        return Tree(in, post, 0, n - 1, index);  
    }
};
