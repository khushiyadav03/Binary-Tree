// User function Template for C++

class Solution {
  public:
  
    void dfs(Node* root, int level, vector<int>& ans){
        if(root == NULL) return;
        
        if(level == ans.size()){
            ans.push_back(root->data);
        } else {
            ans[level] = max(ans[level], root->data);
        } 
        
        dfs(root->right, level + 1, ans);
        dfs(root->left, level + 1, ans);
    }
    
    vector<int> largestValues(Node* root) {
        // code here
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};