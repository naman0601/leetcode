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
   bool bst(TreeNode* root,long long lb,long long ub){
       if(root==NULL)
           return true;
       if(root->val>lb && root->val<ub){
           return bst(root->left,lb,root->val) && bst(root->right,root->val,ub);
       }
       return false;
   }
    bool isValidBST(TreeNode* root) {
        return bst(root,LLONG_MIN, LLONG_MAX);
    }
};