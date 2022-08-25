class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> r;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                        long long sum=arr[i]+arr[j];
                        long long res=(long long)target-sum;
                        int l=j+1;
                        int h=n-1;
                        while(l<h){
                            long long tsum=arr[l]+arr[h];
                            if(res==tsum){
                                vector<int> temp(4,0);
                                temp[0]=arr[i];
                                temp[1]=arr[j];
                                temp[2]=arr[l];
                                temp[3]=arr[h];
                                r.push_back(temp);
                                while(l<h && arr[l]==temp[2]) l++;
                                while(l<h && arr[h]==temp[3]) h--;
                            }
                            else if(res<arr[l]+arr[h]) h--;
                            else l++;
                        }
                      while(j+1<n && arr[j]==arr[j+1]) j++;
                    }
                while(i+1<n-1 && arr[i]==arr[i+1]) i++;
            }
        return r;
    }
};