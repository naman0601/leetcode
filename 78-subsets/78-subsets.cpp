class Solution {
public:
    void recur(vector<vector<int>> &res, vector<int> &v, vector<int> &nums,int n){
        if(n==0){
            res.push_back(v);
            return;
        }
        v.push_back(nums[n-1]);
        recur(res,v,nums,n-1);
        v.pop_back();
        recur(res,v,nums,n-1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        recur(res,v,nums,nums.size());
        return res;
    }
};