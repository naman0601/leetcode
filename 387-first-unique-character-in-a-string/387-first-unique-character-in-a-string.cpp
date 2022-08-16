class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        int i;
        for(i=0;i<s.length();i++)
            if(m[s[i]]==1)
                break;
        if(i<s.length())
            return i;
        else 
            return -1;
    }
};