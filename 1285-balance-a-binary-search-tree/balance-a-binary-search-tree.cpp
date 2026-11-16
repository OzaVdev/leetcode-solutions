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
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return arrToBST(0, arr.size()-1);
    }
private:
    vector<TreeNode*> arr;
    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        inOrder(root->left);
        arr.push_back(root);
        inOrder(root->right);
    }
    TreeNode* arrToBST(int start, int end){
        if(start>end) return nullptr;
        int mid = (start+end)/2;
        TreeNode* root = arr[mid];
        root->left = arrToBST(start, mid-1);
        root->right = arrToBST(mid+1, end);
        return root;
    }
};