class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        set<char> s(ransomNote.begin(),ransomNote.end());
        map<char,int> m,n;
        for(char x:ransomNote)
            m[x]++;
        for(char x:magazine)
            n[x]++;
        for(auto x:s)
            if(m[x]>n[x])
                return false;
        return true;
    }
};