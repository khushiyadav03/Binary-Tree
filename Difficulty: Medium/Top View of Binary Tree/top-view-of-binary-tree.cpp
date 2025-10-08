class Solution {
  public:
  
  void Find(Node* root, int pos, int& l, int& r) {
      if (!root) return;
      l = min(l, pos);
      r = max(r, pos);
      
      Find(root->left, pos - 1, l, r);
      Find(root->right, pos + 1, l, r);
  }
  
  vector<int> topView(Node *root) {
      if (!root) return {};
      
      int l = 0, r = 0;
      Find(root, 0, l, r);
      
      vector<int> ans(r - l + 1);
      vector<bool> filled(r - l + 1, false);
      
      queue<pair<Node*, int>> q;
      q.push({root, -l}); // offset to make index 0-based
      
      while (!q.empty()) {
          auto [temp, pos] = q.front();
          q.pop();
          
          if (!filled[pos]) {
              filled[pos] = true;
              ans[pos] = temp->data;
          }
          
          if (temp->left) q.push({temp->left, pos - 1});
          if (temp->right) q.push({temp->right, pos + 1});
      }
      
      return ans;
  }
};
