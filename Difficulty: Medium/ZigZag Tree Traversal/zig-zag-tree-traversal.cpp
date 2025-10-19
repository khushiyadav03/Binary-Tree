class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        if (!root) return {};

        stack<Node*> s1; // L to R
        stack<Node*> s2; // R to L
        vector<int> ans;

        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            
            // Left to Right
            while (!s1.empty()) {
                Node* temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);

                // Push order: left first, then right
                if (temp->left) s2.push(temp->left);
                if (temp->right) s2.push(temp->right);
            }

            // Right to Left
            while (!s2.empty()) {
                Node* temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);

                // Push order: right first, then left
                if (temp->right) s1.push(temp->right);
                if (temp->left) s1.push(temp->left);
            }
        }

        return ans;
    }
};
