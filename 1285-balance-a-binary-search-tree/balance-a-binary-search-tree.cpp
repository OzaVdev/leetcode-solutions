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

    // Store BST elements in sorted order
    void inorder(TreeNode* root, vector<int>& arr) {

        if (root == NULL)
            return;

        inorder(root->left, arr);

        arr.push_back(root->val);

        inorder(root->right, arr);
    }


    // Create a balanced BST from sorted array
    TreeNode* buildTree(vector<int>& arr, int left, int right) {

        // No elements remaining
        if (left > right)
            return NULL;

        // Find middle element
        int mid = (left + right) / 2;

        // Make middle element the root
        TreeNode* root = new TreeNode(arr[mid]);

        // Build left subtree
        root->left = buildTree(arr, left, mid - 1);

        // Build right subtree
        root->right = buildTree(arr, mid + 1, right);

        return root;
    }


    TreeNode* balanceBST(TreeNode* root) {

        vector<int> arr;

        // Step 1: Store sorted elements
        inorder(root, arr);

        // Step 2: Build balanced BST
        return buildTree(arr, 0, arr.size() - 1);
    }
};