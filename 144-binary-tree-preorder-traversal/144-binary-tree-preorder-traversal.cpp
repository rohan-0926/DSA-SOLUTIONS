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
    vector<int> preorderTraversal(TreeNode* root) {
        /* itervative */
        vector<int>v;
        stack<TreeNode*>s;
        if(root==NULL){
            return v;
        }
        TreeNode* curr = root;
        s.push(curr);
        while(!s.empty()){
            curr=s.top();
            s.pop();
            v.push_back(curr->val);
            if(curr->right!=NULL){
                s.push(curr->right);
            }
            if(curr->left!=NULL){
                s.push(curr->left);
            }
        }
        return v;
    }
};