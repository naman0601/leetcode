class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int n=s.length();
        int i;
        for(i=n-1;i>0;i--){
            if(m[s[i]]>m[s[i-1]]){
                sum+=m[s[i]]-m[s[i-1]];
                i--;
            }
            else
                sum+=m[s[i]];
        }
        if(i==0)
            sum+=m[s[0]];
        return sum;
    }
};