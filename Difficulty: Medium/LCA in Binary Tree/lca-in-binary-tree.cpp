class Solution {
public:
    Node* lca(Node* root, int p, int q) {
        if (root == NULL) 
            return NULL;

        // If root itself is p or q
        if (root->data == p || root->data == q) 
            return root;

        Node* left = lca(root->left, p, q);
        Node* right = lca(root->right, p, q);

        // If one node is found in left and the other in right
        if (left != NULL && right != NULL) 
            return root;

        // Otherwise, return the non-null side
        return (left != NULL) ? left : right;
    }
};
