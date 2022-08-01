class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        for(auto x:words2){
            vector<int> freq1(26,0);
            for(auto y:x){
                freq1[y-'a']++;
                freq[y-'a']=max(freq[y-'a'],freq1[y-'a']);
            }
        }
        vector<string> v;
        for(auto x:words1){
            vector<int> freq2(26,0);
            for(auto y:x){
                freq2[y-'a']++;
            }
            bool res=true;
            for(int i=0;i<26;i++)
                if(freq[i]>freq2[i]){
                    res=false;
                    break;
                }
            if(res)
                v.push_back(x);
        }
        return v;
    }
};