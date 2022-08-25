class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26];
        memset(map,0,sizeof map);
        for(auto x:ransomNote)
            map[x-'a']++;
        for(auto x:magazine)
            map[x-'a']--;
        for(auto x:ransomNote)
            if(map[x-'a']>0)
                return false;
        return true;
    }
};