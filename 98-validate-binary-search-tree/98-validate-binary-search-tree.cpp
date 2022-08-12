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
    void inordertraversal(TreeNode* root,vector<int>  &v){
        if(root==NULL)
            return;
        inordertraversal(root->left,v);
        v.push_back(root->val);
        inordertraversal(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inordertraversal(root,v);
        for(int i=0;i<v.size()-1;i++)
            if(v[i]==v[i+1])
                return false;
        vector<int> v1=v;
        sort(v1.begin(),v1.end());
        return v1==v;
    }
};