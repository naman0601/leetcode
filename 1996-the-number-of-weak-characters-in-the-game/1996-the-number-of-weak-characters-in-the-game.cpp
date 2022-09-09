class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]!=b[0])
                return a[0]>b[0];
            return a[1]<b[1];
        });
        int count=0;
        int maxtillnow=INT_MIN;
        for(int i=0;i<properties.size();i++){
            if(maxtillnow>properties[i][1]) 
                count++;
            else 
                maxtillnow=properties[i][1];
        }
        return count;
    }
};