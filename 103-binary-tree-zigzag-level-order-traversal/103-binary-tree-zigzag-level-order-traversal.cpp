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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        q.push(root);
        TreeNode* curr=root;
        int j=0;
        while(!q.empty()){
            int m=q.size();
            vector<int>y;
            for(int i=0;i<m;i++){
                curr=q.front();
                q.pop();
                y.push_back(curr->val);
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            if(j%2==0){
                v.push_back(y);
            }
            else{
                reverse(y.begin(),y.end());
                v.push_back(y);
            }
            j+=1;
        }
        return v;
    }
};