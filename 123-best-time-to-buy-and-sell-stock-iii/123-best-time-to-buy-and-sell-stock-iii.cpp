class Solution {
public:
    int maxProfit(vector<int>& prices) {
         vector<vector<int>> ahead(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
         for(int ind=prices.size()-1;ind>=0;ind--){
             for(int buy=0;buy<2;buy++){
                 for(int limit=0;limit<3;limit++){
                     if(buy)
                        cur[buy][limit]=max(-prices[ind]+ahead[0][limit],ahead[1][limit]);
                    else{
                        cur[buy][limit]=ahead[0][limit];
                        if(limit>=1){
                            cur[buy][limit]=max(prices[ind]+ahead[1][limit-1],cur[buy][limit]);
                        }
                    }
                 }
                 ahead=cur;
             }
         }
         return ahead[1][2];
    }
};