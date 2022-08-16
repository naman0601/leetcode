class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,false);
    prev[0]=true;
    if(arr[0]<=k)    
       prev[arr[0]]=true;
    for(int i=1;i<n;i++){
        vector<bool> cur(k+1,false);
        cur[0]=true;
        for(int t=1;t<=k;t++){
            bool nottake=prev[t];
            bool take=false;
            if(arr[i]<=t)
                take=prev[t-arr[i]];
            cur[t]=(take||nottake);
        }
        prev=cur;
    }
    return prev[k];
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
            sum+=x;
        if(sum%2==0)
            return subsetSumToK(nums.size(),sum/2,nums);
        else
            return false;
    }
};