class Solution {
public:
    int solve(vector<vector<int>>& matrix, int mid){
        int count = 0, n = matrix.size(), i = n-1, j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] > mid) i--;
            else{
                count += (i+1);
                j++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), low = matrix[0][0], high = matrix[n-1][n-1];
        while(low < high){
            int mid = low + (high-low)/2;
            int posi = solve(matrix, mid);
            if(posi < k) low = mid+1;
            else high = mid;
        }
        return low;
    }
};