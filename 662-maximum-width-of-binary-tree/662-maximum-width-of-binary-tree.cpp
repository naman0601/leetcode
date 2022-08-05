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
     typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<ll ,TreeNode*>> q;
        q.push({0,root});
        ll maxi=1;
        map<int,int> m;
        while(!q.empty()){
            ll l,r;
            ll size=q.size();
            for(ll i=0;i<size;i++){
                pair<ll ,TreeNode*> p=q.front();
                q.pop();
                ll hd=p.first;
                if(i==0)
                    l=hd;
                if(i==size-1)
                    r=hd;
                if(p.second->left)
                    q.push({2*hd+1,p.second->left});
                if(p.second->right)
                    q.push({2*hd+2,p.second->right});
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};