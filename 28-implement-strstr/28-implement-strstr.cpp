class Solution {
public:
    vector<int> prefix(string pat){
            int n=pat.size();
            vector<int> t(n,0);
            for(int i=1;i<n;i++){
                int j=t[i-1];
                while(j>0 and pat[i]!=pat[j]){
                    j=t[j-1];
                }
                if(pat[i]==pat[j])
                   j++;
                t[i]=j;   
            }
            return t;
        }
    int strStr(string txt, string pat) {
        vector<int> lps=prefix(pat);
            int i=0,j=0;
            int pos=-1;
            int n=txt.size();
            while(i<n){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                }
                else{
                    if(j!=0)
                       j=lps[j-1];
                    else
                       i++;
                }
                if(j==pat.size()){
                    pos=i-j;
                    break;
                }
            }
            return pos;
    }
};