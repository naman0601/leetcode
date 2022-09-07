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
    void func(TreeNode* root,string &s){
        if(root==NULL) return;
        s+=to_string(root->val);
        if(root->left || root->right)
          s+="(";
        func(root->left,s);
        if(root->left || root->right)
          s+=")";
        if(root->right)
            s+='(';
        func(root->right,s);
        if(root->right)
            s+=')';
    }
    string tree2str(TreeNode* root) {
        string s;
        func(root,s);
        return s;
    }
};