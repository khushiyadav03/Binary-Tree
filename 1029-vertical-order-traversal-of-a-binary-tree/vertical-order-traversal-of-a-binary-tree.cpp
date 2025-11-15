class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // col -> row -> sorted values
        map<int, map<int, multiset<int>>> nodes;

        // BFS queue: {node, {row, col}}
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;

            // Insert node into map structure
            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});

            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        // Build final answer
        vector<vector<int>> ans;

        for (auto &colPair : nodes) {
            vector<int> colNodes;
            for (auto &rowPair : colPair.second) {
                colNodes.insert(
                    colNodes.end(),
                    rowPair.second.begin(),
                    rowPair.second.end()
                );
            }
            ans.push_back(colNodes);
        }

        return ans;
    }
};
