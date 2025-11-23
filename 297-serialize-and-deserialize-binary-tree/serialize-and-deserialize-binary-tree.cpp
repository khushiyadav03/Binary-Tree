class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "N,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* buildTree(vector<string>& nodes, int& idx) {
        if (idx >= nodes.size() || nodes[idx] == "N") {
            idx++;
            return nullptr;
        }

        // create node from CURRENT token
        TreeNode* root = new TreeNode(stoi(nodes[idx]));
        idx++; // move to next token

        root->left = buildTree(nodes, idx);
        root->right = buildTree(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string curr = "";

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }

        int idx = 0;
        return buildTree(nodes, idx);
    }
};
