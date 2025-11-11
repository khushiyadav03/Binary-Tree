/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // helper function
    int burnTree(Node* root, int target, int &ans) {
        if (!root) return 0;

        if (root->data == target) {
            // found the target node → now calculate time as we go back up
            maxDepth(root, ans); 
            return -1; // signal that fire started here
        }

        int left = burnTree(root->left, target, ans);
        int right = burnTree(root->right, target, ans);

        // If fire started in left subtree
        if (left < 0) {
            ans = max(ans, abs(left) + height(root->right)); // fire spreads to right side
            return left - 1; // propagate fire upward
        }

        // If fire started in right subtree
        if (right < 0) {
            ans = max(ans, abs(right) + height(root->left)); // fire spreads to left side
            return right - 1; // propagate fire upward
        }

        // if no fire found yet, return height of this subtree
        return 1 + max(left, right);
    }

    // get height of subtree
    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // compute maximum depth from burning node
    void maxDepth(Node* root, int &ans) {
        if (!root) return;
        ans = max(ans, 0);
        queue<Node*> q;
        q.push(root);
        int time = 0;

        while (!q.empty()) {
            int n = q.size();
            bool burned = false;
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                burned = true;
            }
            if (burned) time++;
        }
        ans = max(ans, time - 1);
    }

    int minTime(Node* root, int target) {
        int ans = 0;
        burnTree(root, target, ans);
        return ans;
    }
};
