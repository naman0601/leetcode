class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string st;
        for(auto x:s){
            if(x==' '){
                if(st!=""){
                    v.push_back(st);
                    st="";
                }
                else
                    continue;
            }
            else
                st+=x;
        }
        if(st!="")
        v.push_back(st);
        reverse(v.begin(),v.end());
        string res;
        for(int i=0;i<v.size();i++){
            res+=v[i];
            res+=" ";
        }
        return res.substr(0,res.size()-1);
    }
};