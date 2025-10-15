/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isleaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }

    void addLeftBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->left;
        while (curr) {
            if (!isleaf(curr)) ans.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& ans) {
        vector<int> temp;
        Node* curr = root->right;
        while (curr) {
            if (!isleaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    void addLeaf(Node* root, vector<int>& ans) {
        if (isleaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if (root->left) addLeaf(root->left, ans);
        if (root->right) addLeaf(root->right, ans);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        if (!isleaf(root)) ans.push_back(root->data);

        addLeftBoundary(root, ans);
        addLeaf(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};
