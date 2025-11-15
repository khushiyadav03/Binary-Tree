class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes; 
        // stores {col, row, val}

        dfs(root, 0, 0, nodes);

        // Sort by: col, then row, then value
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        int prevCol = INT_MIN;

        for(auto &[col, row, val] : nodes) {
            if(col != prevCol){
                ans.push_back({});
                prevCol = col;
            }
            ans.back().push_back(val);
        }

        return ans;
    }

    void dfs(TreeNode* node, int row, int col, vector<tuple<int,int,int>>& nodes) {
        if(!node) return;

        nodes.push_back({col, row, node->val});

        dfs(node->left, row + 1, col - 1, nodes);
        dfs(node->right, row + 1, col + 1, nodes);
    }
};
