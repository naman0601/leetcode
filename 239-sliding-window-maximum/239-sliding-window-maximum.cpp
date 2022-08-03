class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k) //to pop the index of value which is not in the window 
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]) //to pop the index of value which are less
                dq.pop_back();         //than the max value of that window
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};