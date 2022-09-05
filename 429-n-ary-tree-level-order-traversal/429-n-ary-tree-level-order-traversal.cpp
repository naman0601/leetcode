/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        queue<Node*> q;
        if(!root)
            return v;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> v1;
            while(size--){
                Node* t=q.front();
                q.pop();
                v1.push_back(t->val);
                for (auto u : t->children)
                     q.push(u);
            }
            v.push_back(v1);
        }
        return v;
    }
};