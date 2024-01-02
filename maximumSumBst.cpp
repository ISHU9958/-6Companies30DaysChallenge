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


class element{
    public:
    int min,max,sum;
};
class Solution {

    int maxi=INT_MIN;
    element f(TreeNode*root){

        if(root==NULL){
            return {INT_MAX,INT_MIN,0};
        }

        auto left=f(root->left);
        auto right=f(root->right);

        if(left.max>=root->val || right.min<=root->val){
            // not a bst
            return {INT_MIN,INT_MAX,0};
        }

        // it is a bst
        maxi=max(maxi,left.sum+right.sum+root->val);

        return {min(left.min,root->val),max(right.max,root->val),left.sum+right.sum+root->val};
    }

    
public:
    int maxSumBST(TreeNode* root) {
        
        f(root);

        return maxi<0 ? 0:maxi;
        

    }
};
