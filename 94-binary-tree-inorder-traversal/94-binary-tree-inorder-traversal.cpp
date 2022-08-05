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
    void traversal(vector<int> &v,TreeNode* root){
        if(root==NULL)
            return;
        traversal(v,root->left);
        v.push_back(root->val);
        traversal(v,root->right);
    } 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traversal(v,root);
        return v;
    }
};