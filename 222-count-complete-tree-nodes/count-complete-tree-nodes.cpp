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
    int maxV = 0;
    int calDepth(TreeNode* n) {
        if(n==nullptr) {
            return 0;
        }
        int left = 1 + calDepth(n->left);
        return left;
    }
    void calculate(TreeNode*node, int val, TreeNode* parent) {
        if(node==nullptr) {
            return;
        }
        maxV = max(maxV, val);
        if(node->right != nullptr && parent != nullptr) {
            parent->left = nullptr;
        }
        int l = calDepth(node->left);
        int r = calDepth(node->right);
        if(l<=r) {
            calculate(node->right,(val*2)+1, node);
        } else {
            calculate(node->left,(val*2), node);
        }
    }
    int countNodes(TreeNode* root) {
        maxV = 0;
        calculate(root, 1, nullptr);
        return maxV;
    }
};