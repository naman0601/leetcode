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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)
          return v;
        queue<TreeNode*> q;
        q.push(root);
        map<int,int> m;
        while(!q.empty()){
            vector<int> v1;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* p=q.front();
                q.pop();
                v1.push_back(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            v.push_back(v1);
        }
        return v;   
    }
};