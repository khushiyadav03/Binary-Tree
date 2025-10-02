class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();            // current level size
            vector<int> level;              // store nodes of this level
            
            for(int i = 0; i < size; i++){
                Node* temp = q.front();
                q.pop();
                
                level.push_back(temp->data);
                
                // left child
                if(temp->left) 
                    q.push(temp->left);
                
                // right child
                if(temp->right) 
                    q.push(temp->right);
            }
            
            ans.push_back(level); // store one complete level
        }
        
        return ans;
    }
};
