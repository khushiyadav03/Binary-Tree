/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  Code here
        vector<int> ans;
        
        if (root == nullptr) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            ans.push_back(q.front()->data);
            
            while(n--){
                Node* temp = q.front();
                q.pop();
                
                if(temp->right) q.push(temp->right);
                
                if(temp->left) q.push(temp->left);
            }
        }
        
        return ans;
    }
};