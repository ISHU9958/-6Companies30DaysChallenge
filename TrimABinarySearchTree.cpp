
class Solution {

    TreeNode*f(TreeNode*root,int low,int high){

        if(root==NULL) return NULL;

        TreeNode*left=f(root->left,low,high);
        TreeNode*right=f(root->right,low,high);

        if(low<=root->val && root->val<=high){
            root->left=left;
            root->right=right;
            return root;
        }

        if(left==NULL && right==NULL) return NULL;
        if(left==NULL) return right;
        return left;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return f(root,low,high);
    }
};
