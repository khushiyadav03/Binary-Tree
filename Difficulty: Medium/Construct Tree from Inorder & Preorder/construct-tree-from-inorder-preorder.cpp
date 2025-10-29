/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // helper function to find the position of a target in inorder array
    int find(int* in, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == target) {
                return i;
            }
        }
        return -1;
    }

    // recursive function to build the tree
    Node* Tree(int* in, int* pre, int Instart, int Inend, int& index) {
        if (Instart > Inend) return NULL;

        Node* root = new Node(pre[index]);
        index++; // move to the next preorder element

        if (Instart == Inend) return root; // leaf node

        int pos = find(in, root->data, Instart, Inend);

        root->left = Tree(in, pre, Instart, pos - 1, index);
        root->right = Tree(in, pre, pos + 1, Inend, index);

        return root;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int* in = &inorder[0];
        int* pre = &preorder[0];
        int index = 0; // preorder index tracker

        return Tree(in, pre, 0, n - 1, index);
    }
};
