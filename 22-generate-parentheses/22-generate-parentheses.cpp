class Solution {
public:
    void parenthesis(int ob,int cb,vector<string> &ans,string s){
        if(ob==0 && cb==0){
            ans.push_back(s);
            return;
        }
        if(ob>0)
            parenthesis(ob-1,cb,ans,s+"(");
        if(cb>ob)
            parenthesis(ob,cb-1,ans,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int ob=n,cb=n;
        parenthesis(ob,cb,ans,"");
        return ans;
    }
};