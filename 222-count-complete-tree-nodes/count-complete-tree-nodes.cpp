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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
            
        int lh = findHeightofLeft(root);
        int rh = findheightofRight(root);

        if(lh == rh)
            return (1<<lh)-1;
        
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
    int findHeightofLeft(TreeNode* node){
        int lheight = 0;
        while(node){
            lheight++;
            node=node->left;
        }
        return lheight;
    }
    int findheightofRight(TreeNode* node){
        int rheight=0;
        while(node){
            rheight++;
            node=node->right;
        }
        return rheight;
    }
};