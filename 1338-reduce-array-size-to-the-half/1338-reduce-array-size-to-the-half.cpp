class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto x:arr)
            m[x]++;
        int n=arr.size();
        int size=n;
        int c=0;
        vector<int> v;
        for(auto x:m){
            v.push_back(x.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<v.size();i++){
            if(n-v[i]<=size/2){
                c++;
                break;
            } 
            else{
                n-=v[i];
                c++;
            }
        }
        return c;
    }
};