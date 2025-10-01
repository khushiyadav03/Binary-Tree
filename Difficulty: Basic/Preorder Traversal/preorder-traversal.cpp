/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preorder(Node* root) {
        vector<int> ans;   // vector create karo
        preorderUtil(root, ans);
        return ans;        // vector return karo
    }

    void preorderUtil(Node* root, vector<int>& ans) {
        if(root == NULL) return;   // base case

        ans.push_back(root->data);    // root pe visit
        preorderUtil(root->left, ans);   // left subtree
        preorderUtil(root->right, ans);  // right subtree
    }
};