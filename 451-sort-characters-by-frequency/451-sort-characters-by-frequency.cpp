class Solution {
public:
    string frequencySort(string s) {
       map<char,int> freq;
        for(auto c:s)
            freq[c]++;
       vector<pair<char,int>> v;
       for(auto x:freq){
           v.push_back(x);
       }
       sort(v.begin(),v.end(),[](const pair<char,int> &a,const pair<char,int> &b){
            return a.second>b.second;
       });
        string s1;
        for(auto x:v){
            while(x.second--)
                s1+=x.first;
        }
        return s1;
    }
};