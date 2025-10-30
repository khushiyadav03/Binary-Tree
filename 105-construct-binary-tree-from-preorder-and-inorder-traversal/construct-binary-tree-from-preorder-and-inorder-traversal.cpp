/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // pass index by reference so it updates across recursive calls
    TreeNode* Tree(int* in, int* pre, int instart, int inend, int &index){
        if(instart > inend) return NULL;

        // create root from preorder[index]
        TreeNode* root = new TreeNode(pre[index]);

        // find its position in inorder
        int pos = find(in, pre[index], instart, inend);
        index++; // move to next preorder element

        // build subtrees
        root->left = Tree(in, pre, instart, pos - 1, index);
        root->right = Tree(in, pre, pos + 1, inend, index);

        return root;
    }

    int find(int* in, int target, int start, int end){
        for(int i = start; i <= end; i++){
            if(in[i] == target) return i;
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int* in = &inorder[0];
        int* pre = &preorder[0];
        int index = 0;

        return Tree(in, pre, 0, n - 1, index);
    }
};
