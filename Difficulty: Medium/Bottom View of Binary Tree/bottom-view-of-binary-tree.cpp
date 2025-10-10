/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
    vector<int> ans;
    if (!root) return ans;

    map<int, int> mp;  // HD → node->data
    queue<pair<Node*, int>> q; // node + HD
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        mp[hd] = node->data; // overwrite for bottommost

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto &it : mp) ans.push_back(it.second);
    return ans;
}

};