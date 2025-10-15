class Solution {
  public:
    // Function to check if a tree is Sum Tree
    bool isSumTree(Node* root) {
        // Base case: empty tree or leaf node → true
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;

        // Step 1: recursively check subtrees
        if (!isSumTree(root->left) || !isSumTree(root->right))
            return false;

        // Step 2: find sum of left & right subtrees
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        // Step 3: check current node condition
        return (root->data == leftSum + rightSum);
    }

    // helper to calculate sum of subtree
    int sum(Node* root) {
        if (root == NULL) return 0;
        return root->data + sum(root->left) + sum(root->right);
    }
};
