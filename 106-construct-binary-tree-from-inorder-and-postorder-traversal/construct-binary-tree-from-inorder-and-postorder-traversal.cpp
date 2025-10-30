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
    int find(int* in, int target, int start, int end){
        for(int i = start; i <= end; i++){
            if(in[i] == target) return i;
        }
        return -1;
    }
    
    TreeNode* Tree(int* in, int* post, int instart, int inend, int &index){ 
        if(instart > inend) return NULL;
        
        TreeNode* root = new TreeNode(post[index]);
        int pos = find(in, post[index], instart, inend);
        index--;
        
        root->right = Tree(in, post, pos + 1, inend, index);
        root->left = Tree(in, post, instart, pos - 1, index);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int* in = &inorder[0];
        int* post = &postorder[0];
        int index = n - 1;

        return Tree(in, post, 0, n - 1, index);

    }
};