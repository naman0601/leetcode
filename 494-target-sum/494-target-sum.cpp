class Solution {
public:
    int f(int n,vector<int> &nums,int t){
        if(n==0){
            if(t==0 && nums[0]==0)
                return 2;
            if(t+nums[0]==0)
                return 1;
            if(t-nums[0]==0)
                return 1;
            return 0;
        }
        
        int plus=f(n-1,nums,t-nums[n]);
        int minus=f(n-1,nums,t+nums[n]);
        
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,nums,target);
    }
};