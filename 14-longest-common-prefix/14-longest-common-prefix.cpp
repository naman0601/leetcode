class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        bool r=true;
        int n=201;
        for(int i=0;i<strs.size();i++)
            if(strs[i].length()<n)
                n=strs[i].length();
        for(int i=0;i<n;i++){
            char a=strs[0][i];
            
                for(int j=1;j<strs.size();j++)
                    if(a!=strs[j][i]){
                        r=false;
                        break;
                    }
           
            if(!r)
                break;
            else
                s+=a;
        }
        return s;
    }
};