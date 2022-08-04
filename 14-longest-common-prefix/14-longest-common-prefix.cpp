class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans="" ;        
        sort(strs.begin() , strs.end());
        string first = strs[0];
        string second = strs[strs.size() - 1];
        int s1 = 0 , s2 = 0;
        while(first[s1]==second[s2] && s1<first.size() && s2<second.size()){
            ans+=first[s1];
            s1++;s2++;
        }
        return ans;  
    }
};