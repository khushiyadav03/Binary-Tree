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
    void find(Node* root, int pos, int &l, int &r){
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalOrder(Node *root) {
        if (!root) return {};

        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<int>> Positive(r + 1);
        vector<vector<int>> Negative(abs(l) + 1);

        queue<Node*> q;
        queue<int> index;
        q.push(root);
        index.push(0);

        while (!q.empty()) {
            Node* temp = q.front(); q.pop();
            int pos = index.front(); index.pop();

            if (pos >= 0) Positive[pos].push_back(temp->data);
            else Negative[abs(pos)].push_back(temp->data);

            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }

            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        vector<vector<int>> ans;

        // merge Negative (in reverse)
        for (int i = Negative.size() - 1; i > 0; i--) {
            if (!Negative[i].empty())
                ans.push_back(Negative[i]);
        }

        // merge Positive (normal order)
        for (int i = 0; i < Positive.size(); i++) {
            if (!Positive[i].empty())
                ans.push_back(Positive[i]);
        }

        return ans;
    }
};
