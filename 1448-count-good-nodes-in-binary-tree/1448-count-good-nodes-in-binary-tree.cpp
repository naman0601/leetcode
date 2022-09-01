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
    int count=0;
    void f(TreeNode* root,int res){
        if(root==NULL) return;
        if(root->val>=res){
            count++;
            res=root->val;
        }
        f(root->left,res);
        f(root->right,res);
    }
    int goodNodes(TreeNode* root) {
        f(root,INT_MIN);
        return count;
    }
};