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
    int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int h=height(root->left);
        int j=height(root->right);
        if(abs(h-j)>1){
            return -1;
        }
        if(h==-1 || j==-1){
            return -1;
        }
        
        return 1+max(h,j);
    }
    bool isBalanced(TreeNode* root) {
        if(height(root)==-1){
            return false;
        }
        return true;
    }
};