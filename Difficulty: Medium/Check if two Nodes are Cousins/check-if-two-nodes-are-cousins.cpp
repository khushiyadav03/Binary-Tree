/*Complete the function below
Node is as follows:
struct Node {
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
  bool isCousins(Node* root, int a, int b) {
    if (!root) return false;

    // Stores {level, parent_pointer}
    int l1 = -1, l2 = -1;
    Node* p1 = nullptr;
    Node* p2 = nullptr;

    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        Node* temp = q.front();
        q.pop();

        // Check for children and update levels and parents
        if (temp->left) {
          if (temp->left->data == a) {
            l1 = level + 1;
            p1 = temp;
          }
          if (temp->left->data == b) {
            l2 = level + 1;
            p2 = temp;
          }
          q.push(temp->left);
        }

        if (temp->right) {
          if (temp->right->data == a) {
            l1 = level + 1;
            p1 = temp;
          }
          if (temp->right->data == b) {
            l2 = level + 1;
            p2 = temp;
          }
          q.push(temp->right);
        }
      }

      // Check if both nodes have been found in this or previous levels
      // If found, check the conditions: same level and different parents.
      if (l1 != -1 && l2 != -1) {
        // Cousins are: same level (l1 == l2) AND different parents (p1 != p2)
        return (l1 == l2 && p1 != p2);
      }
      
      // If one is found and the other is not, we can stop the loop early 
      // if we've passed the level of the found one, but it's cleaner to 
      // just check when both are found.

      level++;
    }

    // This case is reached if one or both nodes are not in the tree
    return false;
  }
};